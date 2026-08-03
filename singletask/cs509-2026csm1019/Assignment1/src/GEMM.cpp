#include "../include/GEMM.h"
#include<bits/stdc++.h>
#include <algorithm>
std::vector<std::vector<int>> GEMM::simpleMultiply(const Matrix &matrix)
{
    int M = matrix.getM();
    int K = matrix.getK();
    int N = matrix.getN();

    std::vector<std::vector<int>> C(M, std::vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C[i][j] += matrix.A[i][k] * matrix.B[k][j];
            }
        }
    }

    return C;
}

std::vector<std::vector<int>> GEMM::blockedMultiply(const Matrix &matrix, int blockSize)
{
        int M = matrix.getM();
    int K = matrix.getK();
    int N = matrix.getN();

    std::vector<std::vector<int>> C(M, std::vector<int>(N, 0));

    for (int ii = 0; ii < M; ii += blockSize)
    {
        for (int jj = 0; jj < N; jj += blockSize)
        {
            for (int kk = 0; kk < K; kk += blockSize)
            {
                for (int i = ii; i < std::min(ii + blockSize, M); i++)
                {
                    for (int j = jj; j < std::min(jj + blockSize, N); j++)
                    {
                        for (int k = kk; k < std::min(kk + blockSize, K); k++)
                        {
                            C[i][j] += matrix.A[i][k] * matrix.B[k][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}