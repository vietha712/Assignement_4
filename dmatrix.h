/*
* Linear Algebra from assignment 3
* Implemented By Ha The Viet
* Date: 08/01/2021
*/

#ifndef _MATRIXDOUBLECLASS_
#define _MATRIXDOUBLECLASS_

class Matrix
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
        Matrix();
        Matrix(const int& numRows, const int& numCols);
        Matrix(const int& numRows,
               const int& numCols,
               const double& initValue);
        Matrix(const Matrix& inputMatrix);
        ~Matrix();

        //member methods
        int getRows(void) const;
        int getCols(void) const;
        int getEntries(void) const;
        void setEntry(const int& rowIndex, const int& colIndex, double& input);
        void zeros(void) const;
        void ones(void) const;
        void eye(void) const;
        void random(const int& lower, const int& upper) const;
        void print(void) const;
        void info(void) const;


}
#endif /* _MATRIXDOUBLECLASS_ */