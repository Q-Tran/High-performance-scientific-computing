
#include "matrix.hpp"
double Lagrange2D(Matrix& x, Matrix& y, Matrix& z, double a, double b);

int main(){
	int n = 6;
	int m = n;
	Matrix x = Linspace(-4.0, 4.0, m+1, 1);
	Matrix y = Linspace(-4.0, 4.0, n+1, 1);
	Matrix f(x.Size(), y.Size());
	for(int i = 0; i < x.Size(); i++){
		for(int j = 0; j < y.Size(); j++){
			f(i, j) = 1/(1+(x(i)*x(i)) + (y(j)*y(j)));
		}
	}
	Matrix a = Linspace(-4.0, 4.0, 201, 1);
	a.Write("avals.txt");
	Matrix b = Linspace(-4.0, 4.0, 101, 1);
	b.Write("bvals.txt");
	Matrix p6(a.Size(), b.Size());
	for(int i = 0; i < a.Size(); i++){
		for(int j = 0; j < b.Size(); j++){
			p6(i, j) = Lagrange2D(x, y, f, a(i), b(j));
		}
	}
	p6matrix.Write("p6_uni.txt");

	n = 24
	m = n;
	Matrix x = Linspace(-4.0, 4.0, m+1, 1);
	Matrix y = Linspace(-4.0, 4.0, n+1, 1);
	for(int i = 0; i < x.Size(); i++){
		for(int j = 0; j < y.Size(); j++){
			f(i, j) = 1/(1+(x(i)*x(i)) + (y(j)*y(j)));
		}
	}
	Matrix p24(a.Size(), b.Size());
	for(int i = 0; i < a.Size(); i++){
		for(int j = 0; j < b.Size(); j++){
			p24(i, j) = Lagrange2D(x, y, f, a(i), b(j));
		}
	}
	p24.Write("p24_uni.txt");

	Matrix runge(201, 101);
	for(int i = 0; i < a.Size(); i++){
		for(int j = 0; j < b.Size(); j++){
			runge(i, j) = 1/(1+(a(i)*a(i)) + (b(j)*b(j)));
		}
	}
	//create runge matrix
	runge.Write("Runge.txt");



}