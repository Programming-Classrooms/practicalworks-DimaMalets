#include <iostream>

//19. Находит для заданного натурального N все пифагоровы тройки
//чисел, каждое из которых не превосходит N.

void inputNumber(int32_t& number) {
	std::cout << "Enter natural number = ";
	std::cin >> number;
	while (number <= 0)
	{
		std::cout << "Is a not natural number" << '\n';
		std::cout << "Enter natural number = ";
		std::cin >> number;
	}
}

int main()
{
	int32_t number;
	inputNumber(number);
		for (size_t i = 1; i <= number; i++)
		{
			for (size_t j = 1; j <= number; j++)
			{
				for (size_t m = 1; m <= number; m++)
				{
					if (m * m + j * j == i * i /*&& j < m*/)
					{
						std::cout << j << " " << m << " " << i << '\n';
					}
				}
			}
		}
	return 0;
	}