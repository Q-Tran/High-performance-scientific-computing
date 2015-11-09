###################################################################
#  Makefile for project 3
#
#  Van Tran
#  Math 3316
#  11/7/15
#  NOTE I TOOK OUT THE OPTIMIZATION FLAGS TO MAKE SURE THE CODE COMPILED WAS EXACTLY REPRESENTATIVE OF THE CODE CREATED
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -std=c++11

# makefile targets
all : test_Lagrange.exe test_Newton.exe compare.exe test_Lagrange2D.exe Runge_uniform.exe Runge_Chebyshev.exe

test_Lagrange.exe : Lagrange.cpp test_Lagrange.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Lagrange2D.exe : test_Lagrange2D.cpp Lagrange2D.cpp Lagrange.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

compare.exe : compare.cpp matrix.cpp Newton_interpolant.cpp Lagrange.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_Newton.exe : Newton_interpolant.cpp test_Newton.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Runge_uniform.exe : Runge_uniform.cpp matrix.cpp Lagrange2D.cpp Lagrange.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Runge_Chebyshev.exe : Runge_Chebyshev.cpp matrix.cpp Lagrange2D.cpp Lagrange.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
