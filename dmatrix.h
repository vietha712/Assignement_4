/*
* Linear Algebra from assignment 3
* Implemented By Ha The Viet
* Date: 08/01/2021
*/

double** allocate(const int& numCols, const int numRows);

void deallocate(double** matrix, int numRows);

void random(double** matrix, int numRows, int numCols);

void zeros(double** matrix, int numRows, int numCols);

void print(double** matrix, int numRows, int numCols);

double det(int matrixDimension, double** matrix);

void add(double **firstMatrix,
         int firstMatrixRows,
         int firstMatrixCols,
         double **secondMatrix,
         int secondMatrixRows,
         int secondMatrixCols,
         double **outputMatrix, 
         int outputMatrixRows,
         int outputMatrixCols);

void mult(double **firstMatrix,
          int firstMatrixRows,
          int firstMatrixCols,
          double **secondMatrix,
          int secondMatrixRows,
          int secondMatrixCols,
          double **outputMatrix, 
          int outputMatrixRows,
          int outputMatrixCol);

void mult(double **firstMatrix,
          int firstMatrixRows,
          int firstMatrixCols,
          double *vector,
          int vectorLength,
          double *output, 
          int outputLength);