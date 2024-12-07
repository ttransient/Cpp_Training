#ifndef BUS_H
#define BUS_H
#include"Executor.h"
using namespace adas;
class Bus : public Executor {
public:
    // ʹ���ܳ��ļ��ٷ�ʽ
    Bus(int x = 0, int y = 0, Direction heading = Direction::North)
        : Executor(x, y, heading) {}

protected:
    // ��д MoveForward ���������ܳ�ǰ������
    void Move(int step)noexcept;
    void MoveForward() noexcept override;
    void TurnLeft() noexcept override;
    void TurnRight() noexcept override;
};
#endif // !BUS_H
