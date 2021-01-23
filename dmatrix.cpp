/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/

#include "dmatrix.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include "constants.h"

using namespace std;

// Mem utility function
void Matrix::allocate()
{
    entries = new double* [numRows];
    for( int i = 0; i < numRows ; ++i)
    {
        entries[i] = new double [numCols];
    }
}

void Matrix::deallocate()
{
    for(int i = 0; i < numRows ; ++i)
    {
        delete [] entries [i];
    }

    delete [] entries;
    entries = NULL;
}

// Contructors
Matrix::Matrix()
{
    entries = NULL;
    numRows = 0;
    numCols = 0;
    type = DMAT;
}

Matrix::Matrix(const int& numRows, const int& numCols)
        : numRows(numRows), numCols(numCols), type(DMAT)
{
    assert (numRows > 0 && numCols > 0);
    allocate();
}

//Set entry
Matrix::Matrix(const int& numRows,
               const int& numCols,
               const double& initValue)
               : Matrix(numRows, numCols)
{
    for(int i = 0; i < numRows ; ++i)
        for(int j = 0; j < numCols ; ++j)
            entries [i][j] = initValue;
}

//Copy constructor
Matrix::Matrix(const Matrix& inputMatrix) 
       :Matrix(inputMatrix.getRows(), inputMatrix.getCols())
{
    for(int i = 0; i < numRows ; ++i)
        for(int j = 0; j < numCols ; ++j)
            entries[i][j] = inputMatrix.getEntries(i,j);
}

Matrix::~Matrix()
{
    deallocate();
}

//Member methods
int Matrix::getRows(void) const
{
    return numRows;
}

int Matrix::getCols(void) const
{
    return numCols;
}

double Matrix::getEntries(const int& rowIndex, const int& colIndex) const
{
    return entries[rowIndex][colIndex];
}

void Matrix::setEntries(const int& rowIndex, const int& colIndex, double& input)
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = input;
}

void Matrix::zeros(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ZERO;
}

void Matrix::ones(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ONE;
}

void Matrix::eye(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ZERO;
    
    for(int i = 0; i < numRows; ++i)
        entries[i][i] = ONE;
}

void Matrix::random(const int& lower, const int& upper) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = (double)(lower + rand() % upper);
}

void Matrix::print(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            cout << "entry[" << i << "][" << j << "] = " << entries[i][j]; 

    cout << endl;
}

void Matrix::info(void) const
{
    cout << "Number of rows: " << numRows << endl;
    cout << "Number of columns: " << numCols << endl;
    cout << "Matrix Type: " << type << endl;
}



