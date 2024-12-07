#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <string>
#include<unordered_map>
#include<functional>
#include<Memory>
#include <utility>
// ���巽��ö��
namespace adas{
enum class Direction {
    North = 0, // 'N'
    East = 1,  // 'E'
    South = 2, // 'S'
    West = 3   // 'W'
};
struct Status {
    int posX;
    int posY;
    Direction heading;
    bool isFast;//F
    bool isReversing;//B
    Status(int x, int y, Direction heading) :
        posX(x), posY(y), heading(heading), isFast(false), isReversing(false) {};
};
class Executor {
public:
    // ���캯����Ĭ�ϳ�ʼ��λ��Ϊ(0, 0) ����ΪNorth
    Executor(int x = 0, int y = 0, Direction heading = Direction::North);
    // ִ��һϵ��ָ��
    void ExecuteCommands(const std::string& commands);
    // ��ȡ��ǰ��λ�ã�x, y��
    std::pair<int, int> GetPosition()noexcept;
    std::string GetHeading()noexcept;
protected:
    Status status;
    std::unordered_map<char, std::function<void()>>cmderMap;
    // ת����ƶ��ĸ�������
    virtual void MoveForward()noexcept;
    virtual void TurnLeft()noexcept;
    virtual void TurnRight()noexcept;
    //�ı����״̬
    void ChangeStatus()noexcept;
    //�ı䵹��״̬
    void ChangeReverse()noexcept;
    // ��ȡ��ǰ�ĳ���
    Direction Heading()noexcept;
    // ִ��һ��ָ��
    void ExecuteCommand(char command);
    void TurnRonud()noexcept;
};
}
#endif // EXECUTOR_H
