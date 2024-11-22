#include<iostream>
#include"Executor.h"
int main() {
	Executor vecihle;
	auto [x, y] = vecihle.getPosition();
	std::cout << x << ' ' << y << std::endl;
	
	std::cout << vecihle.getHeading() << std::endl;
	std::string inst = "MMMMLM";
	vecihle.executeCommands(inst);
	auto [a, b] = vecihle.getPosition();
	std::cout << a << ' ' << b << std::endl;
	std::cout << vecihle.getHeading() << std::endl;
	return 0;
}