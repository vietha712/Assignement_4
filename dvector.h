/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/
#ifndef _VECTORDOUBLECLASS_
#define _VECTORDOUBLECLASS_

#include <iostream>

using namespace std;

class VectorDouble
{
    private:
        double *entries;
        int vectorLength;
    public:
        // mem utility functions
        void allocate();
        void deallocate();

        // constructors
        VectorDouble();
        VectorDouble(const int& vectorLength); //create a vector object of size size
        VectorDouble(const int& vectorLength, const double& inputValue); //create a vector with entries of value
        VectorDouble(const VectorDouble& vector); //copy constructor from vector v
        ~VectorDouble();

        // member methods
        int getSize(void) const;
        void setEntry(const int& index, const double& input);
        int getEntry(const int& index) const;
        void zeros(void) const;
        void ones(void) const;
        void random(const int& lower, const int& upper) const;
        double norm(const int& p) const;
        void print(void) const;
        void info(void) const;

        //Operators
        double& operator() (const int& i); // set entry
        double operator() (const int& i) const;
        //Unary
        VectorDouble operator+() const;
        VectorDouble operator-() const;
        VectorDouble& operator++(); // prefix ++v
        VectorDouble operator++(int); // postfix v++
        //Binary
        VectorDouble& operator=(const VectorDouble& inVector);
        VectorDouble& operator+=(const VectorDouble& inVector);
        VectorDouble& operator-=(const VectorDouble& inVector);
        VectorDouble& operator*=(const VectorDouble& inVector);
        VectorDouble& operator*=(const double& alpha);
        VectorDouble operator+(const VectorDouble& inVector);
        VectorDouble operator-(const VectorDouble& inVector);
        VectorDouble operator*(const VectorDouble& inVector);
        VectorDouble operator*(const double& alpha);
        VectorDouble operator^(const VectorDouble& inVector);
        //Non member operator
        friend ostream& operator<<(ostream& os, const VectorDouble& inVector);
};

// Non member operator
ostream& operator<<(ostream& os, const VectorDouble& inVector);
double dot(const VectorDouble& firstVector, const VectorDouble& secondVector);

#endif /* _VECTORDOUBLECLASS_ */