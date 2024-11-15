#include "Executor.h"
#include <stdexcept>
#include <array>
#include <iostream>

// ����ת�����飬���ڼ�����ת����ת
const std::array<Direction, 4> directionArray = { Direction::North, Direction::East, Direction::South, Direction::West };

// ���캯������ʼ��λ�úͳ���
Executor::Executor(int x, int y, Direction heading) : posX(x), posY(y), heading(heading) {}

// ִ��һ��ָ��
void Executor::executeCommand(char command) {
    switch (command) {
    case 'M': moveForward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    default: throw std::invalid_argument("Invalid command. Only 'M', 'L', 'R' are allowed.");
    }
}

// ִ��һϵ��ָ��
void Executor::executeCommands(const std::string& commands) {
    for (char command : commands) {
        executeCommand(command);
    }
}

// ��ȡ��ǰ��λ�ã�x, y��
std::pair<int,int> Executor::getPosition(){
    return std::make_pair(posX,posY);
}

// ��ȡ��ǰ�ĳ���
Direction Executor::getHeading(){
    return heading;
}

// ǰ��һ��
void Executor::moveForward() {
    switch (heading) {
    case Direction::North: posY += 1; break;
    case Direction::South: posY -= 1; break;
    case Direction::East:  posX += 1; break;
    case Direction::West:  posX -= 1; break;
    }
}

// ��ת
void Executor::turnLeft() {
    heading = static_cast<Direction>((static_cast<int>(heading) + 3) % 4); // ��ʱ��ת��
}

// ��ת
void Executor::turnRight() {
    heading = static_cast<Direction>((static_cast<int>(heading) + 1) % 4); // ˳ʱ��ת��
}
