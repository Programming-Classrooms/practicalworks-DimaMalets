#include <stdexcept>
#include "../Car/Car.hpp"
#include "../TDeque/TDeque.hpp"
#include <gtest/gtest.h>


class TDequeTest : public ::testing::Test {
protected:
    TDeque<int> deque;

    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(TDequeTest, AccessByIndex) {
    deque.InsRear(90);
    deque.InsRear(100);
    deque.InsRear(110);

    EXPECT_EQ(deque.GetByIndex(0), 90);
    EXPECT_EQ(deque.GetByIndex(1), 100);
    EXPECT_EQ(deque.GetByIndex(2), 110);

    deque.SetByIndex(120, 1);
    EXPECT_EQ(deque.GetByIndex(1), 120);
}

TEST_F(TDequeTest, FindElement) {
    deque.InsRear(130);
    deque.InsRear(140);
    deque.InsRear(150);

    EXPECT_TRUE(deque.findElement(130));
    EXPECT_TRUE(deque.findElement(140));
    EXPECT_TRUE(deque.findElement(150));
    EXPECT_FALSE(deque.findElement(160));
}

TEST_F(TDequeTest, BrowseWithModification) {
    deque.InsRear(1);
    deque.InsRear(2);
    deque.InsRear(3);

    deque.BrowseWithModification([](int& info) { info *= 2; });

    EXPECT_EQ(deque.GetByIndex(0), 2);
    EXPECT_EQ(deque.GetByIndex(1), 4);
    EXPECT_EQ(deque.GetByIndex(2), 6);
}

TEST_F(TDequeTest, BrowseWithoutModification) {
    deque.InsRear(1);
    deque.InsRear(2);
    deque.InsRear(3);

    std::vector<int32_t> result;
    deque.BrowseWithoutModification([&result](int info) { result.push_back(info); });

    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
}



class TDequeCarTest : public ::testing::Test {
protected:
    TDeque<CarUnderReraip> carDeque;

    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(TDequeCarTest, AccessByIndex) {
    CarUnderReraip car1("Lexus", 2200.0, "Air conditioning repair", 3);
    CarUnderReraip car2("Mazda", 1700.0, "Exhaust system repair", 2);

    carDeque.InsRear(car1);
    carDeque.InsRear(car2);

    EXPECT_EQ(carDeque.GetByIndex(0).getCarBrand(), "Lexus");
    EXPECT_EQ(carDeque.GetByIndex(1).getCarBrand(), "Mazda");

    carDeque.SetByIndex(CarUnderReraip("Subaru", 1100.0, "Steering repair", 5), 1);
    EXPECT_EQ(carDeque.GetByIndex(1).getCarBrand(), "Subaru");
}

TEST_F(TDequeCarTest, FindElement) {
    CarUnderReraip car1("Volvo", 1300.0, "Alternator repair", 4);
    CarUnderReraip car2("Kia", 700.0, "Window repair", 1);

    carDeque.InsRear(car1);
    carDeque.InsRear(car2);

    EXPECT_TRUE(carDeque.findElement(car1));
    EXPECT_TRUE(carDeque.findElement(car2));
    EXPECT_FALSE(carDeque.findElement(CarUnderReraip("Hyundai", 1200.0, "Radiator repair", 2)));
}


TEST_F(TDequeCarTest, BrowseWithoutModification) {
    carDeque.InsRear(CarUnderReraip("Porsche", 5000.0, "Engine tuning", 15));
    carDeque.InsRear(CarUnderReraip("Ferrari", 8000.0, "Turbo installation", 20));

    std::vector<std::string> brands;
    carDeque.BrowseWithoutModification([&brands](const CarUnderReraip& car) { brands.push_back(car.getCarBrand()); });

    EXPECT_EQ(brands[0], "Porsche");
    EXPECT_EQ(brands[1], "Ferrari");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
