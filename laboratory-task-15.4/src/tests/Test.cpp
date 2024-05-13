#include "../func/Function.hpp"
#include <gtest/gtest.h>


TEST(DeleteMaxTest, DeleteMax) {
    std::vector<std::vector<int>> mtrx{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    deleteMax(mtrx, 3, 3);
    std::vector<std::vector<int>> expected{{1, 2}, {4, 5}};
    ASSERT_EQ(mtrx, expected);
}


TEST(NewSortTest, SortBySum) {
    std::vector<std::vector<int>> mtrx{{4, 5, 6}, {1, 2, 3} ,{7, 8, 9}};
    newSort(mtrx, 3, 3);
    std::vector<std::vector<int>> expected{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ASSERT_EQ(mtrx, expected);
}

TEST(FillSizeTest, ValidInput) {
    int16_t rows, columns;
    std::stringstream input("3\n4\n");
    std::cin.rdbuf(input.rdbuf()); // Перенаправление ввода
    ASSERT_NO_THROW(fillSize(rows, columns));
    EXPECT_EQ(rows, 3);
    EXPECT_EQ(columns, 4);
}

TEST(FillSizeTest, NegativeRowsInput) {
    int16_t rows, columns;
    std::stringstream input("-3\n4\n");
    std::cin.rdbuf(input.rdbuf()); // Перенаправление ввода
    ASSERT_THROW(fillSize(rows, columns), std::invalid_argument);
}

TEST(FillSizeTest, NegativeColumnsInput) {
    int16_t rows, columns;
    std::stringstream input("3\n-4\n");
    std::cin.rdbuf(input.rdbuf()); // Перенаправление ввода
    ASSERT_THROW(fillSize(rows, columns), std::invalid_argument);
}