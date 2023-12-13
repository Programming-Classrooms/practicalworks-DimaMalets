#include <iostream>
#include<iomanip>

3. добавляет слева и справа в записи числа цифру, повторяющуюся
максимальное число раз;

void inputNumber(int32_t& number) {
    std::cout << "Input natural number:\n";
    std::cin >> number;
    if (number <= 0)
    {
        std::cout << "Not a natural!!!\n";
        inputNumber(number);
    }
}

int main()
{
    int32_t temp_first;
    int32_t temp_second;
    int32_t number;
    int32_t theDesiredFigure;
    int32_t counterRepetitions = 0;
    int32_t numberRepetitions = 0;
    uint16_t degree = 1;
    inputNumber(number);
    temp_second = number;
    temp_first = number;
    for (size_t i = 0; i <= 9; i++)
    {
        temp_first = number;
        counterRepetitions = 0;
        while (temp_first != 0)
        {
            if (temp_first % 10 == i)
            {
                counterRepetitions++;
            }
            temp_first /= 10;
        }
        if (counterRepetitions >= numberRepetitions)
        {
            theDesiredFigure = i;
            numberRepetitions = counterRepetitions;
        }
    }
    while (number != 0) {
        number /= 10;
        degree++;
    }
        std::cout << "New number = " << std::setprecision(10) << theDesiredFigure * pow(10, degree) + temp_second * 10 + theDesiredFigure;
        return 0;

}