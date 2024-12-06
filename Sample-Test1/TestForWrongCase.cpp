#include"pch.h"
#include"./Executor.h"
// 测试无效指令
TEST(ExecutorTest, InvalidCommand) {
    Executor executor = Executor(0, 0, Direction::North);
    // 'X' 是无效指令，应该抛出 std::invalid_argument 异常
    EXPECT_THROW(executor.ExecuteCommands("X"), std::invalid_argument);
}