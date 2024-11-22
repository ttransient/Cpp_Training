#include"pch.h"
#include"Executor.h"
// 测试前进指令 ('M') 向不同方向前进
TEST(ExecutorTest, MoveForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("M");
    // 朝向北，位置应该变为 (0, 1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 1));
}

TEST(ExecutorTest, MoveForwardSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommands("M");
    // 朝向南，位置应该变为 (0, -1)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, -1));
}

// 测试连续前进指令
TEST(ExecutorTest, MoveMultipleForwardNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("M");
    executor.executeCommands("M");
    executor.executeCommands("M");
    // 执行 3 次 'M' 后，位置应该变为 (0, 3)
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 3));
}


// 测试左转 ('L') 指令
TEST(ExecutorTest, TurnLeftFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("L");
    // 执行 'L' 后，朝向应该变为西
    EXPECT_EQ(executor.getHeading(), "West");
}

TEST(ExecutorTest, TurnLeftFromSouth) {
    Executor executor(0, 0, Direction::South);
    executor.executeCommands("L");
    // 执行 'L' 后，朝向应该变为东
    EXPECT_EQ(executor.getHeading(), "East");
}

// 测试右转 ('R') 指令
TEST(ExecutorTest, TurnRightFromNorth) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("R");
    // 执行 'R' 后，朝向应该变为东
    EXPECT_EQ(executor.getHeading(), "East");
}

TEST(ExecutorTest, TurnRightFromEast) {
    Executor executor(0, 0, Direction::East);
    executor.executeCommands("R");
    // 执行 'R' 后，朝向应该变为南
    EXPECT_EQ(executor.getHeading(), "South");
}

//加速状态下测试前行
TEST(ExecutorTest, FastMove) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("M");
    executor.executeCommands("M");
    // 执行 'R' 后朝向东，执行 'L' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 4));
    executor.executeCommands("F");
    executor.executeCommands("M");
    executor.executeCommands("M");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 6));
}
// 测试左转和右转连续执行
TEST(ExecutorTest, TurnLeftRightSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("R");
    executor.executeCommands("R");
    // 执行 'R' 后朝向南，位置为(1,1)
    EXPECT_EQ(executor.getHeading(), "South");
    EXPECT_EQ(executor.getPosition(), std::make_pair(1, 1));
}

TEST(ExecutorTest, TurnRightLeftSequence) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("F");
    executor.executeCommands("R");
    executor.executeCommands("L");
    // 执行 'R' 后朝向东，执行 'L' 后朝向北，应该恢复为原来朝向
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}

// 测试左转右转多次
TEST(ExecutorTest, TurnLeftMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("F");
    executor.executeCommands("L");
    executor.executeCommands("L");
    executor.executeCommands("L");
    executor.executeCommands("L");
    // 每次执行左转会改变朝向，4次左转后，应该恢复到原来的朝向，即北，位置不变
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}

TEST(ExecutorTest, TurnRightMultipleTimes) {
    Executor executor(0, 0, Direction::North);
    executor.executeCommands("R");
    executor.executeCommands("R");
    executor.executeCommands("R");
    executor.executeCommands("R");
    // 每次执行右转会改变朝向，4次右转后，应该恢复到原来的朝向，即北,位置不变
    EXPECT_EQ(executor.getHeading(), "North");
    EXPECT_EQ(executor.getPosition(), std::make_pair(0, 0));
}