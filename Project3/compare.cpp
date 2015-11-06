#include <chrono>
#include <ctime>
#include <iostream>
#include <math.h>
#include "matrix.hpp"
double Lagrange(Matrix& x, Matrix& y, double z);
Matrix Newton_coefficients(Matrix& x, Matrix& y);
double Newton_evaluate(Matrix& x, Matrix& c, double z);

int main(){
	std::chrono::time_point<std::chrono::system_clock> start, end;
	Matrix xmatrix;
	Matrix ymatrix;
	//lagrange
	for(int n = 10; n <= 80; n=n*2){
		xmatrix = Linspace(-2.0, 2.0, n+1);
		ymatrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){
			ymatrix(i) = cosh(xmatrix(i)*xmatrix(i)/3);
		}
    	start = std::chrono::system_clock::now();
    	//Evaluate lagrange(x,y)
    	lagrange()
    	end = std::chrono::system_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "finished lagrange" << n << " in " << elapsed_seconds.count() << "s" << endl;
	}

	for(int m = 0; m <= 100000; m=m*10){
		xmatrix = Linspace(-2.0, 2.0, m+1);
		ymatrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){
			ymatrix(i) = cosh(xmatrix(i)*xmatrix(i)/3);
		}
	    start = std::chrono::system_clock::now();
	    //Evaluate lagrange(x,y)
	    end = std::chrono::system_clock::now();
	    std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "finished lagrange" << m << " in " << elapsed_seconds.count() << "s" << endl;
	}
	//newton
	for(int n = 10; n <= 80; n=n*2){
		xmatrix = Linspace(-2.0, 2.0, n+1);
		ymatrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){
			ymatrix(i) = cosh(xmatrix(i)*xmatrix(i)/3);
		}
    	start = std::chrono::system_clock::now();
    	//Evaluate newton(x,y)
    	end = std::chrono::system_clock::now();
    	std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "finished newton" << n << " in " << elapsed_seconds.count() << "s" << endl;
	}

	for(int m = 0; m <= 100000; m=m*10){
		xmatrix = Linspace(-2.0, 2.0, m+1);
		ymatrix(xmatrix.Size());
		for(int i = 0; i < xmatrix.Size(); i++){
			ymatrix(i) = cosh(xmatrix(i)*xmatrix(i)/3);
		}
	    start = std::chrono::system_clock::now();
	    //Evaluate newton(x,y)
	    end = std::chrono::system_clock::now();
	    std::chrono::duration<double> elapsed_seconds = end-start;
    	std::cout << "finished newton" << m << " in " << elapsed_seconds.count() << "s" << endl;
	}
}