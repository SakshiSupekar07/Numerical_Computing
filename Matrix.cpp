#include "Matrix.hpp"
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    data = new double *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
}
void Matrix::inputIterative(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    int newrows, newcols;
    file >> newrows >> newcols;

    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;

    rows = newrows;
    cols = newcols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file >> data[i][j];

    file.close();
}


void Matrix::input(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "File not found: " << filename << endl;
        return;
    }

    int newrows, newcols;
    file >> newrows >> newcols;
    newcols = newrows + 2;

    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;

    rows = newrows;
    cols = newcols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file >> data[i][j];

    file.close();
}

void Matrix::inputLU(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "File not found: " << filename << endl;
        return;
    }

    int newrows, newcols;
    file >> newrows >> newcols;

    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;

    rows = newrows;
    cols = newcols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file >> data[i][j];

    file.close();
}

void Matrix::inputAugmented(string &leftfile, string &rightfile)
{
    ifstream fileL(leftfile), fileR(rightfile);

    if (!fileL.is_open() || !fileR.is_open())
    {
        cout << "Unable to open files!\n";
        return;
    }

    int fileRows, fileCols;
    fileL >> fileRows >> fileCols;
    fileCols = fileRows + 1;

    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;

    rows = fileRows;
    cols = fileCols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new double[cols]();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            fileL >> data[i][j];

    for (int i = 0; i < rows; i++)
        fileR >> data[i][cols - 1];

    fileL.close();
    fileR.close();
}

void Matrix::display()
{
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << fixed << setprecision(2) << data[i][j] << " ";
        cout << endl;
    }
}

Matrix Matrix::add(Matrix &mat)
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + mat.data[i][j];
    return result;
}

Matrix Matrix::sub(Matrix &mat)
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] - mat.data[i][j];
    return result;
}

bool Matrix::isIdentity()
{
    if (rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0))
                return false;

    return true;
}

void Matrix::luDecomposition()
{
    Matrix L(rows, cols), U(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int k = i; k < cols; k++)
        {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L.data[i][j] * U.data[j][k];
            U.data[i][k] = data[i][k] - sum;
        }

        for (int k = i; k < rows; k++)
        {
            if (i == k)
                L.data[i][i] = 1;
            else
            {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L.data[k][j] * U.data[j][i];
                L.data[k][i] = (data[k][i] - sum) / U.data[i][i];
            }
        }
    }

    cout << "\nDoolittle - Lower Triangular Matrix (L):\n";
    L.display();
    cout << "\nDoolittle - Upper Triangular Matrix (U):\n";
    U.display();
}

void Matrix::luCrout()
{
    Matrix L(rows, cols), U(rows, cols);

    for (int j = 0; j < cols; j++)
        U.data[j][j] = 1;

    for (int j = 0; j < cols; j++)
    {
        for (int i = j; i < rows; i++)
        {
            double sum = 0;
            for (int k = 0; k < j; k++)
                sum += L.data[i][k] * U.data[k][j];
            L.data[i][j] = data[i][j] - sum;
        }

        for (int i = j; i < cols; i++)
        {
            double sum = 0;
            for (int k = 0; k < j; k++)
                sum += L.data[j][k] * U.data[k][i];
            U.data[j][i] = (data[j][i] - sum) / L.data[j][j];
        }
    }

    cout << "\nCrout - Lower Triangular Matrix (L):\n";
    L.display();
    cout << "\nCrout - Upper Triangular Matrix (U):\n";
    U.display();
}

void Matrix::luCholesky()
{
    if (!isDiagonallyDominant())
    {
        cout << "Matrix not suitable for Cholesky (may not be SPD).\n";
        return;
    }

    Matrix L(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double sum = 0;
            if (j == i)
            {
                for (int k = 0; k < j; k++)
                    sum += L.data[j][k] * L.data[j][k];
                L.data[j][j] = sqrt(data[j][j] - sum);
            }
            else
            {
                for (int k = 0; k < j; k++)
                    sum += L.data[i][k] * L.data[j][k];
                L.data[i][j] = (data[i][j] - sum) / L.data[j][j];
            }
        }
    }

    cout << "\nCholesky - Lower Triangular Matrix (L):\n";
    L.display();
    cout << "\nCholesky - Transpose (L^T):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << fixed << setprecision(2) << L.data[j][i] << " ";
        cout << endl;
    }
}

