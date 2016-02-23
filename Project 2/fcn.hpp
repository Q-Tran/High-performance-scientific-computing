#ifndef FCN_DEFINED__
#define FCN_DEFINED__


// Fcn class
class Fcn {
public:
	double time;
	void setTime(double a){
		time = a;
	}
	double getTime(){
		return time;
	}
 	// pure virtual function makes this an 'abstract' base class
  	virtual double operator()(double x) = 0;

};

#endif  // FCN_DEFINED__
