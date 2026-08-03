#include "../include/Matrix.h"
#include<bits/stdc++.h>
using namespace std;
Matrix::Matrix()
{
    M = 0;
    K = 0;
    N = 0;
}

bool Matrix::loadMatrix(const string &filename)
{
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "Error : Unable to open file : " << filename << endl;
        return false;
    }

    fin >> M >> K >> N;

    A.assign(M, vector<int>(K));
    B.assign(K, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            fin >> A[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> B[i][j];
        }
    }

    fin.close();

    return true;
}

int Matrix::getM() const
{
    return M;
}

int Matrix::getK() const
{
    return K;
}

int Matrix::getN() const
{
    return N;
}