#include <stdexcept>
#include "../func/MyString.hpp"
#include <gtest/gtest.h>

TEST(CompoundAssignment,TestAdd)
{
    MyString a("fffdfv");
    MyString b =a;
    b +="loz";
    EXPECT_STREQ(b.getStr(),"fffdfvloz");
}

TEST(CompoundAssignment,TestAdd2)
{
    MyString a("fffdfv");
    MyString b =a;
    b +=a;
    EXPECT_STREQ(b.getStr(),"fffdfvfffdfv");
}

TEST(Get,GetString)
{
    MyString a("fffdfv");
    EXPECT_STREQ(a.getStr(),"fffdfv");
}

TEST(Get,GetSize)
{
    MyString a("fffdfv");
    EXPECT_EQ(a.getSize(),6);
}

TEST(Constructors,byDefault)
{
    MyString a;
    EXPECT_EQ(a.getSize(),0);
    EXPECT_STREQ(a.getStr(),nullptr);

}

TEST(Constructors,withParameters)
{
    MyString a("Hello");
    EXPECT_EQ(a.getSize(),5);
    EXPECT_STREQ(a.getStr(),"Hello");

}

TEST(Constructors,Copy)
{
    MyString a("Hello");
    MyString b(a);
    EXPECT_EQ(b.getSize(),5);
    EXPECT_STREQ(b.getStr(),"Hello");

}

TEST(Operators,EquallyString)
{
    MyString a("Hello");
    a = "New Hello";
    EXPECT_STREQ(a.getStr(),"New Hello");
}

TEST(Operators,EquallyObject)
{
    MyString a("Hello");
    MyString b;
    b = a;
    EXPECT_STREQ(b.getStr(),"Hello");
}

TEST(Operators,Add)
{
    MyString a("Hello");
    MyString b;
    b = a +a;
    EXPECT_STREQ(b.getStr(),"HelloHello");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
