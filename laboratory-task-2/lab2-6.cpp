#include <iostream>

//6. выполняет разложение числа на простые множители.

void inputNumber(int32_t& number) {
    std::cout << "Enter natural number = ";
    std::cin >> number;
    if (number <= 0) {
        std::cout << "is a not natural number!!!\n";
        std::cin >> number;
    }
}

int main() {
    int32_t number, divisor = 2;
   
     while (divisor * divisor <= number)
        {
          if (number % divisor == 0)
            {
              std::cout << divisor;
              number /= divisor;
              std::cout << '*';
            }
          else if (divisor == 2) {
              divisor = 3;
            }
          else {
              divisor = divisor + 2;
            }
        }
     std::cout << number;
     return 0;

    }
