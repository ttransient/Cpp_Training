#include "Executor.h"
#include <stdexcept>
#include <array>
#include <iostream>

// ����ת�����飬���ڼ�����ת����ת
const std::array<Direction, 4> directionArray = { Direction::North, Direction::East, Direction::South, Direction::West };

// ���캯������ʼ��λ�úͳ���
Executor::Executor(int x, int y, Direction heading) : posX(x), posY(y), heading(heading),isFast(false) {}
// ִ��һ��ָ��
void Executor::executeCommand(char command) {
    switch (command) {
    case 'M': moveForward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    case 'F':changeStatus(); break;
    default: throw std::invalid_argument("Invalid command. Only 'M', 'L', 'R' are allowed.");
    }
}
void Executor::changeStatus() {
    isFast = !isFast;
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
std::string Executor::getHeading() {
    Direction heading = Heading();
    std::string direction = (heading == Direction::North) ? "North" : 
        (heading == Direction::East) ? "East":
        (heading == Direction::South) ? "South" : 
        "West";
    return direction;
}
// ��ȡ��ǰ�ĳ���
Direction Executor::Heading(){
    return heading;
}
// ǰ��һ��
void Executor::moveForward() {
    int dis = (isFast) ? 2 : 1;
    switch (heading) {
    case Direction::North: posY += dis; break;
    case Direction::South: posY -= dis; break;
    case Direction::East:  posX += dis; break;
    case Direction::West:  posX -= dis; break;
    }
}
// ��ת
void Executor::turnLeft() {
    if (isFast) {
        changeStatus();
        moveForward();
        changeStatus();
    }
    heading = static_cast<Direction>((static_cast<int>(heading) + 3) % 4); // ��ʱ��ת��
}
// ��ת
void Executor::turnRight() {
    if (isFast) {
        changeStatus();
        moveForward();
        changeStatus();
    }
    heading = static_cast<Direction>((static_cast<int>(heading) + 1) % 4); // ˳ʱ��ת��
}
