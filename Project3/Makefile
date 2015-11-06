###################################################################
#  Makefile for interpolation demo
#
#  Daniel R. Reynolds
#  SMU Mathematics
#  Math 3316
#  30 September 2015
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11

# makefile targets
demo.exe : Lagrange.cpp Vandermonde.cpp matrix.cpp demo.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
