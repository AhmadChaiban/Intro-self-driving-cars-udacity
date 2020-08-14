#include "matrix.h"
#include <iostream>

Matrix::Matrix(){
    std::vector< std::vector <float> > default_grid(4,std::vector<float> (4, 0));
    grid = default_grid;
    rows = default_grid.size();
    cols = default_grid[0].size();
}

Matrix::Matrix(std::vector< std::vector <float> > defined_grid){
    grid = defined_grid;
    rows = defined_grid.size();
    cols = defined_grid[0].size();
}

void Matrix::setGrid(std::vector< std::vector <float> > new_grid){
    grid = new_grid;
    rows = new_grid.size();
    cols = new_grid[0].size();
}

std::vector< std::vector <float> > Matrix::getGrid() {
    return grid;
}

std::vector<float>::size_type Matrix::getRows() {
    return rows;
}

std::vector<float>::size_type Matrix::getCols() {
    return cols;
}

void Matrix::print_matrix() {
    std::cout << std::endl;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::matrix_addition(Matrix other) {
    if(rows != other.getRows() || cols != other.getCols()){
        std::invalid_argument("error matrices aren't fit for addition");
    }

    std::vector< std::vector <float> > grid_result;
    std::vector<float> row_result;
    for(int i=0; i<rows; i++){
        row_result.clear();
        for(int j=0; j<cols; j++){
            row_result.push_back(grid[i][j] + other.getGrid()[i][j]);
        }
        grid_result.push_back(row_result);
    }
    return Matrix(grid_result);
}

Matrix Matrix::matrix_transpose(){

    std::vector< std::vector <float> > grid_result;
    std::vector<float> row_result;
    for(int i=0; i<cols; i++){
        row_result.clear();
        for(int j=0; j<rows; j++){
            row_result.push_back(grid[j][i]);
        }
        grid_result.push_back(row_result);
    }
    return Matrix(grid_result);
}



/* TODO: Define the default constructor. Remember the syntax is
**      Classname::ClassName() {
**
**          initialize variables
**
**       }
**
**
**      You need to initialize the grid variable to a default value such as
**      a 4x4 matrix with all zeros.
**
**      Then initialize the rows variable, and the cols variable using the
**      vector size method. For example myvector.size() will give the size of
**      a vector. For a 2-dimensional vector, myvector.size() would be the
**      number of rows in a matrix.
**
*/

/* TODO: Define a constructor that receives a 2-Dimensional vector
**       and assigns the vector to the grid variable.
**
**      Remember the syntax is
**      Classname::ClassName(datatype inputvariablename) {
**
**          classvariable = inputvariablename
**
**       }
**
**      Then initialize the rows variable, and the cols variable exactly
**      as you did for the default constructor.
**
*/

/*
** TODO: Define a function setGrid()
**   INPUTS: a 2-D vector
**   OUPUTS: void
**
**   This function receives a 2-D vector reprenting a matrix, and then
**    updates the grid, rows, and cols variables
**
*/

/*
** TODO: Define getGrid(), getRows(), and getCols() functions.
**    INPUTS: None of these functions have inputs
**    OUPUTS: Each function should return its respective variable
**            For example, getRows returns the rows variable
*/