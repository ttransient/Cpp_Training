#include "pch.h"
#include"./Executor.h"
TEST(ExecutorTest, Initialization) {
    Executor executor(0, 0, Direction::North);
    // 初始位置应该是 (0, 0)，朝向是北
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
    EXPECT_EQ(executor.getHeading(), Direction::North);
}