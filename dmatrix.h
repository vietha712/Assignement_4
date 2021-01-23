/*
* Linear Algebra from assignment 3
* Implemented By Ha The Viet
* Date: 08/01/2021
*/

#ifndef _MATRIXDOUBLECLASS_
#define _MATRIXDOUBLECLASS_

#include <iostream>

using namespace std;

class MatrixDouble
{
    private:
        double** entries;
        int numRows;
        int numCols;
        int type;
    public:
        //mem utility functions
        void allocate();
        void deallocate();

        //Constructors
        MatrixDouble();
        MatrixDouble(const int& numRows, const int& numCols);
        MatrixDouble(const int& numRows,
               const int& numCols,
               const double& initValue);
        MatrixDouble(const MatrixDouble& inputMatrix);
        ~MatrixDouble();

        //member methods
        int getRows(void) const;
        int getCols(void) const;
        double getEntries(const int& rowIndex, const int& colIndex) const;
        void setEntries(const int& rowIndex, const int& colIndex, double& input);
        void zeros(void) const;
        void ones(void) const;
        void eye(void) const;
        void random(const int& lower, const int& upper) const;
        void print(void) const;
        void info(void) const;

        //Entry access
        double& operator() (const int& rowIndx, const int& colIndx);
        double operator() (const int& rowIndx, const int& colIndx) const;
        //Unary
        MatrixDouble operator+() const;
        MatrixDouble operator-() const;
        MatrixDouble& operator++(); // prefix
        MatrixDouble operator++(int); // postfix
        //Binary
        MatrixDouble& operator=(const MatrixDouble& inMatrix);
        MatrixDouble& operator+=(const MatrixDouble& inMatrix);
        MatrixDouble& operator-=(const MatrixDouble& inMatrix);
        MatrixDouble& operator*=(const MatrixDouble& inMatrix);
        MatrixDouble& operator*=(const double& alpha);
        MatrixDouble operator+(const MatrixDouble& inMatrix);
        MatrixDouble operator-(const MatrixDouble& inMatrix);
        MatrixDouble operator*(const MatrixDouble& inMatrix);
        MatrixDouble operator*(const double& alpha);
        MatrixDouble operator^(const double& alpha);
        MatrixDouble& transpose(const MatrixDouble& inMatrix);
        //Non member operator
        friend ostream& operator<<(ostream& os, const MatrixDouble& inMatrix);
};

//Non member operator
ostream& operator<<(ostream& os, const MatrixDouble& inMatrix);

#endif /* _MATRIXDOUBLECLASS_ */
