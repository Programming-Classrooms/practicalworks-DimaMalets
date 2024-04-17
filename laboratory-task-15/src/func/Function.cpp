#include "Function.hpp"

void fillVector(std::vector<int>& container) 
{
	int number;
	std::cout << "Введите числа (для выхода введите любой другой символ)\n";
	while (std::cin >> number) {
		container.push_back(number);
	}
}

void sumElements(std::vector<int>& container)
{
	int32_t sum = std::accumulate(container.begin(), container.end(), 0);
	std::cout << "Сумма элементов: " << sum;
}

void sizeVector(std::vector<int>& container)

{
	int32_t counter = container.size();
	std::cout << "\nКоличество элементов : " << counter;
}

void seekNumber(std::vector<int>& container)
{
	std::cout << "\n\n******************************************";
	std::cout << "\nВведите число для поиска: ";
	int32_t snum;
	std::cin.clear();
	std::cin.ignore();
	std::cin >> snum;
	int32_t counterS = 0;
	for (auto& number : container) {
		if (snum == number) {
			++counterS;
		}
	}
	std::cout << "Количество " << snum << ": " << counterS;
	std::cout << "\n******************************************";
}

void comparisons(std::vector<int>& container)
{
	std::cout << "\n\n******************************************";
	std::cout << "\nВведите число для сравнения: ";
	int32_t cnum;
	std::cin.clear();
	std::cin.ignore();
	std::cin >> cnum;
	int32_t counterC = 0;
	for (const auto& number : container) {
		if (number < cnum) {
			counterC++;
		}
	}
	std::cout << "Количество чисел  < " << cnum << " : " << counterC;
}

void interval(std::vector<int>& container)
{
	std::cout << "\n\n******************************************";
	std::cout << "\nДобавить к каждому элементу вектора сумму всех чисел из заданного интервала этого же вектора ;\n";
	std::cout << "\nВведите интервал от: ";
	int16_t first;
	int16_t last;
	std::cin >> first;
	if (first < 0) {
		throw std::invalid_argument("Интервал от 0 до размера массива");
	}
	std::cout << " до: ";
	std::cin >> last;
	if (last > container.size()) {
		throw std::invalid_argument("Интервал от 0 до размера массива");
	}
	int32_t sumInt = std::accumulate(container.begin() + first, container.begin()+last + 1, 0);
	for (auto& number : container) {
		number += sumInt;
	}
	std::cout << "\n\nПреобразованный массив\n";
	for (const auto& number : container) {
		std::cout << number << " ";
	}
	std::cout << "\n******************************************\n";

}

 void replacEvenNum(std::vector<int>& container)
 {
	std::cout << "\n\n******************************************";
	std::cout << "\nЗаменить все числа, модуль которых есть четное число,";
	std::cout << "\nна разность максимального и минимального элемента этого вектора;";
	int32_t maxEl;
	int32_t minEl;
	maxEl = *std::max_element(begin(container), end(container));
	std::cout << "\n\nМаксимальный элемент = " << maxEl;
	minEl = *std::min_element(begin(container), end(container));
	std::cout << "\nМинимальрный элемент = " << minEl;
	std::replace_if(container.begin(), container.end(), [](int number) {return number % 2 == 0; }, maxEl - minEl);
	std::cout << "\n\nПреобразованный массив\n";
	for (const auto& number : container) {
		std::cout << number << " ";
	}
 }

void deleteRepeat(std::vector<int>& container)
{	
	std::cout << "\n\n******************************************";
	std::cout << "\nУдалить из последовательности все равные по модулю числа, кроме первого из них";
	std::vector<int>copy = container;
	container.clear();
	int32_t temp;
	std::sort(copy.begin(),copy.end());
	for(const auto& number:copy){
		if(number != temp){
			temp = number;
			container.push_back(temp);
		}
	}
	std::cout << "\n\nПреобразованный массив\n";
	for (const auto& number : container) {
		std::cout << number << " ";
	}
}

void replaceZeros(std::vector<int>container)
{
	std::cout << "\n\n******************************************";
	std::cout << "\nИзменение всех нулевых элементов на среднее арифметическое";
	int32_t sum = std::accumulate(container.begin(),container.end(),0);
	int32_t average = std::floor(double(sum / container.size()));
	std::replace_if(container.begin(), container.end(), [](int number) {return number == 0; }, average);
	for (auto& number : container) {
		if (number == 0) {
			number = average;
		}
	}
	std::cout << "\n\nПреобразованный вектор\n";
	for (const auto& number : container) {
		std::cout << number << " ";
	}
	std::cout << "\n******************************************";
}
