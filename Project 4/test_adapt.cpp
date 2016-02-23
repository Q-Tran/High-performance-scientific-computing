/*Author: Van Tran
test_adapt.cpp
11/25/15*/
#include "fcn.hpp"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//includes

using namespace std;

class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};

int adaptive_int(Fcn& f, const double a, const double b, const double rtol,const double atol, double& R, int& n, int& Ntot);

int main(){//tests the adaptive_int function defined in adaptive_int.cpp
	double rtol[] = {10e-2, 10e-4, 10e-6, 10e-8, 10e-10, 10e-12};
	double atol[] = {rtol[0]/1000.0, rtol[1]/1000.0, rtol[2]/1000.0, rtol[3]/1000.0 , rtol[4]/1000.0, rtol[5]/1000.0};
  // limits of integration
	double a = -3.0;
	double b = 5.0;

	// integrand
	fcn f;
	f.c = 0.5;
	f.d = 25.0;
	double R;
	int n;
	int Ntot;
	double Itrue = f.antiderivative(b) - f.antiderivative(a);
  	printf("\n True Integral = %22.16e\n", Itrue);
  	int success;
  	cout.precision(17); //so prints without roundoff
	for(int i = 0; i < 6; i++){
	    success = adaptive_int(f, a, b, rtol[i], atol[i], R, n, Ntot);
	    if(success){
	    	cout << "SUCCESS" << endl;
	    }
	    cout << "Result: " << fixed << R << endl;
	    cout << scientific << "final number of subintervals: " << n << endl << "total number of subintervals calculated: " << Ntot << endl << "|I(f) - R(f)|: " << fabs(Itrue - R) << endl << "rtol|I(f)| + atol: " << rtol[i] * fabs(Itrue) + atol[i] << endl << endl;
	}
}

