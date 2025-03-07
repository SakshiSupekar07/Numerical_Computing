
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class GaussianElimination {
private:
    float** mat;          
    float* solution;      
    int rows, cols;       

public:
                            
    void acceptMatrix(string &filename);  
    void solve();                                 
    void displaySolution();   
    void freeMatrix();                   
};


