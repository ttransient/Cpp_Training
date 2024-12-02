#include"pch.h"
#include"Executor.h"
// ����ǰ��ָ�� ('M') ��ͬ����ǰ��
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("M");
    // ���򱱣�λ��Ӧ�ñ�Ϊ (0, 1)
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 1));
}

TEST(ExecutorTest, MoveForwardSouth) {
    Executor executor(0, 0, Direction::South);
    executor.ExecuteCommands("M");
    // �����ϣ�λ��Ӧ�ñ�Ϊ (0, -1)
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, -1));
}

// ��������ǰ��ָ��
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    // ִ�� 3 �� 'M' ��λ��Ӧ�ñ�Ϊ (0, 3)
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 3));
}


// ������ת ('L') ָ��
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("L");
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.GetHeading(), "West");
}

TEST(ExecutorTest, TurnLeftFromSouth) {
    Executor executor(0, 0, Direction::South);
    executor.ExecuteCommands("L");
    // ִ�� 'L' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.GetHeading(), "East");
}

// ������ת ('R') ָ��
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("R");
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.GetHeading(), "East");
}

TEST(ExecutorTest, TurnRightFromEast) {
    Executor executor(0, 0, Direction::East);
    executor.ExecuteCommands("R");
    // ִ�� 'R' �󣬳���Ӧ�ñ�Ϊ��
    EXPECT_EQ(executor.GetHeading(), "South");
}

//����״̬�²���ǰ��
TEST(ExecutorTest, FastMove) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    // ִ�� 'R' ���򶫣�ִ�� 'L' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 4));
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 6));
}
// ������ת����ת����ִ��
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    // ִ�� 'R' �����ϣ�λ��Ϊ(1,1)
    EXPECT_EQ(executor.GetHeading(), "South");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(1, 1));
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("L");
    // ִ�� 'R' ���򶫣�ִ�� 'L' ���򱱣�Ӧ�ûָ�Ϊԭ������
    EXPECT_EQ(executor.GetHeading(), "North");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
}

// ������ת��ת���
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("L");
    executor.ExecuteCommands("L");
    executor.ExecuteCommands("L");
    executor.ExecuteCommands("L");
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼�����λ�ò���
    EXPECT_EQ(executor.GetHeading(), "North");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    // ÿ��ִ����ת��ı䳯��4����ת��Ӧ�ûָ���ԭ���ĳ��򣬼���,λ�ò���
    EXPECT_EQ(executor.GetHeading(), "North");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
}