//
// Created by yorick on 18.11.17.
//

#include "Factorization.h"

void IntegerFactorization::nativeFactorization(int64_t in)
{
    uint64_t i = 2;
    while (in != 1)
    {
        if (in%i == 0)
        {
            in = in/i;
            decomposition.push_back(i);
        }else
            ++i;

    }
};

void IntegerFactorization::putInt(uint64_t in)
{
    decomposition.clear();
    integer = in;
    if (in == 0)
    {
        decomposition.push_back(in);
        return;
    }

    nativeFactorization(in);
};

std::string IntegerFactorization::getStringDecomposition()
{
    std::string out;
    for (uint64_t  i = 0; i < decomposition.size(); ++i)
    {
        out.append(std::to_string(decomposition[i]));
        if (i < decomposition.size()-1)
            out.append(";");
    }
    return out;
};

uint64_t IntegerFactorization::getInt()
{
    return integer;
};

uint64_t IntegerFactorization::getIntFromFactorization()
{
    uint64_t out = 1;
    for (uint64_t i : decomposition)
        out *= i;
    return out;
};