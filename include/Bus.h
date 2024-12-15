#ifndef BUS_H
#define BUS_H
#include "Executor.h"
using namespace adas;
class Bus : public Executor
{
public:
    // 使用跑车的加速方式
    Bus(int x = 0, int y = 0, Direction heading = Direction::North) : Executor(x, y, heading)
    {
    }

protected:
    // 重写 MoveForward 方法，让跑车前进更快
    void Move(int step) noexcept;
    void MoveForward() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
};
#endif  // !BUS_H