/*Author: Van Tran
application.cpp
11/25/15*/
#include "fcn.hpp"
#include <iostream>
//includes
double bisection(Fcn& f, double a, double b, int maxit, double tol,bool show_iterates); //used to solve root
double carbon(const double x, const double t, const double T, const double rtol, const double atol); //used in function declaration
//function declarations
using namespace std;

int main(){
	class fcn : public Fcn { //define abstract class
	public:
  		double operator()(double x) {   // function evaluation
    		return (carbon(0.003, 129600, x, 10e-14, 10e-15) - 0.006);
  		}
	};
	fcn f;
	cout.precision(17);
	cout << fixed << "The Temperature is: " << bisection(f, 671.0, 2000, 2000, 10e-14, 1) << "K" <<endl; //solve and print value solved
	cout << "start" << carbon(0.002, 129600, 961.26409681901213844, 10e-11, 10e-15) <<endl; //test whether value is correct
}
