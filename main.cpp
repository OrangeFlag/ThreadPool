
#include <iostream>
#include <vector>
#include <fstream>

#include <unistd.h>
#include "ThreadPool.hpp"

#include "Factorization.h"




std::string command;
bool commandIsRead = true;
std::mutex mtxKeyboard;
std::condition_variable cv;


void readKeyboard()
{
    std::string input;
    while (true)
    {
        std::cin >> input;
        if (input == "exit" || input == "pause" || input == "resume")
        {
            std::unique_lock<std::mutex> lock;
            cv.wait(lock, [&](){ return commandIsRead;});
            command = std::move(input);
            commandIsRead = false;
        }

    };
};

int main(int argc, char *argv[]) {

    if (argc != 3) {
        std::cout << "Programm need 2 arguments";
        return 0;
    }
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    std::thread thKeyboard(readKeyboard);
    thKeyboard.detach();

    uint64_t in;
    ThreadPool<void()> cntrl(2);
    std::deque<Task<void()> *> Tasks;
    std::deque<IntegerFactorization *> Classes;


    while (fin.good() || !Tasks.empty()) {
        if (!commandIsRead)
        {
            if (command == "exit")
            {
                cntrl.stopAll();
                while (!cntrl.isAllComplete())
                    sleep(1);
                for (int i = 0; i < Tasks.size(); ++i)
                {
                    if (Tasks[i]->isComplete())
                    {
                        fout << Classes[i]->getInt() << " : " << Classes[i]->getStringDecomposition() << std::endl;
                    };
                    delete Classes[i];
                    delete Tasks[i];
                };
                fout.close();
                fin.close();
                return 0;

            }
            else if (command == "pause")
            {
                cntrl.pauseAll();
                fout.close();
            }
            else
            {
                fout = std::ofstream(argv[2], std::ofstream::app);
                cntrl.resumeAll();
            };
            commandIsRead = true;
            cv.notify_one();
        };
        if (Tasks.size() <= 50 && fin.good()) {
            fin >> in;
            Classes.push_back(new IntegerFactorization());
            auto bind = new std::function<void()>(std::bind(&IntegerFactorization::putInt, Classes.back(), in));
            Tasks.push_back(new Task<void()>(*bind));
            cntrl.push(Tasks.back());
        } else if (Tasks.front()->isComplete()) {
            if(cntrl.isAllPause())
                sleep(1);
            fout << Classes.front()->getInt() << " : " << Classes.front()->getStringDecomposition() << std::endl;
            delete Classes.front();
            delete Tasks.front();
            Tasks.pop_front();
            Classes.pop_front();
        };
    };
    fin.close();
    fout.close();
    return 0;
}
