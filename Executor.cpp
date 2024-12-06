#include "Executor.h"
#include <stdexcept>
#include <array>
#include <iostream>

// 定义转向数组，用于计算左转和右转
const std::array<Direction, 4> directionArray = { Direction::North, Direction::East, Direction::South, Direction::West };

// 构造函数：初始化位置和朝向
//cmderMap作为成员变量，减少重复创建map带来的不必要开销
Executor::Executor(int x, int y, Direction heading) : status(x,y,heading) {
    cmderMap.emplace('M', [this] {MoveForward(); });
    cmderMap.emplace('L', [this] {TurnLeft(); });
    cmderMap.emplace('R', [this] {TurnRight(); });
    cmderMap.emplace('F', [this] {ChangeStatus(); });
    cmderMap.emplace('B', [this] {ChangeReverse(); });
    cmderMap.emplace('T', [this] {TurnRonud(); });
}
//Executor& Executor::GetInstance(int x, int y, Direction heading) {
//    static Executor instance(x, y, heading);
//    return instance;
//}
//// 执行一条指令
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
//将指令结合函数指针，避免了指令类型多了之后switch过于复杂
//结合了lambda表达式,this捕获当前对象的指针，允许访问类内的函数
void Executor::ExecuteCommand(char command) {
    const auto it = cmderMap.find(command);
    if (it != cmderMap.end()) {
        it->second();
    }
    else throw std::invalid_argument("Invalid command.");
}
void Executor::ChangeStatus() noexcept {
    status.isFast = !status.isFast;
}
void Executor::ChangeReverse() noexcept {
    status.isReversing = !status.isReversing;
}
// 执行一系列指令
void Executor::ExecuteCommands (const std::string& commands){
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == 'T') {
            if (i != commands.size() - 1 && commands[i + 1] == 'R')
                ExecuteCommand(commands[i++]);
            else throw std::invalid_argument("Invalid commands");
        }
        else ExecuteCommand(commands[i]);
    }
}
// 获取当前的位置（x, y）
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
// 获取当前的朝向
Direction Executor::Heading()noexcept {
    return status.heading;
}
// 前进一格--移动一格
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
// 左转
void Executor::TurnLeft()noexcept {
    if (status.isFast) {
        ChangeStatus();
        MoveForward();
        ChangeStatus();
    }
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 3) % 4); // 逆时针转动
}
// 右转
void Executor::TurnRight() noexcept {
    if (status.isFast) {
        ChangeStatus();
        MoveForward();
        ChangeStatus();
    }
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 1) % 4); // 顺时针转动
}
//掉头指令
void Executor::TurnRonud()noexcept {
    bool flag = 0;
    if (status.isReversing)flag = 1, ChangeReverse();
    TurnLeft();
    if (!status.isFast)MoveForward();
    TurnLeft();
    if (flag)ChangeReverse();
}
