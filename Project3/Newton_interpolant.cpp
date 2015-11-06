#include <iostream>
#include "matrix.hpp"

Matrix Newton_coefficients(Matrix& x, Matrix& y){ //returns vector of coefficients
	Matrix coef(x.Size());
	if(x.Size()!=y.Size()){
		cout << "Newton error: the sizes of the two matrixes are not the same" << endl;
		return a;
	}
	else{
		for(int i = 0; i < coef.Size(); i++){
			coef(i) = y(i);
		}
		for(int i = 0; i < coef.Size(); i++{
			for(int a = coef.Size(); a > i; i--){
				coef(a) = (coef(a) -coef(a-1))/(x(a) - x(a-i));
			}
		}
		return coef;
	}
	for(int i = 0; i < x.Size(); i++){
		a(i) = //whatever you do to get coefficient
	}
}
double Newton_evaluate(Matrix& x, Matrix& c, double z){ //returns the newton method evaluated using vector of coefficients and vector of x values
	double temp = c(c.Size());
	for(int i = c.Size()-1; i > 0; i--){
		temp = temp * (z-x(i)) + c(i);
	}
	Newton_evaluate(x, c, z);
	return z; //book is odd
}