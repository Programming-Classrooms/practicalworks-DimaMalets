#include "../func/Function.hpp"
#include <gtest/gtest.h>
#include <stdexcept>


TEST(FillVectorTest, MultipleNumbersInput) {
    std::vector<int> container;
    std::stringstream input("1\n2\n3\nq\n");
    std::cin.rdbuf(input.rdbuf()); 
    fillVector(container);
    EXPECT_EQ(container.size(), 3);
}

TEST(FillVectorTest, MultipleNumbersInput) {
    std::vector<int> container;
    std::stringstream input("1\n2\n3\nq\n");
    std::cin.rdbuf(input.rdbuf());
    fillVector(container);
    EXPECT_EQ(container.size(), 3);
}

TEST(SizeVectorTest, SizeVector) {
    std::vector<int> container{1, 2, 3, 4, 5};
    testing::internal::CaptureStdout();
    sizeVector(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\nКоличество элементов : 5");
}


TEST(SeekNumberTest, SeekNumber) {
    std::vector<int> container{1, 2, 3, 4, 5};
    std::stringstream input("3\n");
    std::cin.rdbuf(input.rdbuf()); 
    testing::internal::CaptureStdout();
    seekNumber(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n******************************************\nВведите число для поиска: Количество 3: 1\n******************************************");
}

TEST(ReplaceEvenNumTest, ReplaceEvenNum) {
    std::vector<int> container{1, 2, 3, 4, 5};
    testing::internal::CaptureStdout();
    replacEvenNum(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n\n******************************************\nЗаменить все числа, модуль которых есть четное число,\nна разность максимального и минимального элемента этого вектора;\n\nМаксимальный элемент = 5\nМинимальрный элемент = 1\n\nПреобразованный массив\n1 1 1 1 5 ");
}


TEST(DeleteRepeatTest, DeleteRepeat) {
    std::vector<int> container{1, 2, 3, 2, 4, 5};
    testing::internal::CaptureStdout();
    deleteRepeat(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n\n******************************************\nУдалить из последовательности все равные по модулю числа, кроме первого из них\n\nПреобразованный массив\n1 2 3 4 5 ");
}

TEST(ReplaceZerosTest, ReplaceZeros) {
    std::vector<int> container{1, 0, 3, 0, 5};
    testing::internal::CaptureStdout();
    replaceZeros(container);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n\n******************************************\nИзменение всех нулевых элементов на среднее арифметическое\n\nПреобразованный вектор\n1 2 3 2 5 \n******************************************");
}
