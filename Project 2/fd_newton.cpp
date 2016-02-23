#include "fcn.hpp"
#include <math.h>
#include <iostream>
using namespace std;

double fd_newton(Fcn& f, double x, int maxit, double tol, double alpha, bool show_iterates){
 // returns the root of the function using newton's method. Algorithm taken from the book.
	//check input
	if(maxit < 0){
		cout << "cannot have negative iterations. Setting to 0 iterations." << endl;
		maxit = 0;
	} 
  	if (tol < 1.e-15){ //taken from Daniel R. Reynolds
    	cerr << "warning: tol is too small, resetting to 1e-15" << endl;
    	tol = 1.e-15;
	}
	//initialize newton variables
	double d;
	double fx;
	double fp;
	double e;
	double o;
	fx = f(x);
	for(int i = 0; i <= maxit; i++){ //makes sure that the newton method doesn't run infinitely.
		fp = (f(x + alpha) - f(x))/alpha; //instead of this use derivative approximation.
		d = fx/fp;
		if(tol > fabs(d)){
			cout << "ERROR answer holds no significance. exceeds tolerance ." << endl;
			break;
		}
		x = x-d;
		fx = f(x);
		if(show_iterates){
			cout << "Iterations: " << i << endl << "f(x)/ dpf'(x) = " << d << endl << "new guess: " << x << endl;
		}
	}
	return x;
}
