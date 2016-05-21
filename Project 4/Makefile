###################################################################
# Van Tran
# Makefile for second part of independent project
###################################################################

# compiler & flags
CXX = g++
CXXFLAGS = -O2 -std=c++11
# makefile targets
all : test_Gauss2.exe test_int.exe test_adapt.exe getconstants.exe test_carbon.exe application.exe

test_Gauss2.exe : test_Gauss2.cpp composite_Gauss2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_int.exe : test_int.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_adapt.exe : test_adapt.cpp adaptive_int.cpp composite_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

getconstants.exe : getconstants.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

application.exe : application.cpp carbon.cpp adaptive_int.cpp composite_int.cpp bisection.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_carbon.exe : test_carbon.cpp carbon.cpp adaptive_int.cpp composite_int.cpp matrix.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
clean :
	\rm -f *.o *.txt

realclean : clean
	\rm -f *.exe *~


####### End of Makefile #######
