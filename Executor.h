#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <string>
#include <utility>
// ���巽��ö��
enum class Direction {
    North = 0, // 'N'
    East = 1,  // 'E'
    South = 2, // 'S'
    West = 3   // 'W'
};
class Executor {
public:
    // ���캯����Ĭ�ϳ�ʼ��λ��Ϊ(0, 0) ����ΪNorth
    Executor(int x = 0, int y = 0, Direction heading = Direction::North);
    // ִ��һϵ��ָ��
    void executeCommands(const std::string& commands);
    // ��ȡ��ǰ��λ�ã�x, y��
    std::pair<int, int> getPosition();
    std::string getHeading();
private:
    int posX;
    int posY;
    Direction heading;
    bool isFast;
    // ת����ƶ��ĸ�������
    void moveForward();
    void turnLeft();
    void turnRight();
    //�ı����״̬
    void changeStatus();
    // ��ȡ��ǰ�ĳ���
    Direction Heading();
    // ִ��һ��ָ��
    void executeCommand(char command);
};
#endif // EXECUTOR_H
