#include <iostream>
#include "RootFinding.hpp"

using namespace std;



int main()
{
     RootFinding rfind;

    double a, b, tole;
    int max_iter;

   
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tole;
    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    
    double rootbisection = rfind.bisection(a, b, max_iter, tole);

    
        cout << "\n Root using Bisection: " << rootbisection << "\n";
   

   
    double x0, tol;
    int iter;
    RootFinding rf;
    cout << "Enter initial value for newton raphson: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter max iterations: ";
    cin >> iter;
    double root = rf.newtonRaphson(x0, tol, iter);
    cout << "\n Estimated Root: " << root << "\n";

    double x1, tolerance;
    int iterations;
    RootFinding rootf;
    cout << "Enter initial point: ";
    cin >> x1;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter max iterations: ";
    cin >> iterations;
    double rootfixed = rootf.fixedpoint(x1, tolerance, iterations);
    cout << "\nEstimated Root: " << rootfixed << "\n";




    return 0;
}
