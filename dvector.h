/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/
#ifndef _VECTORDOUBLECLASS_
#define _VECTORDOUBLECLASS_

class VectorDouble
{
    private:
        double *entries;
        int vectorLength;
    public:
        // mem utility function
        void allocate();
        void deallocate();

        // constructors
        VectorDouble();
        VectorDouble(const int& vectorLength); //create a vector object of size size
        VectorDouble(const int& vectorLength, const double& inputValue); //create a vector with entries of value
        VectorDouble(const VectorDouble& vector); //copy constructor from vector v

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
        VectorDouble operator=(const VectorDouble&) const;
        VectorDouble operator+(const VectorDouble&) const;
        VectorDouble operator-(const VectorDouble&) const;
        VectorDouble operator=(const VectorDouble&) const;
        VectorDouble operator+(const VectorDouble&) const;
        VectorDouble operator-(const VectorDouble&) const;

};

#if 0
double* allocate(int vectorLength);

void deallocate(double* vector);

void random(double* vector, int vectorLength);

void zeros(double* vector, int vectorLength);

double& set(double* vector, int vectorLength, int entry);

void print(double* vector, int vectorLength);

void add(double *firstVector, 
         int firstVectorLength, 
         double *secondVector,
         int secondVectorLength, 
         double *outputVector, 
         int outputVectorLength);

double dot(double *firstVector, 
           int firstVectorLength, 
           double *secondVector, 
           int secondVectorLength);

#endif

#endif /* _VECTORDOUBLECLASS_ */