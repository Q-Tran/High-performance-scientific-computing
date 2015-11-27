#include <iostream>
#include <math.h>
#include "fcn.hpp"

double composite_int(Fcn& f, const double a, const double b, const int n);
//f is function, a is lower bound of integral, b is uper bound of integral, rtol is, atol is, R is the double that the result is stored in, n is the int that shows the number of subintervals, Ntot is the total number of intervals used along the way
int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot){
	//find a way to compute the number of n given the rtolerance, atolerance, for now just add n by 10 untill it reaches 320
	double result;
	double bounder;
	int i = 10;
	int z = 0;
	int k = 4;
	while(i <= 160){
		result = composite_int(f, a, b, i);
		z = z + i;
		bounder = composite_int(f, a, b, i+k);
		i = i+10;
		z = z + i + k;
		if(fabs(result - bounder) < rtol*fabs(bounder) + atol){
			break;
		}
	}
	n = i;
	Ntot = z;
	R = result;
	return 1;
}
