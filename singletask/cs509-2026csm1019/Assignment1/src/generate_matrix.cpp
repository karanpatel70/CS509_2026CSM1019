#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));

    const int M = 128;
    const int K = 128;
    const int N = 128;

    ofstream fout("../input/gemm_test_02.txt");

    fout << M << " " << K << " " << N << "\n";

    // Matrix A
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            fout << rand() % 10 << " ";
        }
        fout << "\n";
    }

    // Matrix B
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fout << rand() % 10 << " ";
        }
        fout << "\n";
    }

    fout.close();

    cout << "gemm_128.txt generated successfully.\n";

    return 0;
}