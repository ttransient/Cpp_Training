#ifndef RUNCAR_H
#define RUNCAR_H
#include"Executor.h"
using namespace adas;
class Runcar : public Executor {
public:
    // ʹ���ܳ��ļ��ٷ�ʽ
    Runcar(int x = 0, int y = 0, Direction heading = Direction::North)
        : Executor(x, y, heading) {}

protected:
    // ��д MoveForward ���������ܳ�ǰ������
    void Move(int step)noexcept;
    void MoveForward() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
};

#endif // !RUNCAR_H
