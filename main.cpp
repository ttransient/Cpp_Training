#include<iostream>
#include"Executor.h"
int main() {
	Executor vecihle;
	auto [x, y] = vecihle.getPosition();
	std::cout << x << ' ' << y << std::endl;
	Direction heading = vecihle.getHeading();
	char directionChar = (heading == Direction::North) ? 'N': (heading == Direction::East) ? 'E'
		: (heading == Direction::South) ? 'S' : 'W';
	std::cout << directionChar << std::endl;
	return 0;
}