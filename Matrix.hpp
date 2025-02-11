#include<iostream>
class Matrix{
    private:
    int rows,cols;
    int **data;
    public:
    Matrix(int r,int c);
    ~Matrix();      
    void input();
    void display();
    Matrix add(Matrix &mat);
    Matrix sub(Matrix &mat);
    bool isIdentity();


};