/*Author: Van Tran
test_carbon.cpp
11/25/15*/
#include <fstream>
#include <iostream>
#include <iomanip> //for setprecision
#include "matrix.hpp"
//includes
double carbon(const double x, const double t, const double T, const double rtol, const double atol); //function declaration from carbon.cpp
using namespace std;
int main(){
	Matrix T(400);
	for(int i = 0; i < 400; i++){ //Temptxt
		T(i) = i + 800;
	}
	T.Write("Temp.txt");
	Matrix t(600);
	double h = 172799.0/600.0;
	for(int i = 0; i < 600; i++){//timetxt
		t(i) = 1+ i * h;
	}
	t.Write("time.txt");
	Matrix C2mm(400, 600);
	Matrix C4mm(400, 600);
	for(int i = 0; i < 400; i++){ //C2mmtxt C4mmtxt
		for(int j = 0; j < 600; j++){
			C2mm(i, j) = carbon(0.002, t(j), T(i), 10e-11, 10e-15);
			C4mm(i, j) = carbon(0.004, t(j), T(i), 10e-11, 10e-15);
		}
	}
	C2mm.Write("C2mm.txt");
	C4mm.Write("C4mm.txt");
	Matrix test(2000);
	for(int i = 0; i < 2000; i++){
		test(i) = carbon(0.003, 129600, i, 10e-11, 10e-15);
	}
	test.Write("test.txt");

	Matrix C2800;
	Matrix C2900;
	Matrix C21000;
	Matrix C21100;
	Matrix C21200;

	Matrix C4800;
	Matrix C4900;
	Matrix C41000;
	Matrix C41100;
	Matrix C41200;
	
	for(int i = 0; i < 600; i++){ //everything else
		C2800(i) = carbon(0.002, t(i), 800, 10e-11, 10e-15);
		C2900(i) = carbon(0.002, t(i), 900, 10e-11, 10e-15);
		C21000(i) = carbon(0.002, t(i), 1000, 10e-11, 10e-15);
		C21100(i) = carbon(0.002, t(i), 1100, 10e-11, 10e-15);
		C21200(i) = carbon(0.002, t(i), 1200, 10e-11, 10e-15);

		C4800(i) = carbon(0.004, t(i), 800, 10e-11, 10e-15);
		C4900(i) = carbon(0.004, t(i), 900, 10e-11, 10e-15);
		C41000(i) = carbon(0.004, t(i), 1000, 10e-11, 10e-15);
		C41100(i) = carbon(0.004, t(i), 1100, 10e-11, 10e-15);
		C41200(i) = carbon(0.004, t(i), 1200, 10e-11, 10e-15);
	}
	C2800.Write("C2mm_800K.txt");
	C2900.Write("C2mm_900K.txt");
	C21000.Write("C2mm_1000.txt");
	C21100.Write("C2mm_24hour.txt");
	C21200.Write("C2mm_1200.txt");

	C4800.Write("C4mm_800K.txt");
	C4900.Write("C4mm_900K.txt");
	C41000.Write("C4mm_1000.txt");
	C41100.Write("C4mm_1100.txt");
	C41200.Write("C4mm_1200.txt");

}