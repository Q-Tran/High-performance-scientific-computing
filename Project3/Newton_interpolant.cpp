#include <iostream>
#include "matrix.hpp"

Matrix Newton_coefficients(Matrix& x, Matrix& y){ //returns vector of coefficients
	Matrix a(x.Size());
	if(x.Size()!=y.Size()){
		cout << "Newton error: the sizes of the two matrixes are not the same" << endl;
		return a;
	}
	for(int i = 0; i < x.Size(); i++){
		a(i) = //whatever you do to get coefficient
	}
}
double Newton_evaluate(Matrix& x, Matrix& c, double z){ //returns the newton method evaluated using vector of coefficients and vector of x values
	double v = x(0);
	for (int i = c.Size() - 1; i > 0; i--){
		v = v * (z - x(i)) + c(i);
	}
	return v;
}