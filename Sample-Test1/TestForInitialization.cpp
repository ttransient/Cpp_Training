#include "pch.h"
#include"./Executor.h"
TEST(ExecutorTest, Initialization) {
    Executor executor = Executor(0, 0, Direction::North);
    // ��ʼλ��Ӧ���� (0, 0)�������Ǳ�
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
    EXPECT_EQ(executor.GetHeading(), "North");
}