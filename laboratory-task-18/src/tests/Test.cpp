#include "../class/Library.hpp"
#include <gtest/gtest.h>

TEST(LibraryTest, AllMethods)
{
    Library a;
    a.addBook();
    a.addBook();
    a.addBook();
    a.printListBook();
    a.addAuthor();
    a.printListBook();
    a.seekBook();
    a.deleteBook();
    a.printListBook();
    a.addAuthor();
    a.printListBook();
    a.deleteAuthor();
    a.printListBook();
    a.sortByTtile();
  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}