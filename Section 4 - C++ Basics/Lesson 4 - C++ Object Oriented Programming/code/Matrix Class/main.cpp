#include <iostream>
#include <vector>
#include "matrix.h"

int main () {

    std::vector <std:: vector <float> >
            initial_grid (7, std::vector <float>(5, 0.4));

    Matrix matrixA(initial_grid);

    matrixA.print_matrix();

    std::cout << matrixA.getRows() << std::endl;

    std::cout << matrixA.getCols() << std::endl;

    Matrix transposeA = matrixA.matrix_transpose();

    transposeA.print_matrix();

    std::vector <std:: vector <float> >
            second_grid (7, std::vector <float>(5, 0.2));

    Matrix matrixB(second_grid);

    Matrix matrixSum = matrixA.matrix_addition(matrixB);

    matrixSum.print_matrix();

    return 0;
}