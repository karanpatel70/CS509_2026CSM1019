#include "../include/Matrix.h"
#include "../include/GEMM.h"
#include "../include/Timer.h"

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string inputFile = "tests/gemm_test_03.txt";

    Matrix matrix;

    if (!matrix.loadMatrix(inputFile))
        return 0;

    std::cout << "M = " << matrix.getM() << '\n';
std::cout << "K = " << matrix.getK() << '\n';
std::cout << "N = " << matrix.getN() << '\n';

    // Generate output filename automatically
    std::string outputFile = inputFile;

    size_t pos = outputFile.find("tests/");
    if (pos != std::string::npos)
        outputFile.replace(pos, 6, "outputs/");

    pos = outputFile.find(".txt");
    if (pos != std::string::npos)
        outputFile.replace(pos, 4, "_output.txt");

    std::ofstream fout(outputFile);

    if (!fout.is_open())
    {
        std::cout << "Unable to create output file.\n";
        return 0;
    }

    GEMM gemm;

    Timer timer;

    timer.start();
    auto simple = gemm.simpleMultiply(matrix);
    timer.stop();
    double simpleTime = timer.getExecutionTime();

        std::cout << "Starting Blocked GEMM...\n";
        timer.start();
        auto blocked = gemm.blockedMultiply(matrix, 32);
        timer.stop();
        double blockedTime = timer.getExecutionTime();
        std::cout << "Blocked GEMM Finished.\n";

    fout << "Simple GEMM Result\n\n";

    for (int i = 0; i < matrix.getM(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
            fout << simple[i][j] << " ";

        fout << std::endl;
    }

    fout << "\nBlocked GEMM Result\n\n";

    for (int i = 0; i < matrix.getM(); i++)
    {
        for (int j = 0; j < matrix.getN(); j++)
            fout << blocked[i][j] << " ";

        fout << std::endl;
    }

    fout << "\nSimple GEMM Time : "
         << simpleTime << " ms\n";

    fout << "Blocked GEMM Time : " << blockedTime << " ms\n";

    fout.close();

    std::cout << "Output saved to : " << outputFile << std::endl;

    return 0;
}