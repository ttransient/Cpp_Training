#include"Bus.h"
using namespace adas;
void Bus::Move(int step)noexcept {
    switch (status.heading) {
    case Direction::North: status.posY += step; break;
    case Direction::East: status.posX += step; break;
    case Direction::South: status.posY -= step; break;
    case Direction::West: status.posX -= step; break;
    }
}
void Bus::MoveForward() noexcept {
    int step = status.isFast ? 2 : 1;
    step = status.isReversing ? -step : step;
    Move(step);
}
void Bus::TurnLeft() noexcept {
    MoveForward();
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 3) % 4); // ��ʱ��ת��
    if (status.isReversing)
        status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 2) % 4);
}
void Bus::TurnRight() noexcept {
    MoveForward();
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 1) % 4); // ˳ʱ��ת��
    if (status.isReversing)
        status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 2) % 4);
}