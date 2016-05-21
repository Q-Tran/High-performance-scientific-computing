//Van Tran

//includes
#include <iostream>
#include <math.h>
#include "fcn.hpp"
//includes
int adaptive_int(Fcn& f, const double a, const double b, const double rtol, const double atol, double& R, int& n, int& Ntot); //function declaration from adaptive_int.cpp

class fcn : public Fcn {
public:
  double operator()(double x) {   //integral function
    return pow(2.71828182845904523536, (-1 * pow(x, 2)));
  }
};

fcn err;

double erfs(const double y, const double rtol, const double atol){
	double R = 0;
	int Ntot = 0, n = 0;
	return (1.12837916709551256 * R); //2/sqrt(pi) * integral
}

double carbon(const double x, const double t, const double T, const double rtol, const double atol){
	double Dt = 6.2e-7 * exp(-8e4/(8.31*T));
	double errorf = erfs(x/(2*sqrt(t*Dt)), rtol, atol);
	return (0.02 - (0.019 * errorf));
}


