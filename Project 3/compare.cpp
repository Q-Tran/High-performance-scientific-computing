//Van Tran

//includes
#include <chrono>
#include <ctime>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
using namespace std;
double Lagrange(Matrix& x, Matrix& y, double z);
Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);

int main() {
	std::chrono::time_point<std::chrono::system_clock> start, end;
	Matrix xmatrix;
	Matrix ymatrix;
	Matrix zmatrix;
	//lagrange
	for(int n = 10; n <= 80; n=n*2){ //repeat for n values
		xmatrix = Linspace(-2.0, 2.0, n+1, 1); //Create a set of (n + 1) evenly-spaced nodes, x, over the interval [−2, 2].
		ymatrix= Matrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){ //Create the set of function data values where y(i) = cosh(x^2/3).
			ymatrix(i) = cosh((xmatrix(i)*xmatrix(i))/3);
		}
		for(int m = 100; m <= 100000; m=m*10){ //repeat for m values
			zmatrix = Linspace(-2.0, 2.0, m+1, 1); //Create a set of (m + 1) evenly-spaced evaluation points z over the interval [−2, 2].
			start = std::chrono::system_clock::now(); //Measure and print out the time it takes to evaluate {p(zi) from i=0 to m.
    		//Evaluate lagrange(x,y)
    		for(int i = 0; i < zmatrix.Size(); i++){
    			Lagrange(xmatrix, ymatrix, zmatrix(i));
    		}
    		end = std::chrono::system_clock::now();
    		std::chrono::duration<double> elapsed_seconds = end-start;
    		std::cout << "finished lagrange evaluation of " << m << " points using interpolating polynomial of " << n << " points in "<< elapsed_seconds.count() << "s" << std::endl;
		}
	}
	//newton
	Matrix cmatrix;
	for(int n = 10; n <= 80; n=n*2){ //repeat for n values
		xmatrix = Linspace(-2.0, 2.0, n+1, 1); //Create a set of (n + 1) evenly-spaced nodes, x, over the interval [−2, 2].
		ymatrix = Matrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){ //Create the set of function data values where y(i) = cosh(x^2/3).
			ymatrix(i) = cosh(xmatrix(i)*xmatrix(i)/3);
		}
		start = std::chrono::system_clock::now();
		cmatrix = Newton_coefficients(xmatrix, ymatrix); //Create and time how long it takes to make coefficient matrix
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "finished newton coefficient evaluation of " << n << " points in " << elapsed_seconds.count() << "s" << std::endl;
		for(int m = 100; m <= 100000; m=m*10){ //repeat for m values
			zmatrix = Linspace(-2.0, 2.0, m+1, 1); //Create a set of (m + 1) evenly-spaced evaluation points z over the interval [−2, 2].
			start = std::chrono::system_clock::now(); //Measure and print out the time it takes to evaluate {p(zi) from i=0 to m.
    		//Evaluate lagrange(x,y)
    		for(int i = 0; i < zmatrix.Size(); i++){
    			Newton_evaluate(xmatrix, ymatrix, zmatrix(i));
    		}
    		end = std::chrono::system_clock::now();
    		std::chrono::duration<double> elapsed_seconds = end-start;
    		std::cout << "finished newton evaluation of " << m << " points using interpolating polynomial of " << n << " points in "<< elapsed_seconds.count() << "s" << std::endl;
		}
	}
}
