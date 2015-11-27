#include <iostream>
#include "matrix.hpp"
int main(){
	Matrix a = Linspace(0.0, 5.0, 5, 1);
	for(int i = 0; i < a.Size(); i++)
		std::cout << a(i) << std::endl;
}