void Matrix::solve()
{
    cout << "Performing Gaussian Elimination...\n";

    for (int i = 0; i < rows; i++)
    {
        if (fabs(data[i][i]) < 1e-9)
        {
            for (int k = i + 1; k < rows; k++)
            {
                if (fabs(data[k][i]) > 1e-9)
                {
                    swap(data[i], data[k]);
                    break;
                }
            }
        }

        double pivot = data[i][i];
        for (int k = i; k < cols; k++)
            data[i][k] /= pivot;

        for (int j = i + 1; j < rows; j++)
        {
            double p = data[j][i];
            for (int k = i; k < cols; k++)
                data[j][k] -= p * data[i][k];
        }
    }

    for (int i = rows - 1; i >= 0; i--)
        for (int j = i + 1; j < rows; j++)
            data[i][cols - 1] -= data[i][j] * data[j][cols - 1];

    cout << "\nUpper Triangular Matrix:\n";
    display();
}

void Matrix::displaySolution()
{
    cout << "Solution:\n";
    for (int i = 0; i < rows; i++)
        cout << "x" << (i + 1) << " = " << fixed << setprecision(4) << data[i][cols - 1] << endl;
}

bool Matrix::isDiagonallyDominant()
{
    for (int i = 0; i < rows; i++)
    {
        double sum = 0;
        for (int j = 0; j < rows; j++)
        {
            if (i != j)
                sum += fabs(data[i][j]);
        }
        if (fabs(data[i][i]) < sum)
            return false;
    }
    return true;
}

void Matrix::gaussJacobi(int maxIterations, double tolerance)
{
    if (!isDiagonallyDominant())
    {
        cout << "Matrix is not diagonally dominant. Gauss-Jacobi might not converge.\n";
        return;
    }

    double *x = new double[rows]();     
    double *prev = new double[rows]();   

    cout << "\nGauss-Jacobi Iterations:\n";
    for (int it = 0; it < maxIterations; it++)
    {
        for (int i = 0; i < rows; i++)
        {
            double sum = 0;
            for (int j = 0; j < rows; j++)
            {
                if (j != i)
                    sum += data[i][j] * prev[j];
            }
            x[i] = (data[i][cols - 1] - sum) / data[i][i];
        }

        cout << "Iteration " << it + 1 << ": ";
        for (int i = 0; i < rows; i++)
        
        cout << fixed << setprecision(4) << x[i] << " ";
        cout << endl;

        for (int i = 0; i < rows; i++)
            prev[i] = x[i];  
    }
    cout << "\nFinal Solution using Gauss-Jacobi:\n";
    for (int i = 0; i < rows; i++)
        cout << "x" << (i + 1) << " = " << fixed << setprecision(4) << x[i] << endl;


    delete[] x;
    delete[] prev;
}


void Matrix::gaussSeidel(int maxIterations, double tolerance)
{
    if (!isDiagonallyDominant())
    {
        cout << "Matrix is not diagonally dominant. Gauss-Seidel might not converge.\n";
        return;
    }

    double *x = new double[rows]();

    for (int iter = 0; iter < maxIterations; iter++)
    {
        for (int i = 0; i < rows; i++)
        {
            double sum = data[i][cols - 1]; 
            for (int j = 0; j < rows; j++)
            {
                if (i != j)
                    sum -= data[i][j] * x[j];
            }
            x[i] = sum / data[i][i];
        }

        
        cout << "Iteration " << iter + 1 << ": ";
        for (int i = 0; i < rows; i++)
            cout << fixed << setprecision(4) << x[i] << " ";
        cout << endl;
    }

    cout << "\nFinal Solution using Gauss-Seidel:\n";
    for (int i = 0; i < rows; i++)
        cout << "x" << (i + 1) << " = " << fixed << setprecision(4) << x[i] << endl;

    delete[] x;
}

