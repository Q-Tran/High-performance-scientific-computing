CXX = g++
CXXFLAGS = -O -std=c++11

all : test_newton.exe test_fd_newton.exe kepler.exe

test_newton.exe : test_newton.cpp newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

test_fd_newton.exe : test_fd_newton.cpp fd_newton.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

kepler.exe : kepler.cpp newton.cpp matrix.o

matrix.o : matrix.cpp matrix.h

clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
