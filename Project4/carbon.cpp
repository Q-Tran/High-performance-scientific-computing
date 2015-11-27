/*Author: Van Tran
Carbon.cpp
11/25/15*/
#include <iostream>
#include <math.h>
#include "fcn.hpp"

int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot);
//includes

class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   //integral function
    return pow(2.71828182845904523536, -1 * pow(x, 2));
  }
};

fcn err;

double erf(const double y, const double rtol, const double atol){
	double R;
	int Ntot, n;
	adaptive_int(err, 0, y, rtol, atol, R, n, Ntot);
	std::cout << R << std::endl;
	return (0.63661977236758138 * R); //2/sqrt(pi) * integral
}

double carbon(const double x, const double t, const double T, const double rtol, const double atol){
	return(0.02 - (0.019 * erf(x/sqrt(4.0*t*(6.2e-7 * exp(-8.0e4/(8.31*T))))) , rtol, atol));
}


