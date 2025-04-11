#include <string>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    double **data;

public:
    Matrix(int r, int c);
    ~Matrix();

    void input(string &filename);
    void inputLU(string &filename);
    void inputAugmented(string &leftfile, string &rightfile);
    void inputIterative(string &filename);

    void display();

    Matrix add(Matrix &mat);
    Matrix sub(Matrix &mat);
    bool isIdentity();

    void luDecomposition();
    void luCrout();
    void luCholesky();

    void solve();
    void displaySolution();

    void gaussJacobi(int maxIterations, double tolerance);
    void gaussSeidel(int maxIterations, double tolerance);

    bool isDiagonallyDominant();
};
