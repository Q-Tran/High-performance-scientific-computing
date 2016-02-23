#include <iomanip>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol,bool show_iterates);

class fcn : public Fcn {
  double operator()(double x) {   // function evaluation
    return (x*(x-3)*(x+1));
  }
};

class fcnd : public Fcn {// function derivative evaluation
	double operator() (double x){
		return (3*x*x-4*x-3);
	}
};

int main(int argc, char* argv[]) {
  double x[3] = {-2, 1, 2};
  int maxit = 15;
  double tol[3] = {10e-1, 10e-5, 10e-9};
  fcn f;
  fcnd fd;
  for(int i = 0; i < 3; i++){ //iterates over x
    cout << "INITIAL guess: " << x[i] << endl;
    for(int a = 0; a < 3; a++){ // iterates over tol
      cout << "TOLERANCE: " << tol[a] << endl;
      cout << "The approximate root is: " << setprecision(16) << newton(f, fd, x[i], maxit, tol[a], false) << endl;
    } 
  }

}
