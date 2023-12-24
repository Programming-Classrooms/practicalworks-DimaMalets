/* 
     3. добавляет слева и справа в записи числа цифру, повторяющуюся 
     максимальное число раз; 
 */ 
 
 
#include <iostream> 
#include<iomanip> 
 
void inputNumber(int32_t& number) 
{ 
    std::cout << "Input natural number:\n"; 
    std::cin >> number; 
    while(number <= 0) { 
     std::cout << "Input natural number:\n"; 
     std::cin >> number; 
    }
} 
 
int main() 
{ 
    int32_t number{ 0 }; 
    inputNumber(number); 
    int32_t reserveNumberFirst{ number }; 
    int32_t reserveNumberSecond{ number }; 
    int32_t theDesiredFigure{ 0 }; 
    int32_t counterRepetitions{ 0 }; 
    int32_t numberRepetitions{ 0 }; 
    uint16_t degree{ 1 }; 
    for (size_t i = 0; i <= 9; i++) { 
        reserveNumberFirst = number; 
        counterRepetitions = 0; 
        while (reserveNumberFirst != 0) { 
            if (reserveNumberFirst % 10 == i) { 
                counterRepetitions++; 
            } 
            reserveNumberFirst /= 10; 
        } 
        if (counterRepetitions >= numberRepetitions) { 
            theDesiredFigure = i; 
            numberRepetitions = counterRepetitions; 
        } 
    } 
    while (number != 0) { 
        number /= 10; 
        degree++; 
    } 
    std::cout << "New number = " << std::setprecision(10) << theDesiredFigure * pow(10, degree) + reserveNumberSecond * 10 + theDesiredFigure; 
    return 0; 
}
