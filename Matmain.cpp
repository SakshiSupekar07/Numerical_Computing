#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main()
{
    string file1, file2;

    cout << "Enter first filename: ";
    cin >> file1;
    cout << "Enter second filename: ";
    cin >> file2;

    Matrix m1(0, 0), m2(0, 0);
    m1.input(file1);
    m2.input(file2);

    cout << "\nMatrix 1:\n";
    m1.display();

    cout << "\nMatrix 2:\n";
    m2.display();

    cout << "\nSum of matrices:\n";
    m1.add(m2);
    m1.display();

    cout << "\nDifference of matrices:\n";
    m1.sub(m2);
    m1.display();

    cout << "\nMatrix 1 is " << (m1.isIdentity() ? "" : "NOT ") << "an Identity Matrix.\n";
    cout << "Matrix 2 is " << (m2.isIdentity() ? "" : "NOT ") << "an Identity Matrix.\n";

    cout << "\nSolving using Gauss Elimination:\n";
    m1.solve();
    m1.displaySolution();

    return 0;
}
