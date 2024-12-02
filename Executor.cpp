#include "Executor.h"
#include <stdexcept>
#include <array>
#include <iostream>

// ����ת�����飬���ڼ�����ת����ת
const std::array<Direction, 4> directionArray = { Direction::North, Direction::East, Direction::South, Direction::West };

// ���캯������ʼ��λ�úͳ���
Executor::Executor(int x, int y, Direction heading) : status(x,y,heading) {}
//// ִ��һ��ָ��
//void Executor::ExecuteCommand(char command) noexcept {
//    switch (command) {
//    case 'M': MoveForward(); break;
//    case 'L': TurnLeft(); break;
//    case 'R': TurnRight(); break;
//    case 'F':ChangeStatus(); break;
//    case 'B':ChangeReverse(); break;
//    default: throw std::invalid_argument("Invalid command. Only 'M', 'L', 'R' are allowed.");
//    }
//}
//��ָ���Ϻ���ָ�룬������ָ�����Ͷ���֮��switch���ڸ���
//�����lambda���ʽ,this����ǰ�����ָ�룬����������ڵĺ���
void Executor::ExecuteCommand(char command)noexcept {
    std::unordered_map<char,std::function<void()>>cmderMap;
    cmderMap.emplace('M', [this] {MoveForward(); });
    cmderMap.emplace('L', [this] {TurnLeft(); });
    cmderMap.emplace('R', [this] {TurnRight(); });
    cmderMap.emplace('F', [this] {ChangeStatus(); });
    cmderMap.emplace('B', [this] {ChangeReverse(); });
    const auto it = cmderMap.find(command);
    if (it != cmderMap.end()) {
        it->second();
    }
    else throw std::invalid_argument("Invalid command. Only 'M', 'L', 'R' are allowed.");
}
void Executor::ChangeStatus() noexcept {
    status.isFast = !status.isFast;
}
void Executor::ChangeReverse() noexcept {
    status.isReversing = !status.isReversing;
}
// ִ��һϵ��ָ��
void Executor::ExecuteCommands (const std::string& commands)noexcept {
    for (char command : commands) {
        ExecuteCommand(command);
    }
}
// ��ȡ��ǰ��λ�ã�x, y��
std::pair<int,int> Executor::GetPosition()noexcept{
    return std::make_pair(status.posX,status.posY);
}
std::string Executor::GetHeading() noexcept {
    Direction heading = Heading();
    std::string direction = (heading == Direction::North) ? "North" : 
        (heading == Direction::East) ? "East":
        (heading == Direction::South) ? "South" : "West";
    return direction;
}
// ��ȡ��ǰ�ĳ���
Direction Executor::Heading()noexcept {
    return status.heading;
}
// ǰ��һ��--�ƶ�һ��
void Executor::MoveForward() noexcept {
    int dis = (status.isFast) ? 2 : 1;
    dis = (status.isReversing) ? -dis : dis;
    switch (status.heading) {
    case Direction::North: status.posY += dis; break;
    case Direction::South: status.posY -= dis; break;
    case Direction::East:  status.posX += dis; break;
    case Direction::West:  status.posX -= dis; break;
    }
}
// ��ת
void Executor::TurnLeft()noexcept {
    if (status.isFast) {
        ChangeStatus();
        MoveForward();
        ChangeStatus();
    }
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 3) % 4); // ��ʱ��ת��
}
// ��ת
void Executor::TurnRight() noexcept {
    if (status.isFast) {
        ChangeStatus();
        MoveForward();
        ChangeStatus();
    }
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 1) % 4); // ˳ʱ��ת��
}
