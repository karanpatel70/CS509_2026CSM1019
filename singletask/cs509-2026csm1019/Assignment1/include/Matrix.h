#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Matrix
{
    private:
    int M;
    int K;
    int N;
    public:
    vector<std::vector<int>> A;
    vector<std::vector<int>> B;

    Matrix();
    bool loadMatrix(const string& filename);

    int getM() const;

    int getK() const;

    int getN() const;
};

#endif // MATRIX_H