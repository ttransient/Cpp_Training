#include<iostream>
#include"Executor.h"
#include"Runcar.h"
#include"Bus.h"
using namespace adas;
int main() {
	/*Executor vecihle=Executor();
	auto [x, y] = vecihle.GetPosition();
	std::cout << x << ' ' << y << std::endl;
	
	std::cout << vecihle.GetHeading() << std::endl;
	std::string inst = "MMBTRBFTR";
	vecihle.ExecuteCommands(inst);
	auto [a, b] = vecihle.GetPosition();
	std::cout << a << ' ' << b << std::endl;
	std::cout << vecihle.GetHeading() << std::endl;
	Runcar car = Runcar();
	std::cout << "car\n";
	std::string inst2 = "FBMLR";
	car.ExecuteCommands(inst2);
	auto [c, d] = car.GetPosition();
	std::cout << c << ' ' << d << std::endl;
	std::cout << car.GetHeading() << std::endl;*/
	std::cout << "Bus\n";
	Bus bus = Bus();
	std::string inst3 = "FBMLR";
	bus.ExecuteCommands(inst3);
	auto [i, j] = bus.GetPosition();
	std::cout << i << ' ' << j <<std::endl;
	std::cout << bus.GetHeading() << std::endl;
	return 0;
}