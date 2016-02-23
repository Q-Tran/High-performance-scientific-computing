/*Author: Van Tran
getconstants.cpp
11/25/15*/
#include <iostream>
#include <math.h>
//includes

using namespace std;
int main(){//gives me various constants in floating point precision so I can plug into programs for later
	cout.precision(17);
	cout << fixed << 128.0/225.0 << endl;
	cout << fixed <<(1.0/3.0) * sqrt(5.0 - 2.0*sqrt(10.0/7.0)) << endl;
	cout << fixed <<(1.0/3.0) * sqrt(5.0 + 2.0*sqrt(10.0/7.0)) << endl;
	cout << fixed <<(322.0 + 13.0*(sqrt(70.0)))/900.0 << endl;
	cout << fixed <<(322.0 - 13.0*(sqrt(70.0)))/900.0 << endl;
	cout << fixed << (2.0/sqrt(3.141592653589793238463)) << endl;
	return 0;
}
