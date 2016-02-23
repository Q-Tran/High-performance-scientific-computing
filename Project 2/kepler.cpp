#include <iostream>
#include "fcn.hpp"
#include <math.h>
#include "matrix.hpp"
using namespace std;

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol,bool show_iterates);

class fcn : public Fcn {
	double operator()(double x) {   // function of kepler
		return (sqrt(1- 1.5625/4)*sin(x) - x - time);
  	}
};

class fcnd : public Fcn {
	double operator()(double x) { // derivative of kepler
		return(sqrt(1- 1.5625/4)*cos(x) - 1);
	}
};

int main(){
	cout << "initializing Matrixes" << endl;
	Matrix t(1,10001);
	Matrix x(1,10001);
	Matrix y(1,10001);
	fcn f;
	fcnd fd;
	double r;
	double w = 0.0;
	double theTime = 0;
	cout << "writing to Matrixes" << endl;
	for(int i = 0; i <= 10000; i++){ //evaluate newton at previous w and write
		//write i to t
		t(0,i) = theTime;
		f.time = theTime;
		w = newton(f, fd, w, 6, 10e-5, 0);
		cout << w << endl;
		
		r = 2.5/sqrt((1.25*cos(w))*1.25*cos(w) + 2.0*sin(w) * 2.0*sin(w));
		x(0,i) = r*cos(w);
		y(0,i) = r*sin(w);
		theTime = theTime + .001;
	}
	cout << "writing to files" << endl;
	t.Write("t.txt");
	x.Write("x.txt");
	y.Write("y.txt");

}