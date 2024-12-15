#include<gtest/gtest.h>
#include"Runcar.h"
using namespace adas;
TEST(RuncarTest, complexInst1) {
    Runcar car = Runcar(0, 0, Direction::North);
    car.ExecuteCommands("MLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-1, 3));
}
TEST(RuncarTest, complexInst2) {
    Runcar car = Runcar(0, 0, Direction::North);
    car.ExecuteCommands("BMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-1, -3));
}
TEST(RuncarTest, complexInst3) {
    Runcar car = Runcar(0, 0, Direction::North);
    car.ExecuteCommands("FMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-2, 6));
}
TEST(RuncarTest, complexInst4) {
    Runcar car = Runcar(0, 0, Direction::North);
    car.ExecuteCommands("FBMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-2, -6));
}