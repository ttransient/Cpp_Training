#ifndef RUNCAR_H
#define RUNCAR_H
#include"Executor.h"
using namespace adas;
class Runcar : public Executor {
public:
    // 使用跑车的加速方式
    Runcar(int x = 0, int y = 0, Direction heading = Direction::North)
        : Executor(x, y, heading) {}

protected:
    // 重写 MoveForward 方法，让跑车前进更快
    void Move(int step)noexcept;
    void MoveForward() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
};

#endif // 