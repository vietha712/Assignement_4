/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/

#include "dmatrix.h"
#include <cstdlib>
#include <cassert>
#include "constants.h"

// Mem utility function
void MatrixDouble::allocate()
{
    entries = new double* [numRows];
    for( int i = 0; i < numRows ; ++i)
    {
        entries[i] = new double [numCols];
    }
}

void MatrixDouble::deallocate()
{
    for(int i = 0; i < numRows ; ++i)
    {
        delete [] entries [i];
    }

    delete [] entries;
    entries = NULL;
}

// Contructors
MatrixDouble::MatrixDouble()
{
    entries = NULL;
    numRows = 0;
    numCols = 0;
    type = DMAT;
}

MatrixDouble::MatrixDouble(const int& numRows, const int& numCols)
        : numRows(numRows), numCols(numCols), type(DMAT)
{
    assert (numRows > 0 && numCols > 0);
    allocate();
}

//Set entry
MatrixDouble::MatrixDouble(const int& numRows,
               const int& numCols,
               const double& initValue)
               : MatrixDouble(numRows, numCols)
{
    for(int i = 0; i < numRows ; ++i)
        for(int j = 0; j < numCols ; ++j)
            entries [i][j] = initValue;
}

//Copy constructor
MatrixDouble::MatrixDouble(const MatrixDouble& inputMatrix) 
       :MatrixDouble(inputMatrix.getRows(), inputMatrix.getCols())
{
    for(int i = 0; i < numRows ; ++i)
        for(int j = 0; j < numCols ; ++j)
            entries[i][j] = inputMatrix.getEntries(i,j);
}

MatrixDouble::~MatrixDouble()
{
    deallocate();
}

//Member methods
int MatrixDouble::getRows(void) const
{
    return numRows;
}

int MatrixDouble::getCols(void) const
{
    return numCols;
}

double MatrixDouble::getEntries(const int& rowIndex, const int& colIndex) const
{
    return entries[rowIndex][colIndex];
}

void MatrixDouble::setEntries(const int& rowIndex, const int& colIndex, double& input)
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = input;
}

void MatrixDouble::zeros(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ZERO;
}

void MatrixDouble::ones(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ONE;
}

void MatrixDouble::eye(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = ZERO;
    
    for(int i = 0; i < numRows; ++i)
        entries[i][i] = ONE;
}

void MatrixDouble::random(const int& lower, const int& upper) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            entries[i][j] = (double)(lower + rand() % upper);
}

void MatrixDouble::print(void) const
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j <numCols; ++j)
            cout << "entry[" << i << "][" << j << "] = " << entries[i][j]; 

    cout << endl;
}

void MatrixDouble::info(void) const
{
    cout << "Number of rows: " << numRows << endl;
    cout << "Number of columns: " << numCols << endl;
    cout << "MatrixDouble Type: " << type << endl;
}

double& MatrixDouble::operator() (const int& rowIndx, const int& colIndx)
{
    assert(rowIndx > -1 && rowIndx < numRows);
    assert(colIndx > -1 && colIndx < numCols);

    return entries[rowIndx][colIndx];
}

double MatrixDouble::operator() (const int& rowIndx, const int& colIndx) const
{
    assert (rowIndx > -1 && rowIndx < numRows);
    assert (colIndx > -1 && colIndx < numCols);

    return entries[rowIndx][colIndx];
}

//Unary
MatrixDouble MatrixDouble::operator+() const
{
    MatrixDouble tempMatrix( numRows , numCols );
    tempMatrix.zeros ();
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = +entries[i][j];
    
    return tempMatrix;    
}

MatrixDouble MatrixDouble::operator-() const
{
    MatrixDouble tempMatrix(numRows, numCols);
    tempMatrix.zeros();

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = -entries[i][j];
    
    return tempMatrix;    
}

MatrixDouble& MatrixDouble::operator++()
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            ++entries[i][j];

    return *this;
}

MatrixDouble MatrixDouble::operator++(int)
{
    MatrixDouble tempMatrix(numRows, numCols);
    tempMatrix.zeros();

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = ++entries[i][j];

    return tempMatrix;
}

MatrixDouble& MatrixDouble::operator=(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            entries[i][j] = inMatrix(i,j);

    return *this;
}

MatrixDouble& MatrixDouble::operator+=(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            entries[i][j] += inMatrix(i,j);

    return *this;
}

MatrixDouble& MatrixDouble::operator-=(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            entries[i][j] -= inMatrix(i,j);

    return *this;
}

MatrixDouble& MatrixDouble::operator*=(const MatrixDouble& inMatrix)
{
    assert(numCols == inMatrix.getRows());

    for(int i = 0; i < numRows; ++i)
    {
        for(int j = 0; j < inMatrix.getCols(); ++j)
        {
            for(int k = 0; k < numCols; ++k)
            {
                entries[i][j] += (entries[i][k] * inMatrix(k,j));
            }
        }
    }

    return *this;
}

MatrixDouble& MatrixDouble::operator*=(const double& alpha)
{
    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            entries[i][j] *= alpha;

    return *this;
}

MatrixDouble MatrixDouble::operator+(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    MatrixDouble tempMatrix;

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = entries[i][j] + inMatrix(i,j);

    return tempMatrix;
}

MatrixDouble MatrixDouble::operator-(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    MatrixDouble tempMatrix;

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = entries[i][j] - inMatrix(i,j);

    return tempMatrix;
}

MatrixDouble MatrixDouble::operator*(const MatrixDouble& inMatrix)
{
    assert(numCols == inMatrix.getRows());

    MatrixDouble tempMatrix;

    for(int i = 0; i < numRows; ++i)
    {
        for(int j = 0; j < inMatrix.getCols(); ++j)
        {
            for(int k = 0; k < numCols; ++k)
            {
                tempMatrix(i,j) = (entries[i][k] * inMatrix(k,j));
            }
        }
    }

    return tempMatrix;
}

MatrixDouble MatrixDouble::operator*(const double& alpha)
{
    MatrixDouble tempMatrix;

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = entries[i][j] * alpha;

    return tempMatrix;
}

MatrixDouble MatrixDouble::operator^(const double& alpha)
{
    MatrixDouble tempMatrix;

    for(int i = 0; i < numRows; ++i)
        for(int j = 0; j < numCols; ++j)
            tempMatrix(i,j) = (int)entries[i][j] ^ (int)alpha;

    return tempMatrix;
}

MatrixDouble& MatrixDouble::transpose(const MatrixDouble& inMatrix)
{
    assert(numRows == inMatrix.getRows());
    assert(numCols == inMatrix.getCols());

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j) 
        {
            entries[j][i] = inMatrix(i,j);
        }
    }

    return *this;
}

ostream& operator<<(ostream& os, const MatrixDouble& inMatrix)
{
    for(int i = 0; i < inMatrix.getRows(); ++i)
        for(int j = 0; j < inMatrix.getCols(); ++j)
            os << inMatrix.getEntries(i,j);

    return os;
}

