#include<iostream>
#include"Executor.h"
int main() {
	Executor vecihle;
	auto [x, y] = vecihle.GetPosition();
	std::cout << x << ' ' << y << std::endl;
	
	std::cout << vecihle.GetHeading() << std::endl;
	std::string inst = "MBRFMLM";
	vecihle.ExecuteCommands(inst);
	auto [a, b] = vecihle.GetPosition();
	std::cout << a << ' ' << b << std::endl;
	std::cout << vecihle.GetHeading() << std::endl;
	return 0;
}