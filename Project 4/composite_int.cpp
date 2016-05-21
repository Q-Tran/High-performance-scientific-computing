//Van Tran

//includes
#include <iostream>
#include <math.h>
#include "fcn.hpp"
//includes
using namespace std;

//gaussian quadrature rule 4 for function f
double composite_int(Fcn& f, const double a, const double b, const int n){
  // check input arguments
  if (b < a) {
    cerr << "error: illegal interval, b < a\n";
    return 0.0;
  }
  if (n < 1) {
    cerr << "error: illegal number of subintervals, n < 1\n";
    return 0.0;
  }
   // set subinterval width
  double h = (b-a)/n;

  // set nodes/weights defining the quadrature method (within each subinterval)
  //gotten from getroots.cpp
  double x1 =0.0;
  double x2 = -0.53846931010568300;
  double x3 = 0.53846931010568300;
  double x4 = -0.90617984593866396;
  double x5 = 0.90617984593866396;

  double w1 =0.56888888888888889;
  double w2 =0.47862867049936647;
  double w3 =0.47862867049936647;
  double w4 =0.23692688505618908;
  double w5 =0.23692688505618908;

  // initialize result
  double F = 0.0;

  // loop over subintervals, accumulating result
  double xmid, node1, node2, node3, node4, node5;
  for (int i=0; i<n; i++) {
   
    // determine evaluation points within subinterval (basically scale so the nodes in gaussian rule are nodes in subinterval)
    xmid  = a + (i+0.5)*h;
    node1 = xmid + .5*h*x1;
    node2 = xmid + .5*h*x2;
    node3 = xmid + .5*h*x3;
    node4 = xmid + .5*h*x4;
    node5 = xmid + .5*h*x5;

    // add Gauss4 approximation on this subinterval to result
    F += w1*f(node1) + w2*f(node2) + w3*f(node3) + w4*f(node4) + w5*f(node5);

  } // end loop

  // return final result
  return (0.5*h*F);
}
