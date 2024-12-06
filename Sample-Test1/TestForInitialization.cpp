#include "pch.h"
#include"./Executor.h"
TEST(ExecutorTest, Initialization) {
    Executor executor = Executor(0, 0, Direction::North);
    // 初始位置应该是 (0, 0)，朝向是北
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
    EXPECT_EQ(executor.GetHeading(), "North");
}