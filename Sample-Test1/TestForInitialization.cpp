#include "pch.h"
#include"./Executor.h"
TEST(ExecutorTest, Initialization) {
    Executor executor(0, 0, Direction::North);
    // ��ʼλ��Ӧ���� (0, 0)�������Ǳ�
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
    EXPECT_EQ(executor.getHeading(), Direction::North);
}