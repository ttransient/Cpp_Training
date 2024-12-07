#include"pch.h"
#include"Bus.h"
using namespace adas;
TEST(BusTest, complexInst1) {
    Bus car = Bus(0, 0, Direction::North);
    car.ExecuteCommands("MLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-1, 2));
}
TEST(BusTest, complexInst2) {
    Bus car = Bus(0, 0, Direction::North);
    car.ExecuteCommands("BMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-1, -2));
}
TEST(BusTest, complexInst3) {
    Bus car = Bus(0, 0, Direction::North);
    car.ExecuteCommands("FMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-2, 4));
}
TEST(BusTest, complexInst4) {
    Bus car = Bus(0, 0, Direction::North);
    car.ExecuteCommands("FBMLR");
    EXPECT_EQ(car.GetHeading(), "North");
    EXPECT_EQ(car.GetPosition(), std::make_pair(-2, -4));
}