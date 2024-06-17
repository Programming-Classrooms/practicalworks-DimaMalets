#include "../MyString/MyString.hpp"

int main() {

MyString test("dcd");
MyString test2;
test2 = "few";
test = test + test2;
std::cout << test;
return 0;
}
