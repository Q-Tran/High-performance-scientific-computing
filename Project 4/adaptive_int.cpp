/*Author: Van Tran
adaptive_int.cpp
11/25/15*/
#include <iostream>
#include <math.h>
#include "fcn.hpp"
//includes
double composite_int(Fcn& f, const double a, const double b, const int n);
//f is function, a is lower bound of integral, b is uper bound of integral, rtol is, atol is, R is the double that the result is stored in, n is the int that shows the number of subintervals, Ntot is the total number of intervals used along the way
int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot){
	double bounder;
	int i = 20; //current number of intervals
	int z = 0; //total number of intervals
	double result = composite_int(f, a, b, i);
	z = z+i;
	while(i <= 80){ //never let loop call composite_int with i > 160
		i = i*2;
		result = composite_int(f,a,b, i);
		z = z+i;
		bounder = composite_int(f, a, b, i+1);
		z =z+i+1;
		if(fabs(result - bounder) < rtol*fabs(bounder) + atol){
			n = i;
			Ntot = z;
			R = result;
			return 1; //success!
		}
	}
	n = i;
	Ntot = z;
	R = result;
	return 0; //failure because R(f) does not satisfy its boundary conditions
}
