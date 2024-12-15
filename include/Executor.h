#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <Memory>
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
// 定义方向枚举
namespace adas
{
enum class Direction {
    North = 0,  // 'N'
    East = 1,   // 'E'
    South = 2,  // 'S'
    West = 3    // 'W'
};
struct Status {
    int posX;
    int posY;
    Direction heading;
    bool isFast;       // F
    bool isReversing;  // B
    Status(int x, int y, Direction heading) : posX(x), posY(y), heading(heading), isFast(false), isReversing(false) {};
};
class Executor
{
public:
    // 构造函数：默认初始化位置为(0, 0) 朝向为North
    Executor(int x = 0, int y = 0, Direction heading = Direction::North);
    // 执行一系列指令
    void ExecuteCommands(const std::string& commands);
    // 获取当前的位置（x, y）
    std::pair<int, int> GetPosition() noexcept;
    std::string GetHeading() noexcept;
    virtual ~Executor();  // 增加一个虚析构函数，避免基类操作删除子类
protected:
    Status status;
    std::unordered_map<char, std::function<void()>> cmderMap;
    // 转向和移动的辅助函数
    virtual void MoveForward() noexcept;
    virtual void TurnLeft() noexcept;
    virtual void TurnRight() noexcept;
    // 改变加速状态
    void ChangeStatus() noexcept;
    // 改变倒车状态
    void ChangeReverse() noexcept;
    // 获取当前的朝向
    Direction Heading() noexcept;
    // 执行一条指令
    void ExecuteCommand(char command);
    void TurnRonud() noexcept;
};
}  // namespace adas
#endif  // EXECUTOR_H