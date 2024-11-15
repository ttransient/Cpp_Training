#include "Executor.h"
#include <stdexcept>
#include <array>
#include <iostream>

// 定义转向数组，用于计算左转和右转
const std::array<Direction, 4> directionArray = { Direction::North, Direction::East, Direction::South, Direction::West };

// 构造函数：初始化位置和朝向
Executor::Executor(int x, int y, Direction heading) : posX(x), posY(y), heading(heading) {}

// 执行一条指令
void Executor::executeCommand(char command) {
    switch (command) {
    case 'M': moveForward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    default: throw std::invalid_argument("Invalid command. Only 'M', 'L', 'R' are allowed.");
    }
}

// 执行一系列指令
void Executor::executeCommands(const std::string& commands) {
    for (char command : commands) {
        executeCommand(command);
    }
}

// 获取当前的位置（x, y）
std::pair<int,int> Executor::getPosition(){
    return std::make_pair(posX,posY);
}

// 获取当前的朝向
Direction Executor::getHeading(){
    return heading;
}

// 前进一格
void Executor::moveForward() {
    switch (heading) {
    case Direction::North: posY += 1; break;
    case Direction::South: posY -= 1; break;
    case Direction::East:  posX += 1; break;
    case Direction::West:  posX -= 1; break;
    }
}

// 左转
void Executor::turnLeft() {
    heading = static_cast<Direction>((static_cast<int>(heading) + 3) % 4); // 逆时针转动
}

// 右转
void Executor::turnRight() {
    heading = static_cast<Direction>((static_cast<int>(heading) + 1) % 4); // 顺时针转动
}
