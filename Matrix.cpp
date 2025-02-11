#include "Matrix.hpp"
using namespace std;

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}


    void Matrix::input() {
        cout << "Enter elements for " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }
    
    void Matrix::display() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    Matrix Matrix::add(Matrix& mat) {
        Matrix add(rows, cols);
    
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                add.data[i][j] = data[i][j] + mat.data[i][j];
            }
        }
        return add;
    }
    
    Matrix Matrix::sub(Matrix& mat) {
        Matrix sub(rows, cols);
    
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sub.data[i][j] = data[i][j] - mat.data[i][j];
            }
        }
        return sub;
    }

    bool Matrix::isIdentity() {
        if (rows != cols) return false; // Identity matrix must be square
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)) {
                    return false;
                }
            }
        }
        return true;
    }
   