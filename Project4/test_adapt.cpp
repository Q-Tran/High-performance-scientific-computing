#include "fcn.hpp"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

int main(){
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
	for(int i = 0; i < 6; i++){
	    adaptive_int(f, a, b, rtol[i], atol[i], R, n, Ntot);
	    cout << "Result: " << R << endl << "final number of subintervals: " << n << endl << "total number of subintervals calculated: " << Ntot << endl << "|I(f) - R(f)|: " << fabs(Itrue - R) << endl << "rtol|I(f)| + atol: " << rtol[i] * fabs(Itrue) + atol[i] << endl;
	}
}

