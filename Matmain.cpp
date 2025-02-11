
#include "Matrix.hpp"
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    Matrix mat1(rows, cols);
    Matrix mat2(rows, cols);

    cout << "Enter elements for first matrix:\n";
    mat1.input();
    mat1.display();

    cout << "Enter elements for second matrix:\n";
    mat2.input();
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
