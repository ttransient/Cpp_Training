#include"pch.h"
#include"./Executor.h"
// ���Զ��ָ�����
TEST(ExecutorTest, ComplexCommands) {
    Executor executor(1, 1, Direction::East);
    executor.executeCommands("MFMLMRMFM");
    // ��ʼλ�ã�(1, 1)������East
    // 'M' -> (2, 1)
    // 'F' -> Fast=1
    // 'M' -> (4, 1)
    // 'L' -> North,(5,1)
    // 'M' -> (5, 3)
    // 'R' -> (5, 4),East
    // 'M' -> (7, 4)
    // 'F' -> Fast=0
    // 'M' -> (8, 4)

    EXPECT_EQ(executor.getPosition(), std::make_pair(8, 4));
    EXPECT_EQ(executor.getHeading(), "East");
}