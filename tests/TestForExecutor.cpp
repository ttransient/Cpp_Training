#include <gtest/gtest.h>

#include "hello.h"
#include"Executor.h"
using namespace adas;
TEST(ExecutorTest, Initialization) {
    Executor executor = Executor(0, 0, Direction::North);
    // 初始位置应该是 (0, 0)，朝向是北
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
    EXPECT_EQ(executor.GetHeading(), "North");
}
TEST(ExecutorTest, ComplexCommands1) {
    Executor executor(1, 1, Direction::North);
    executor.ExecuteCommands("MFMLMRMFM");
    // 初始位置：(1, 1)，朝向：North
    // 'M' -> (2, 1)
    // 'F' -> Fast=1
    // 'M' -> (4, 1)
    // 'L' -> North,(5,1)
    // 'M' -> (5, 3)
    // 'R' -> (5, 4),East
    // 'M' -> (7, 4)
    // 'F' -> Fast=0
    // 'M' -> (8, 4)

    EXPECT_EQ(executor.GetPosition(), std::make_pair(-2, 8));
    EXPECT_EQ(executor.GetHeading(), "North");
}
TEST(ExecutorTest, ComplexCommands2) {
    Executor executor=Executor(0, 0, Direction::North);
    executor.ExecuteCommands("MBM");
    executor.ExecuteCommands("FMRBM");

    EXPECT_EQ(executor.GetPosition(), std::make_pair(2, -3));
    EXPECT_EQ(executor.GetHeading(), "East");
}
TEST(ExecutorTest, ComplexCommands3) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("MMBTRBFTR");
    // 初始位置：(0, 0)，朝向：North
    // 'M' -> (0, 1)
    // 'M' -> (0,2)
    // 'B' -> B=1
    // 'TR' -> (-1,2),South
    // 'B' -> B=0
    // 'F' -> F=1
    // 'TR' -> (0,1)North
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 1));
    EXPECT_EQ(executor.GetHeading(), "North");
}
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("M");
    // 朝向北，位置应该变为 (0, 1)
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 1));
}

// 测试连续前进指令
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    // 执行 3 次 'M' 后，位置应该变为 (0, 3)
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 3));
}


// 测试左转 ('L') 指令
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("L");
    // 执行 'L' 后，朝向应该变为西
    EXPECT_EQ(executor.GetHeading(), "West");
}

// 测试右转 ('R') 指令
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("R");
    // 执行 'R' 后，朝向应该变为东
    EXPECT_EQ(executor.GetHeading(), "East");
}

//加速状态下测试前行
TEST(ExecutorTest, FastMove) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    // 执行 'R' 后朝向东，执行 'L' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 4));
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("M");
    executor.ExecuteCommands("M");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 6));
}
// 测试左转和右转连续执行
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    // 执行 'R' 后朝向南，位置为(1,1)
    EXPECT_EQ(executor.GetHeading(), "South");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(1, 1));
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("F");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("L");
    // 执行 'R' 后朝向东，执行 'L' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.GetHeading(), "North");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
}

// 测试左转右转多次
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("L");
    executor.ExecuteCommands("L");
    executor.ExecuteCommands("R");
    executor.ExecuteCommands("R");
    // 每次执行左转会改变朝向，2次左转后,2次右转，应该恢复到原来的朝向，即北，位置不变
    EXPECT_EQ(executor.GetHeading(), "North");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(0, 0));
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor = Executor(0, 0, Direction::North);
    executor.ExecuteCommands("FTRMF");
    // 最后位置应为
    EXPECT_EQ(executor.GetHeading(), "South");
    EXPECT_EQ(executor.GetPosition(), std::make_pair(-1, -1));
}