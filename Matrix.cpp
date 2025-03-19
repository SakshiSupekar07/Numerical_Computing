#include "Matrix.hpp"
#include <fstream>
#include <iomanip>

using namespace std;

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;

    data = new int *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new int[cols];
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    delete[] data;
}
void Matrix::input(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "File not found: " << filename << endl;
        return;
    }

    file >> rows >> cols;  
    cols = rows + 2; // Ensure augmented matrix has correct number of columns

    // Allocate memory for the matrix
    data = new int *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new int[cols];

    // Read matrix values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!(file >> data[i][j]))  // Check if reading fails
            {
                cout << "Error reading value at (" << i << ", " << j << ")\n";
                return;
            }
        }
    }

    file.close();
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

void Matrix::add(Matrix &m)
{
    if (rows != m.rows || cols != m.cols)
    {
        cout << "Matrix dimensions must match for addition.\n";
        return;
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] += m.data[i][j];
}

void Matrix::sub(Matrix &m)
{
    if (rows != m.rows || cols != m.cols)
    {
        cout << "Matrix dimensions must match for subtraction.\n";
        return;
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] -= m.data[i][j];
}

bool Matrix::isIdentity()
{
    if (rows != cols - 1) // Check only for square matrices (ignoring last column)
        return false;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++) // Ignore RHS column
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0))
                return false;

    return true;
}
void Matrix::solve()
{
    cout << "Performing Gaussian Elimination...\n";

    // Forward Elimination: Convert matrix to upper triangular form
    for (int i = 0; i < rows; i++)
    {
        // Ensure pivot is non-zero (swap if necessary)
        if (data[i][i] == 0)
        {
            bool swapped = false;
            for (int k = i + 1; k < rows; k++)
            {
                if (data[k][i] != 0) // Find a non-zero pivot
                {
                    swap(data[i], data[k]);  // Swap entire row pointers
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
            {
                cout << "Matrix is singular, cannot solve.\n";
                return;
            }
        }

        // Normalize pivot row (Make leading coefficient 1)
        double pivot = data[i][i];
        for (int k = i; k < cols; k++)
        {
            data[i][k] /= pivot;
        }

        // Eliminate elements below the pivot
        for (int j = i + 1; j < rows; j++)
        {
            double factor = data[j][i];
            for (int k = i; k < cols; k++)
            {
                data[j][k] -= factor * data[i][k];
            }
        }
    }

    // Printing the Upper Triangular Matrix
    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << fixed << setprecision(2) << data[i][j] << " ";
        cout << endl;
    }

    // Back Substitution: Store solution in the last column of data[][]
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < rows; j++)
        {
            data[i][cols - 1] -= data[i][j] * data[j][cols - 1];
        }
    }

    // Print the solution (Stored in last column)
    
}
void Matrix::displaySolution()
{
    cout << "Solution:\n";
    for (int i = 0; i < rows; i++)
        cout << "x" << (i + 1) << " = " << fixed << setprecision(2) << data[i][cols - 1] << endl;
}
