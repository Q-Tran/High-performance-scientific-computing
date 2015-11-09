//Van Tran
//11/9/15

//includes
#include "matrix.hpp"
double Lagrange_basis(Matrix& x, int i, double z);

double Lagrange2D(Matrix& x, Matrix& y, Matrix& f, double a, double b){
	double p = 0.0;

	for(int i = 0; i<x.Size() ;i++){
		for(int j = 0; j<y.Size() ;j++){
			p += f(i, j) + Lagrange_basis(x, i, a) * Lagrange_basis(y, j, b);
		}
	}
	return p;
}
