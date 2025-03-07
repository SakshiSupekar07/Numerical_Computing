#include "GaussElim.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void GaussianElimination::acceptMatrix( string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found!" << endl;
        exit(1);
    }

    file >> rows >> cols;   

    
    mat = new float*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new float[cols];
    }
    solution = new float[rows];

  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> mat[i][j];
        }
    }

    file.close();
}

void GaussianElimination::solve() {
  
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            float r = mat[j][i] / mat[i][i];
            for (int k = 0; k < cols; k++) {
                mat[j][k] -= r * mat[i][k];
            }
        }
    }

  
    for (int i = rows - 1; i >= 0; i--) {
        solution[i] = mat[i][cols - 1];  
        for (int j = i + 1; j < rows; j++) {
            solution[i] -= mat[i][j] * solution[j];
        }
        solution[i] /= mat[i][i];
    }
}

void GaussianElimination::displaySolution() {
    cout << "Solution:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "x" << (i + 1) << " = " << solution[i] << endl;
    }
}

void GaussianElimination::freeMatrix() {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    delete[] solution;
}
