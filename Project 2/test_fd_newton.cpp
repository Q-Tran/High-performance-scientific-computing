#include <iomanip>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

double fd_newton(Fcn& f, double x, int maxit, double tol, double alpha, bool show_iterates);

class fcn : public Fcn {
  double operator()(double x) {   // function evaluation
    return (x*(x-3)*(x+1));
  }
};

int main(int argc, char* argv[]) {
  double x[3] = {-2, 1, 2};
  int maxit = 20;
  double tol[3] = {10e-1, 10e-5, 10e-9};
  fcn f;
  double alpha[3] = {2e-4, 2e-26, 2e-50};
  for(int i = 0; i < 3; i++){ //x
    cout << "INITIAL guess: " << x[i] << endl;
    for(int a = 0; a < 3; a++){ //tol
      cout << "TOLERANCE: " << tol[a] << endl;
      for (int b = 0; b < 3; b++){ // alpha
        cout << "The approximate root is: " << setprecision(16) << fd_newton(f, x[i], maxit, tol[a], alpha[b], false) << endl;
      }
    } 
  } 
}
