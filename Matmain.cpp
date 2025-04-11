#include "Matrix.hpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string filename, filename1, leftfile, rightfile, filenameLU, filenameIter;

    cout << "Enter filename to read first matrix from: ";
    cin >> filename;
    cout << "Enter filename to read second matrix from: ";
    cin >> filename1;

    Matrix mat1(0, 0), mat2(0, 0);
    mat1.input(filename);
    mat2.input(filename1);

    cout << "Matrix 1:\n";
    mat1.display();
    cout << "Matrix 2:\n";
    mat2.display();

    Matrix sum = mat1.add(mat2);
    cout << "Sum of matrices:\n";
    sum.display();

    Matrix difference = mat1.sub(mat2);
    cout << "Difference of matrices:\n";
    difference.display();

    if (mat1.isIdentity())
        cout << "Matrix 1 is an identity matrix.\n";
    else
        cout << "Matrix 1 is NOT an identity matrix.\n";

    if (mat2.isIdentity())
        cout << "Matrix 2 is an identity matrix.\n";
    else
        cout << "Matrix 2 is NOT an identity matrix.\n";

    cout << "Enter filename to read matrix for LU decomposition: ";
    cin >> filenameLU;
    Matrix luMat(0, 0);
    luMat.inputLU(filenameLU);

    cout << "Choose LU decomposition method:\n";
    cout << "1. Doolittle\n";
    cout << "2. Crout\n";
    cout << "3. Cholesky\n";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        luMat.luDecomposition();
        break;
    case 2:
        luMat.luCrout();
        break;
    case 3:
        luMat.luCholesky();
        break;
    default:
        cout << "Invalid choice.\n";
    }

    cout << "Enter filename for left matrix: ";
    cin >> leftfile;
    cout << "Enter filename for right matrix: ";
    cin >> rightfile;

    Matrix augMat(0, 0);
    augMat.inputAugmented(leftfile, rightfile);
    augMat.display();

    augMat.solve();
    augMat.displaySolution();

    cout << "Enter filename for Gauss-Jacobi and Gauss-Seidel matrix: ";
    cin >> filenameIter;

    Matrix iterMat(0, 0);
    iterMat.inputIterative(filenameIter);
    cout << "\nMatrix read from file:\n";
    iterMat.display();

    cout << "\nRunning Gauss-Jacobi...\n";
    iterMat.gaussJacobi(5, 1e-6);

    cout << "\nRunning Gauss-Seidel...\n";
    iterMat.gaussSeidel(5, 1e-6);

    return 0;
}
