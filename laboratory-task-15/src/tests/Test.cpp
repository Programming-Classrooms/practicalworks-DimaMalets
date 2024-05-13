#include "../func/Function.hpp"
#include <gtest/gtest.h>


// Тест ввода нескольких чисел
TEST(FillVectorTest, MultipleNumbersInput) {
    std::vector<int> container;
    std::stringstream input("1\n2\n3\nq\n");
    std::cin.rdbuf(input.rdbuf()); // Перенаправление ввода
    fillVector(container);
    EXPECT_EQ(container.size(), 3);
}

// Тест суммирования элементов вектора
TEST(SumElementsTest, SumElements) {
    std::vector<int> container{1, 2, 3, 4, 5};
    testing::internal::CaptureStdout();
    sumElements(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Сумма элементов: 15");
}

// Тест получения размера вектора
TEST(SizeVectorTest, SizeVector) {
    std::vector<int> container{1, 2, 3, 4, 5};
    testing::internal::CaptureStdout();
    sizeVector(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\nКоличество элементов : 5");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
