#include <iostream>
#include <string>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;
   
    

public:
    Matrix(int r, int c);
    ~Matrix();
    void input(string &filename);
    void display();
   void add(Matrix &mat);
  void sub(Matrix &mat);
    bool isIdentity();
    void solve();
    void displaySolution();
    
    
      
};
