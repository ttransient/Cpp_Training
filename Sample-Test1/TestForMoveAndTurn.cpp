#include"pch.h"
#include"Executor.h"
// ����ǰ��ָ�� ('M') ��ͬ����ǰ��
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('M');
    // ���򱱣�λ��Ӧ�ñ�Ϊ (0, 1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 1));
}

TEST(ExecutorTest, MoveForwardSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommand('M');
    // �����ϣ�λ��Ӧ�ñ�Ϊ (0, -1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, -1));
}

// ��������ǰ��ָ��
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('M');
    executor.executeCommand('M');
    executor.executeCommand('M');
    // ִ�� 3 �� 'M' ��λ��Ӧ�ñ�Ϊ (0, 3)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 3));
}


// ������ת ('L') ָ��
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), Direction::West);
}

TEST(ExecutorTest, TurnLeftFromSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommand('L');
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), Direction::East);
}

// ������ת ('R') ָ��
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), Direction::East);
}

TEST(ExecutorTest, TurnRightFromEast) {
    Executor executor(0, 0, Direction::East);
    executor.executeCommand('R');
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.getHeading(), Direction::South);
}


// ������ת����ת����ִ��
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    executor.executeCommand('R');
    // ִ�� 'L' ��������ִ�� 'R' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    executor.executeCommand('L');
    // ִ�� 'R' ���򶫣�ִ�� 'L' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

// ������ת��ת���
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    executor.executeCommand('L');
    executor.executeCommand('L');
    executor.executeCommand('L');
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼���
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    executor.executeCommand('R');
    executor.executeCommand('R');
    executor.executeCommand('R');
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼���
    EXPECT_EQ(executor.getHeading(), Direction::North);
}