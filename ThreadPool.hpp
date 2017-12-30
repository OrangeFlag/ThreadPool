//
// Created by yorick on 16.12.17.
//

#ifndef LAB5_THREADPOOL_H
#define LAB5_THREADPOOL_H

#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>


//exception-safe
//thread-safe


//think about destructors 
namespace ThreadStates
{
enum States {
    work,
    pause,
    have_stopped,
    are_stopping
};
};

template<typename Func>
class Task;

template<typename Ret, typename... Arguments>
class Task<Ret(Arguments...)> {
    std::function<Ret(Arguments...)> &func;
    bool complete;
    Ret result;
public:
    Task(std::function<Ret(Arguments...)> &_func) : func(_func), complete(false) {};
    ~Task(){};

    bool isComplete() const {
        return complete;
    };

    Ret getResult() const {
        if (!complete)
            throw std::runtime_error("Function not complete");
        return result;
    };

    void call() {
        result = func();
        complete = true;
    };
};

template<typename... Arguments>
class Task<void(Arguments...)> {
    std::function<void(Arguments...)> &func;
    bool complete;
public:
    Task(std::function<void(Arguments...)> &_func) : func(_func), complete(false) {};
    ~Task(){};

    bool isComplete() const {
        return complete;
    };

    void call() {
        func();
        complete = true;
    };
};



template<typename Func>
class Thread {
private:
    std::queue<Task<Func> *> waitingBegan;
    std::queue<Task<Func> *> waitingForPickUp;
    std::mutex mtx;
    mutable std::condition_variable cv;
    mutable std::atomic<bool> pause_;
    mutable std::atomic<bool> stop_;
    mutable bool complete_;
    std::thread th;


public:
    Thread() : th(&Thread::main, this), pause_(false), stop_(false), complete_(false)
    {
        th.detach();
    };

    void main() {
        while (true) {
            {
                std::unique_lock<std::mutex> ulk(mtx);
                cv.wait(ulk, [&]() { return !(pause_ || waitingBegan.empty()); });

                waitingBegan.front()->call();
                waitingForPickUp.push(waitingBegan.front());
                waitingBegan.pop();
            }

            if (stop_)
            {
                complete_ = true;
                break;
            }
        };

    };

    void push(Task<Func> *t) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            waitingBegan.push(t);
        }
        cv.notify_one();
    };


    unsigned long countWaitingBeganTasks() const {
        return waitingBegan.size();
    };

    unsigned long countWaitingPickUpTasks() const {
        return waitingForPickUp.size();
    };

    void pause() const noexcept {
        pause_ = true;
    };

    void resume() const noexcept {
        pause_ = false;
        cv.notify_one();
    };

    void stop() const noexcept {
        stop_ = true;
        resume();
    };

    ThreadStates::States getStatus() const noexcept {
        if (stop_)
            if (complete_)
                return ThreadStates::States::have_stopped;
            else
                return ThreadStates::States::are_stopping;
        else if (pause_)
            return ThreadStates::States::pause;
        else
            return ThreadStates::States::work;
    };


};


template<typename Func>
class ThreadPool {
private:
    int8_t countThread;
    Thread<Func> *Threads;

public:
    explicit ThreadPool() : countThread((int8_t)std::thread::hardware_concurrency()) {
        Threads = new Thread<Func>[countThread];
    };

    explicit ThreadPool(int8_t countThread_) : countThread(countThread_) {
        Threads = new Thread<Func>[countThread];
    };

    ~ThreadPool()
    {
        delete[] Threads;
    };
    unsigned long countWaitingBeganTasks() const noexcept {
        unsigned long sum = 0;
        for (int i = 0; i < countThread; ++i) {
            sum += Threads[i].countWaitingBeganTasks();
        };
        return sum;
    };

    unsigned long countWaitingPickUpTasks() const noexcept {
        unsigned long sum = 0;
        for (int i = 0; i < countThread; ++i) {
            sum += Threads[i].countWaitingPickUpTasks();
        };
        return sum;
    };

    void push(Task<Func> *t) {
        if (isAllStop())
            throw std::runtime_error("All threads are stop");
        bool firstNormal = true;
        int8_t i_min;

        if (!isAllPause())
        {
            for (int8_t i = 1; i < countThread; ++i) {
                if (Threads[i].getStatus() == ThreadStates::States::work && (firstNormal || Threads[i_min].countWaitingBeganTasks() > Threads[i].countWaitingBeganTasks())) {
                    i_min = i;
                    firstNormal = false;
                };
            };

        } else
        {
            for (int8_t i = 1; i < countThread; ++i) {
                if (Threads[i].getStatus() != ThreadStates::States::have_stopped && Threads[i].getStatus() != ThreadStates::States::are_stopping && (firstNormal ||Threads[i_min].countWaitingBeganTasks() > Threads[i].countWaitingBeganTasks())) {
                    i_min = i;
                    firstNormal = false;
                };
            };
        };
        Threads[i_min].push(t);
    };

    void stopAll() const noexcept {
        for (int8_t i = 1; i < countThread; ++i) {
            Threads[i].stop();
        };
    };

    void pauseAll() const noexcept {
        for (int8_t i = 1; i < countThread; ++i) {
            Threads[i].pause();
        };
    };


    void resumeAll() const  noexcept {
        for (int8_t i = 1; i < countThread; ++i) {
            Threads[i].resume();
        };
    };

    bool isAllWork() const noexcept
    {
        bool allIsWork = true;
        for (int8_t i = 1; i < countThread; ++i) {
            allIsWork &= Threads[i].getStatus()==ThreadStates::States::work;
        };
        return allIsWork;

    };
    bool isAllPause() const noexcept
    {
        bool allIsPause = true;
        for (int8_t i = 1; i < countThread; ++i) {
            allIsPause &= Threads[i].getStatus()==ThreadStates::States::pause;
        };
        return allIsPause;
    };
    bool isAllStop() const noexcept
    {
        bool allIsStop = true;
        for (int8_t i = 1; i < countThread; ++i) {
            allIsStop = allIsStop && (Threads[i].getStatus()==ThreadStates::States::have_stopped || Threads[i].getStatus()==ThreadStates::States::are_stopping);
        };
        return allIsStop;
    };

    bool isAllComplete() const noexcept
    {
        bool allIsComplete = true;
        for (int8_t i = 1; i < countThread; ++i) {
            allIsComplete = allIsComplete && Threads[i].getStatus()==ThreadStates::States::have_stopped;
        };
        return allIsComplete;

    };

    int8_t getCountThread() const noexcept {
        return countThread;
    };
};




#endif //LAB5_THREADPOOL_H
