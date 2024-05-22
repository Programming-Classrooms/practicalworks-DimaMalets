#include "../funcs/Funcs.hpp"
#include <gtest/gtest.h> 
#include <sstream> 
#include <fstream> 

// Тестирование функции readFile
TEST(ReadFileTest, BasicTest) {
    std::multimap<std::string, int16_t> myMap;
    std ::ifstream in ("src/files/test.txt");
    readFile(myMap, in);
    EXPECT_EQ(myMap.count("hello"), 3);
    EXPECT_EQ(myMap.count("world"), 2);
}

// Тестирование функции checkFile
TEST(CheckFileTest, BasicTest) {
    std::ifstream goodFile("src/files/good_file.txt");
    std::ifstream emptyFile("src/files/empty_file.txt");
    std::ifstream badFile("src.files/bad_file.txt");
    EXPECT_NO_THROW(checkFile(goodFile));
    EXPECT_THROW(checkFile(emptyFile), std::runtime_error);
    EXPECT_THROW(checkFile(badFile), std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

