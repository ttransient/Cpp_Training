#include"pch.h"
#include"./Executor.h"
// ������Чָ��
TEST(ExecutorTest, InvalidCommand) {
    Executor executor(0, 0, Direction::North);
    // 'X' ����Чָ�Ӧ���׳� std::invalid_argument �쳣
    EXPECT_THROW(executor.executeCommand('X'), std::invalid_argument);
}