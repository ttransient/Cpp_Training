#include"pch.h"
#include"./Executor.h"
// ���Զ��ָ�����
TEST(ExecutorTest, ComplexCommands) {
    Executor executor(1, 1, Direction::East);
    executor.executeCommands("MMRMMMLMM");
    // ��ʼλ�ã�(1, 1)������East
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