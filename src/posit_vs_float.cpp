#include <iostream>
#include <cmath>
#include <iomanip>
#include "softposit_cpp.h"
#include <Eigen/Dense>

//function to print float matrix content
void printFloatMatrix(const Eigen::MatrixXf& mat, const std::string& label) {
    std::cout << label << "\n";
    std::cout << std::scientific << std::setprecision(10);
    std::cout << mat << "\n\n";
}

//function to print posit matrix content
void printPositMatrix(const Eigen::Matrix<posit32, Eigen::Dynamic, Eigen::Dynamic>& mat, const std::string& label) {
    std::cout << label << "\n";
    std::cout << std::scientific << std::setprecision(10);
    for (int i = 0; i < mat.rows(); ++i) {
        for (int j = 0; j < mat.cols(); ++j) {
            std::cout << mat(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "============================================================\n";
    std::cout << "Demonstrating Posit vs Float for extremely small values:\n";
    std::cout << "============================================================\n\n";

    double small1 = 1e-10;
    double small2 = 1e-30;

    std::cout << "Initializing two 2x2 matrices with very small values:\n";
    std::cout << "  small1 = " << std::scientific << small1 << "\n";
    std::cout << "  small2 = " << std::scientific << small2 << "\n";
    std::cout << "  One matrix uses IEEE float (Eigen::MatrixXf), the other uses posit32.\n\n";

    // Float matrix
    Eigen::MatrixXf fmat(2, 2);
    fmat << small1, small2,
            small2, small1;

    // Posit matrix
    Eigen::Matrix<posit32, Eigen::Dynamic, Eigen::Dynamic> pmat(2, 2);
    pmat << posit32(small1), posit32(small2),
            posit32(small2), posit32(small1);

    printFloatMatrix(fmat, "[Float Matrix]:");
    printPositMatrix(pmat, "[Posit32 Matrix]:");

    // Element-wise multiplication
    auto f_mul = fmat.array() * fmat.array();
    auto p_mul = pmat.array() * pmat.array();

    printFloatMatrix(f_mul, "[Float Result - Multiplication]:");
    printPositMatrix(p_mul, "[Posit32 Result - Multiplication]:");

    return 0;
}
