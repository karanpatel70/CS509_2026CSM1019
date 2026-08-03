#ifndef GEMM_H
#define GEMM_H

#include <vector>
#include "Matrix.h"
using namespace std;

class GEMM
{
public:
    vector<vector<int>> simpleMultiply(const Matrix &matrix);

    vector<vector<int>> blockedMultiply(const Matrix &matrix, int blockSize);
};

#endif