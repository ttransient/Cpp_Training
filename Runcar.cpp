#include"Runcar.h"
using namespace adas;
void Runcar::Move(int step)noexcept {
    switch (status.heading) {
    case Direction::North: status.posY += step; break;
    case Direction::East: status.posX += step; break;
    case Direction::South: status.posY -= step; break;
    case Direction::West: status.posX -= step; break;
    }
}
void Runcar::MoveForward() noexcept {
    int step = status.isFast ? 4 : 2;
    step = status.isReversing ? -step : step;
    Move(step);
}
void Runcar::TurnLeft() noexcept {
    if (status.isFast&&!status.isReversing)Move(1);
    if (status.isFast && status.isReversing)Move(-1);
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 3) % 4); // 逆时针转动
    Move(1);
    if(status.isReversing)
        status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 2) % 4);
}
void Runcar::TurnRight() noexcept {
    if (status.isFast && !status.isReversing)Move(1);
    if (status.isFast && status.isReversing)Move(-1);
    status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 1) % 4); // 顺时针转动
    Move(1);
    if (status.isReversing)
        status.heading = static_cast<Direction>((static_cast<int>(status.heading) + 2) % 4);
}