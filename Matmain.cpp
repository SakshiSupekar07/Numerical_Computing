
#include "Matrix.hpp"
#include<string>
using namespace std;

int main()
{
    int rows, cols;
    string filename;
    string filename1;
 
    cout<<"Enter filename to read matrix from:\n";  
    cin>>filename;
    cout<<"Enter filename to read matrix from:\n";  
    cin>>filename1;
    
   
    


    Matrix mat1(0,0),mat2(0,0);
   
    mat1.input(filename);
    mat2.input(filename1);
    cout<<"Matrix 1:\n";
    mat1.display();
    cout<<"Matrix 2:\n";
    mat2.display();


    
    Matrix sum = mat1.add(mat2);
    cout << "Sum of matrices:\n";
    sum.display();

    Matrix difference = mat1.sub(mat2);
    cout << "Difference of matrices:\n";
    difference.display();

    if (mat1.isIdentity()) {
        cout << "The First  matrix is an identity matrix.\n";
    } else {
        cout << "The First matrix is NOT an identity matrix.\n";
    }
    if (mat2.isIdentity()) {
        cout << "The Second matrix is an identity matrix.\n";
    } else {
        cout << "The Second matrix is NOT an identity matrix.\n";
    }




    return 0;
}
