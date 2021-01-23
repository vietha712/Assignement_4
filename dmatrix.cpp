/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/

#include "dmatrix.h"
#include <cstdlib>
#include "constants.h"
#include <iostream>
#include <cassert>

using namespace std;

#if 0
double** allocate(const int& numCols, const int numRows)
{
    double **matrix;
    int i;

    matrix = new double* [numRows];

    for(i = 0; i < numCols; ++i)
    {
        matrix[i] = new double [numCols];
    }

    return matrix;
}

void deallocate(double** matrix, int numRows)
{
    int i;

    for(i = 0; i < numRows; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void random(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void zeros(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            matrix[i][j] = 0.0;
        }
    }
}

void print(double** matrix, int numRows, int numCols)
{
    int i,j;

    for(i = 0; i < numRows; ++i)
    {
        for(j = 0; j < numCols; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << endl;
}

// ma
static void getCoFactor(double** matrix, 
                        double** tempMatrix, 
                        int matrixRows,
                        int matrixCols,
                        int dimension)
{
    int i, j;
    int indexRow, indexCol;
 
    // Looping for each element of the matrix
    for(indexRow = 0; indexRow < dimension; ++indexRow)
    {
        for (indexCol = 0, i = 0, j = 0; indexCol < dimension; ++indexCol) 
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (indexRow != matrixRows && indexCol != matrixCols) 
            {
                tempMatrix[i][j++] = matrix[indexRow][indexCol];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == dimension - 1) 
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double det(int matrixDimension, double** matrix)
{
    double determinant = 0;
    // temporary matrix to store cofactors
    double** tempMatrix;
    // multiplier sign
    int sign = 1;
    int i;

    // early return to reduce the complexity
    if(1 == matrixDimension)
    {
        return matrix[0][0];
    }

    tempMatrix = new double* [DIMENSION_SQUARE_MATRIX];
    for(i = 0; i < DIMENSION_SQUARE_MATRIX; ++i)
    {
        tempMatrix[i] = new double [DIMENSION_SQUARE_MATRIX];
    }

    for(i = 0; i < matrixDimension; ++i)
    {
        getCoFactor(matrix, tempMatrix, 0, i, matrixDimension);

        determinant += (sign * matrix[0][i] * det(matrixDimension - 1, tempMatrix));

        sign = -sign;
    }

    return determinant;
}

void add(double **firstMatrix,
         int firstMatrixRows,
         int firstMatrixCols,
         double **secondMatrix,
         int secondMatrixRows,
         int secondMatrixCols,
         double **outputMatrix, 
         int outputMatrixRows,
         int outputMatrixCols)
{
    assert(firstMatrixRows == secondMatrixRows);
    assert(firstMatrixCols == secondMatrixCols);

    int i,j;
    for(i = 0; i < outputMatrixRows; ++i)
    {
        for(j = 0; j < outputMatrixCols; ++j)
        {
            outputMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

// Matrix multiply matrix
void mult(double **firstMatrix,
          int firstMatrixRows,
          int firstMatrixCols,
          double **secondMatrix,
          int secondMatrixRows,
          int secondMatrixCols,
          double **outputMatrix, 
          int outputMatrixRows,
          int outputMatrixCol)
{
    assert(firstMatrixCols == secondMatrixRows);

    for(int i = 0; i < firstMatrixRows; ++i)
    {
        for(int j = 0; j < secondMatrixCols; ++j)
        {
            for(int k = 0; k < firstMatrixCols; ++k)
            {
                outputMatrix[i][j] += (firstMatrix[i][k] * secondMatrix[k][j]);
            }
        }
    }
}

void mult(double **matrix,
          int matrixRows,
          int matrixCols,
          double *vector,
          int vectorLength,
          double *output, 
          int outputLength)
{
    assert(vectorLength == matrixCols);
    assert(vectorLength == outputLength);

    int i, j;
    double sumPerRow;

    for(i = 0; i < outputLength; ++i)
    {
        for(j = 0, sumPerRow = 0; j < matrixCols; ++j)
        {
            sumPerRow += (vector[j] * matrix[i][j]);
        }

        output[i] = sumPerRow;
    }
}

#endif