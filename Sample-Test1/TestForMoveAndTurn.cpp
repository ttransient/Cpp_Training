#include"pch.h"
#include"Executor.h"
// ����ǰ��ָ�� ('M') ��ͬ����ǰ��
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("M");
    // ���򱱣�λ��Ӧ�ñ�Ϊ (0, 1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 1));
}

TEST(ExecutorTest, MoveForwardSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommands("M");
    // �����ϣ�λ��Ӧ�ñ�Ϊ (0, -1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, -1));
}

// ��������ǰ��ָ��
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("M");
    executor.executeCommands("M");
    executor.executeCommands("M");
    // ִ�� 3 �� 'M' ��λ��Ӧ�ñ�Ϊ (0, 3)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 3));
}


// ������ת ('L') ָ��
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("L");
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), "West");
}

TEST(ExecutorTest, TurnLeftFromSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommands("L");
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), "East");
}

// ������ת ('R') ָ��
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("R");
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), "East");
}

TEST(ExecutorTest, TurnRightFromEast) {
    Executor executor(0, 0, Direction::East);
    executor.executeCommands("R");
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), "South");
}

//����״̬�²���ǰ��
TEST(ExecutorTest, FastMove) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("M");
    executor.executeCommands("M");
    // ִ�� 'R' ���򶫣�ִ�� 'L' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 4));
    executor.executeCommands("F");
    executor.executeCommands("M");
    executor.executeCommands("M");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 6));
}
// ������ת����ת����ִ��
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("R");
    executor.executeCommands("R");
    // ִ�� 'R' �����ϣ�λ��Ϊ(1,1)
    EXPECT_EQ(executor.getHeading(), "South");
    EXPECT_EQ(executor.getPosition(), std::make_pair(1, 1));
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("F");
    executor.executeCommands("R");
    executor.executeCommands("L");
    // ִ�� 'R' ���򶫣�ִ�� 'L' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}

// ������ת��ת���
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("L");
    executor.executeCommands("L");
    executor.executeCommands("L");
    executor.executeCommands("L");
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼�����λ�ò���
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("R");
    executor.executeCommands("R");
    executor.executeCommands("R");
    executor.executeCommands("R");
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼���,λ�ò���
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}