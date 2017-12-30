//
// Created by yorick on 18.11.17.
//

#ifndef LAB4_FACTORIZATION_H
#define LAB4_FACTORIZATION_H

#include <cstdint>
#include <vector>
#include <string>


class  IntegerFactorization
{
private:
    uint64_t integer;
    std::vector<uint64_t>  decomposition;
    void nativeFactorization(int64_t in);
public:
    void putInt(uint64_t in);
    std::string getStringDecomposition();
    uint64_t getInt();
    uint64_t getIntFromFactorization();
};

#endif //LAB4_FACTORIZATION_H
