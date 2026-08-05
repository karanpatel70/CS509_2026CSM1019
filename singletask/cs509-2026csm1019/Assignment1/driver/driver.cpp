#include "../include/Matrix.h"
#include "../include/GEMM.h"
#include "../include/Timer.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void runTest(const   string &inputFile)
{
    Matrix matrix;

    if(!matrix.loadMatrix(inputFile))
    {
      cout << "Error: Unable to open " << inputFile <<   endl;
        return;
    }
    // Generate output filename
      string outputFile = inputFile;

    size_t pos = outputFile.find("tests/");
    if (pos !=   string::npos)
        outputFile.replace(pos, 6, "outputs/");

    pos = outputFile.find(".txt");
    if (pos !=   string::npos)
        outputFile.replace(pos, 4, "_output.txt");

      ofstream fout(outputFile);

    if (!fout.is_open())
    {
          cout << "Error: Unable to create output file.\n";
        return;
    }

    GEMM gemm;
    Timer timer;

    // Simple GEMM
    timer.start();
    auto simple = gemm.simpleMultiply(matrix);
    timer.stop();
    double simpleTime = timer.getExecutionTime();

    // Blocked GEMM
    timer.start();
    auto blocked = gemm.blockedMultiply(matrix, 32);
    timer.stop();
    double blockedTime = timer.getExecutionTime();

    fout << "Algorithm : Simple GEMM\n";
    fout << "Result Matrix:\n";

    for (int i = 0; i < matrix.getM(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
            fout << simple[i][j] << " ";

        fout << '\n';
    }

    fout << "\nExecution Time : "
         << simpleTime << " ms\n\n";

    fout << "Algorithm : Blocked GEMM\n";
    fout << "Result Matrix:\n";

    for (int i = 0; i < matrix.getM(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
            fout << blocked[i][j] << " ";

        fout << '\n';
    }

    fout << "\nExecution Time : "
         << blockedTime << " ms\n";

    fout.close();

      cout << inputFile << "  -->  Completed\n";
      cout << "Output File : " << outputFile << "\n\n";
}

int main()
{
    int choice;

      cout << "=====================================\n";
      cout << "      Assignment 01 : GEMM\n";
      cout << "=====================================\n";
      cout << "1. Run One Test File\n";
      cout << "2. Run All Test Files\n";
      cout << "3. Exit\n";
      cout << "Enter Choice : ";

      cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int testChoice;

          cout << "\nAvailable Test Files\n";
          cout << "1. gemm_test_01.txt\n";
          cout << "2. gemm_test_02.txt\n";
          cout << "3. gemm_test_03.txt\n";

          cout << "\nEnter Test Number : ";
          cin >> testChoice;

        switch (testChoice)
        {
        case 1:
            runTest("tests/gemm_test_01.txt");
            break;

        case 2:
            runTest("tests/gemm_test_02.txt");
            break;

        case 3:
            runTest("tests/gemm_test_03.txt");
            break;

        default:
              cout << "Invalid Test Selection.\n";
        }

        break;
    }

    case 2:

        runTest("tests/gemm_test_01.txt");
        runTest("tests/gemm_test_02.txt");
        runTest("tests/gemm_test_03.txt");

          cout << "=====================================\n";
          cout << "All Test Files Executed Successfully.\n";
          cout << "=====================================\n";

        break;

    case 3:
          cout << "Exiting...\n";
        break;

    default:
          cout << "Invalid Choice.\n";
    }

    return 0;
}