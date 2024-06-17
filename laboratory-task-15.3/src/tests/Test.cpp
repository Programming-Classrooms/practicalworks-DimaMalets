#include "../func/Function.hpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <fstream>

TEST(CheckFileTest, FileNotOpen) {
    std::fstream testFile("nonexistent.txt");
    ASSERT_THROW(checkFile(testFile), std::invalid_argument);
}

TEST(SortVectorTest, SortVector) {
    std::vector<std::string> container = {"banana", "apple", "orange"};
    sortVector(container);
    ASSERT_EQ(container[0], "apple");
    ASSERT_EQ(container[1], "banana");
    ASSERT_EQ(container[2], "orange");
}

TEST(DeleteByLetterTest, DeleteWordsStartingWithLetter) {
    std::vector<std::string> container = {"apple", "banana", "orange"};
    std::istringstream iss("b");
    std::cin.rdbuf(iss.rdbuf());
    deleteByLetter(container);
    ASSERT_EQ(container.size(), 2);
    ASSERT_EQ(container[0], "apple");
    ASSERT_EQ(container[1], "orange");
}
