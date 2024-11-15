#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <string>
#include <utility>
// 定义方向枚举
enum class Direction {
    North = 0, // 'N'
    East = 1,  // 'E'
    South = 2, // 'S'
    West = 3   // 'W'
};
class Executor {
public:
    // 构造函数：默认初始化位置为(0, 0) 朝向为North
    Executor(int x = 0, int y = 0, Direction heading = Direction::North);
    // 执行一条指令
    void executeCommand(char command);
    // 执行一系列指令
    void executeCommands(const std::string& commands);
    // 获取当前的位置（x, y）
    std::pair<int, int> getPosition();
    // 获取当前的朝向
    Direction getHeading();
private:
    int posX;
    int posY;
    Direction heading;

    // 转向和移动的辅助函数
    void moveForward();
    void turnLeft();
    void turnRight();
};
#endif // EXECUTOR_H
