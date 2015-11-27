#include <fstream>
#include <iostream>
double carbon(const double x, const double t, const double T, const double rtol, const double atol);
using namespace std;
int main(){
	ofstream Ttxt("Temp.txt");
	ofstream ttxt("time.txt");
	ofstream C2txt("C2mm.txt");
	ofstream C4txt("C4mm.txt");

	ofstream C2800txt("C2mm_800K.txt");
	ofstream C21000txt("C2mm_1000.txt");
	ofstream C21100txt("C2mm_24hour.txt");
	ofstream C21200txt("C2mm_1200.txt");

	ofstream C4800txt("C4mm_800K.txt");
	ofstream C41000txt("C4mm_1000.txt");
	ofstream C41100txt("C4mm_1100.txt");
	ofstream C41200txt("C4mm_1200.txt");

	int T[400];
	for(int i = 0; i < 400; i++){ //Temptxt
		T[i] = i + 400;
		Ttxt << T[i] << endl;
	}
	double t[600];
	double h = 47.0/600.0;
	for(int i = 0; i < 600; i++){//timetxt
		t[i] = 1+ i * h;
		ttxt << t[i] << endl;
	}
	double Cmm[400][600];
	for(int i = 0; i < 400; i++){ //C2mmtxt C4mmtxt
		for(int j = 0; j < 600; j++){
			C2txt << carbon(0.002, t[j], T[i], 10e-11, 10e-15) << endl;
			C4txt << carbon(0.004, t[j], T[i], 10e-11, 10e-15) << endl;
		}
	}

	for(int i = 0; i < 600; i++){ //everything else
		C2800txt << carbon(0.002, t[i], 800, 10e-11, 10e-15) << endl;
		C21000txt << carbon(0.002, t[i], 1000, 10e-11, 10e-15) << endl;
		C21100txt << carbon(0.002, t[i], 1100, 10e-11, 10e-15) << endl;
		C21200txt << carbon(0.002, t[i], 1200, 10e-11, 10e-15) << endl;

		C4800txt << carbon(0.004, t[i], 800, 10e-11, 10e-15) << endl;
		C41000txt << carbon(0.004, t[i], 1000, 10e-11, 10e-15) << endl;
		C41100txt << carbon(0.004, t[i], 1100, 10e-11, 10e-15) << endl;
		C41200txt << carbon(0.004, t[i], 1200, 10e-11, 10e-15) << endl;
	}

}