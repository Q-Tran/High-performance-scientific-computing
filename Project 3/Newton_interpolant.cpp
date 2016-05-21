// Van Tran

// includes
#include <iostream>
#include "matrix.hpp"
Matrix Newton_coefficients(Matrix& x, Matrix& y){ //returns vector of coefficients
	if(x.Size()!= y.Size()){
		std::cerr << "Newton error: the sizes of the two matrixes are not the same" << std::endl;
		return Matrix(0,0);
	}
	else{
		Matrix coef(x.Size());
		for(int i = 0; i < coef.Size(); i++){
			coef(i) = y(i);
		}
		for(int i = 1; i < coef.Size(); i++){
			for(int a = coef.Size() - 1; a >= i; a--){
				coef(a) = (coef(a) - coef(a-1))/(x(a) - x(a-i));
			}
		}
		return coef;
	}
}

double Newton_evaluate(Matrix& x, Matrix& c, double z){ //returns the newton method evaluated using vector of coefficients and vector of x values
	double temp = c(c.Size()-1);
	for(int i = c.Size()-1; i >= 0; i--){
		temp = temp * (z-x(i)) + c(i);
	}
	return temp;
}
