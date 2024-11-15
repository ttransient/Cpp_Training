#include"pch.h"
#include"Executor.h"
// 测试前进指令 ('M') 向不同方向前进
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('M');
    // 朝向北，位置应该变为 (0, 1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 1));
}

TEST(ExecutorTest, MoveForwardSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommand('M');
    // 朝向南，位置应该变为 (0, -1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, -1));
}

// 测试连续前进指令
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('M');
    executor.executeCommand('M');
    executor.executeCommand('M');
    // 执行 3 次 'M' 后，位置应该变为 (0, 3)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 3));
}


// 测试左转 ('L') 指令
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    // 执行 'L' 后，朝向应该变为西
    EXPECT_EQ(executor.getHeading(), Direction::West);
}

TEST(ExecutorTest, TurnLeftFromSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommand('L');
    // 执行 'L' 后，朝向应该变为东
    EXPECT_EQ(executor.getHeading(), Direction::East);
}

// 测试右转 ('R') 指令
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    // 执行 'R' 后，朝向应该变为东
    EXPECT_EQ(executor.getHeading(), Direction::East);
}

TEST(ExecutorTest, TurnRightFromEast) {
    Executor executor(0, 0, Direction::East);
    executor.executeCommand('R');
    // 执行 'R' 后，朝向应该变为南
    EXPECT_EQ(executor.getHeading(), Direction::South);
}


// 测试左转和右转连续执行
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    executor.executeCommand('R');
    // 执行 'L' 后朝向西，执行 'R' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    executor.executeCommand('L');
    // 执行 'R' 后朝向东，执行 'L' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

// 测试左转右转多次
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('L');
    executor.executeCommand('L');
    executor.executeCommand('L');
    executor.executeCommand('L');
    // 每次执行左转会改变朝向，4次左转后，应该恢复到原来的朝向，即北
    EXPECT_EQ(executor.getHeading(), Direction::North);
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommand('R');
    executor.executeCommand('R');
    executor.executeCommand('R');
    executor.executeCommand('R');
    // 每次执行右转会改变朝向，4次右转后，应该恢复到原来的朝向，即北
    EXPECT_EQ(executor.getHeading(), Direction::North);
}