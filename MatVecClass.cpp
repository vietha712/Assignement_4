/*
* Assignment 4
* Implemented By Ha The Viet
* Date: 20/01/2021
*/

#include <iostream>
#include "dmatrix.h"
#include "dvector.h"

using namespace std;

int main(void)
{
    /*
     * For vectors
     */

    double *v, *w, *t;
    int size_v(5) , size_w(5) , size_t(5);

    // === allocation
    v = allocate(size_v);
    w = allocate(size_w);
    t = allocate(size_t);

    // === initialization
    random(v, size_v);
    random(w, size_w);
    zeros(t, size_t);

    // === set and print vectors
    cout << "v is";
    print(v, size_v);
    cout << " set v [2] = 5";
    set(v, size_v , 2) = 10.0;
    print(v, size_v );
    cout << "w is";
    print(w, size_w ); 
    // === t = v + w
    add(v, size_v , w, size_w , t, size_t);
    cout << "t = v + w is";
    print(t, size_t); 
    // === dot product of v * w
    cout << " dot product of v * w is " <<
    dot(v, size_v , w, size_w) << endl;

    /*
    * For matrices
    */

    double ** A1 , **A2 , **A;
    int numRows_A1(5), numCols_A1(5);
    int numRows_A2(5), numCols_A2(5);
    int numRows_A(5), numCols_A(5); 
    // === allocation
    A1 = allocate(numRows_A1 , numCols_A1);
    A2 = allocate(numRows_A2 , numCols_A2);
    A = allocate(numRows_A , numCols_A); 
    // === initialization
    random(A1 , numRows_A1 , numCols_A1);
    random(A2 , numRows_A2 , numCols_A2);
    zeros(A, numRows_A , numCols_A);  
    // === print out matrices
    cout << "A1 is";
    print(A1 , numRows_A1 , numCols_A1);
    cout << " det (A1) = " << det ( numRows_A1 , A1) << endl;
    cout << "A2 is";
    print (A2 , numRows_A2 , numCols_A2);
    cout << " det (A2) = " << det ( numRows_A2 , A2) << endl;  
    // === A = A1 + A2
    add(A1 , numRows_A1 , numCols_A1 ,
    A2 , numRows_A2 , numCols_A2 ,
    A, numRows_A , numCols_A);
    cout << "A = A1 + A2 is";
    print(A, numRows_A , numCols_A);  
    // === t = A*v
    mult(A, numRows_A , numCols_A ,
    v, size_v , t, size_t);
    cout << "A is";
    print (A, numRows_A , numCols_A);
    cout << "v is";
    
    print(v, size_v );
    cout << "t = A*v is";
    print(t, size_t );
    // === A = A1 * A2
    mult(A1 , numRows_A1 , numCols_A1 ,
    A2 , numRows_A2 , numCols_A2 ,
    A, numRows_A , numCols_A );
    cout << "A = A1 * A2 is";
    print(A, numRows_A , numCols_A);
    // === deallocation
    deallocate(v);
    deallocate(w);
    deallocate(t);
    deallocate(A1 , numRows_A1);
    deallocate(A2 , numRows_A2);
    deallocate(A, numRows_A);

    return 0;
}