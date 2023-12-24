/* 
    6. выполняет разложение числа на простые множители. 
*/ 
 
#include <iostream> 
 
void inputNumber(int32_t& number)  
{ 
    std::cout << "Enter natural number = "; 
    std::cin >> number; 
    while(number <= 0) { 
     std::cout << "Enter natural number = "; 
     std::cin >> number; 
    }
} 
 
void simpleDivisors(int32_t& divisor, int32_t number) 
{ 
    while (divisor * divisor <= number) { 
        if (number % divisor == 0) { 
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
} 
 
int main() { 
    int32_t number{ 0 }, divisor{ 2 }; 
    inputNumber(number); 
    simpleDivisors(divisor, number); 
    return 0; 
}
