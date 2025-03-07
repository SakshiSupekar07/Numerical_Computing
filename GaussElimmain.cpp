#include "GaussElim.hpp"
#include <iostream>
using namespace std;

int main() {
    GaussianElimination solver;
    string filename;

    cout << "Enter file name containing the matrix: ";
    cin >> filename;

    solver.acceptMatrix(filename);   
    solver.solve();                  
    solver.displaySolution();        

    solver.freeMatrix();  

    return 0;
}
