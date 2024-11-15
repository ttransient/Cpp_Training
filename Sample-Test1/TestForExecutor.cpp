#include"pch.h"
#include"./Executor.h"
// 测试多个指令组合
TEST(ExecutorTest, ComplexCommands) {
    Executor executor(1, 1, Direction::East);
    executor.executeCommands("MMRMMMLMM");
    // 初始位置：(1, 1)，朝向：East
    // 'M' -> (2, 1)
    // 'M' -> (3, 1)
    // 'R' -> South
    // 'M' -> (3, 0)
    // 'M' -> (3, -1)
    // 'M' -> (3, -2)
    // 'L' -> East
    // 'M' -> (4, -2)
    // 'M' -> (5, -2)
    EXPECT_EQ(executor.getPosition(), std::make_pair(5, -2));
    EXPECT_EQ(executor.getHeading(), Direction::East);
}