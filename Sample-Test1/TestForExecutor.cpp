#include"pch.h"
#include"./Executor.h"
// ���Զ��ָ�����
//TEST(ExecutorTest, ComplexCommands1) {
//    Executor executor(1, 1, Direction::North);
//    executor.ExecuteCommands("MFMLMRMFM");
//    // ��ʼλ�ã�(1, 1)������North
//    // 'M' -> (2, 1)
//    // 'F' -> Fast=1
//    // 'M' -> (4, 1)
//    // 'L' -> North,(5,1)
//    // 'M' -> (5, 3)
//    // 'R' -> (5, 4),East
//    // 'M' -> (7, 4)
//    // 'F' -> Fast=0
//    // 'M' -> (8, 4)
//
//    EXPECT_EQ(executor.GetPosition(), std::make_pair(8, 4));
//    EXPECT_EQ(executor.GetHeading(), "East");
//}
TEST(ExecutorTest, ComplexCommands2) {
    Executor executor(0, 0, Direction::North);
    executor.ExecuteCommands("MBM");
    executor.ExecuteCommands("FMRBM");
    // ��ʼλ�ã�(0, 0)������North
    // 'M' -> (0, 1)
    // 'B' -> B=1
    // 'M' -> (0, 0)
    // 'F' -> F=1
    // 'M' -> (0,-2)
    // 'R' -> (0,-3),East
    // 'B' -> B=0
    // 'M' -> (2,-3)

    EXPECT_EQ(executor.GetPosition(), std::make_pair(2, -3));
    EXPECT_EQ(executor.GetHeading(), "East");
}