/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/

#include "dvector.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>

using namespace std;

void VectorDouble::allocate()
{
    entries = new double [vectorLength];
}

void VectorDouble::deallocate()
{
    delete[] entries;
    entries = NULL;
}

// Constructors
VectorDouble::VectorDouble()
{
    entries = NULL;
    vectorLength = 0;
}

// Set length
VectorDouble::VectorDouble(const int& inputVectorLength)
{
    assert(vectorLength > 0);
    vectorLength = inputVectorLength;
}

// Set value for entries
VectorDouble::VectorDouble(const int& inputVectorLength, const double& inputValue)
            : VectorDouble(inputVectorLength) // call a contructor to init vector length
{
    allocate();

    for(int i = 0; i < inputVectorLength; ++i)
    {
        entries[i] = inputValue;
    }
}

// Copy vector
VectorDouble::VectorDouble(const VectorDouble& vector)
            : VectorDouble(vector.getSize()) // init vector length
{
    allocate();

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] = vector.getEntry(i);
    }
}

/**** Member methods ****/
int VectorDouble::getSize(void) const
{
    return vectorLength;
}

void VectorDouble::setEntry(const int& index, const double& input)
{
    entries[index] = input;
}

int VectorDouble::getEntry(const int& index) const
{
    return entries[index];
}

void VectorDouble::zeros(void) const
{
    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] = 0;
    }
}

void VectorDouble::ones(void) const
{
    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] = 1;
    }
}

void VectorDouble::random(const int& lower, const int& upper) const
{
    assert(lower < upper);

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] = (double)(lower + rand() % upper);
    }
}

//Steps to calculate p-norm
//1. Get the absolute value of each element of the vector.
//2. Raise these absolute values to a power p.
//3. Calculate the sum of all these raised absolute values.
//4. Raise the power to 1/p on the result of the previous step.
double VectorDouble::norm(const int& p) const
{
    assert(p >= 1);

    double calculatedNorm;
    double sumOfRaisedAbsValue = 0.0;

    // 1, 2, 3
    for(int i = 0; i < vectorLength; ++i)
    {
        sumOfRaisedAbsValue += pow(abs(entries[i]), p);
    }

    // 4
    calculatedNorm = pow(sumOfRaisedAbsValue, (1/p));

    return calculatedNorm;
}

void VectorDouble::print(void) const
{
    cout << "Vector value: " << endl;

    for(int i = 0; i < vectorLength; ++i)
    {
        cout << "vector[" << i << "] = " << entries[i]; 
    }

    cout << endl;
}

void VectorDouble::info(void) const
{
    cout << "Vector infor contains the length of the vector and its value" << endl;
    cout << "Vector length: " << vectorLength << endl;
    this->print();
}

/**** Operators ****/
double& VectorDouble::operator() (const int& i)
{
    assert(i >= 0);

    return entries[i];
}

double VectorDouble::operator() (const int& i) const
{
    assert(i >= 0);

    return entries[i];
}

//Binary op
VectorDouble& VectorDouble::operator=(const VectorDouble& inVector)
{
    assert(vectorLength == inVector.getSize());

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] = inVector(i);
    }

    return *this;
}

VectorDouble& VectorDouble::operator+=(const VectorDouble& inVector)
{
    assert(vectorLength == inVector.getSize());

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] += inVector(i);
    }

    return *this;
}

VectorDouble& VectorDouble::operator-=(const VectorDouble& inVector)
{
    assert(vectorLength == inVector.getSize());

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] += inVector(i);
    }

    return *this;
}

VectorDouble& VectorDouble::operator*=(const VectorDouble& inVector)
{
    assert(vectorLength == inVector.getSize());

    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] *= inVector(i);
    }

    return *this;
}

VectorDouble& VectorDouble::operator*=(const double& alpha)
{
    for(int i = 0; i < vectorLength; ++i)
    {
        entries[i] *= alpha;
    }

    return *this;
}

VectorDouble VectorDouble::operator+(const VectorDouble& inVector)
{
    VectorDouble temp;
    temp.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        temp(i) = entries[i] + inVector(i);
    }

    return temp;
}

VectorDouble VectorDouble::operator-(const VectorDouble& inVector)
{
    VectorDouble temp;
    temp.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        temp(i) = entries[i] - inVector(i);
    }

    return temp;
}

VectorDouble VectorDouble::operator*(const VectorDouble& inVector)
{
    VectorDouble temp;
    temp.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        temp(i) = entries[i] * inVector(i);
    }

    return temp;
}

VectorDouble VectorDouble::operator*(const double& alpha)
{
    VectorDouble temp;
    temp.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        temp(i) = entries[i] * alpha;
    }

    return temp;
}

VectorDouble VectorDouble::operator^(const VectorDouble& inVector)
{
    VectorDouble temp;
    temp.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        temp(i) = entries[i] * inVector(i);
    }

    return temp;
}

//Unary
VectorDouble VectorDouble::operator-() const
{
    VectorDouble tempVector(vectorLength);
    tempVector.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        tempVector(i) = -(entries[i]);
    }

    return tempVector;
}

VectorDouble VectorDouble::operator+() const
{
    VectorDouble tempVector(vectorLength);
    tempVector.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        tempVector(i) = +(entries[i]);
    }

    return tempVector;
}

VectorDouble& VectorDouble::operator++() //prefix
{
    for(int i = 0; i < vectorLength; ++i)
    {
        ++(entries[i]);
    }

    return *this;
}

VectorDouble VectorDouble::operator++(int)
{
    VectorDouble tempVector(vectorLength);
    tempVector.zeros();

    for(int i = 0; i < vectorLength; ++i)
    {
        tempVector(i) = ++(entries[i]);
    }

    return tempVector;
}

#if 0
double* allocate(int vectorLength)
{
    double* vector;

    vector = new double [vectorLength];

    return vector;
}

void deallocate(double* vector)
{
    delete[] vector;
}

void random(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        vector[i] = rand() % 10;
    }
}

void zeros(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        vector[i] = 0;
    }
}

double& set(double* vector, int vectorLength, int entry)
{
    assert(vectorLength > entry);

    return vector[entry];
}

void print(double* vector, int vectorLength)
{
    int i;

    for(i = 0; i < vectorLength; ++i)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

void add(double *firstVector, 
         int firstVectorLength, 
         double *secondVector,
         int secondVectorLength, 
         double *outputVector, 
         int outputVectorLength)
{
    int i;

    assert(firstVectorLength == secondVectorLength);

    for(i = 0; i < outputVectorLength; ++i)
    {
        outputVector[i] = firstVector[i] + secondVector[i];
    }
}

double dot(double *firstVector, 
           int firstVectorLength, 
           double *secondVector, 
           int secondVectorLength)
{
    int i;
    double product(0.0);
    double output;

    assert(firstVectorLength == secondVectorLength);

    for(i = 0; i < secondVectorLength; ++i)
    {
        product = firstVector[i] * secondVector[i];
        output += product;
    }

    return output;
}

#endif