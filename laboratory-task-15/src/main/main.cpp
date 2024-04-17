#include "../func/Function.hpp"


int main() {
	
	setlocale(LC_ALL, ".1251");

	std::vector <int> container;

	/* Заполнение вектора */
	fillVector(container);

	/* Сумма элементов */
	sumElements(container);

	/* Количество элементов */
	sizeVector(container);

	/* Количество заданных элементов */
	seekNumber(container);

	/* Количество элементов в сравнении с заданным */
	comparisons(container);

	/* Замена нулей на среднее арифметическое */
	replaceZeros(container);

	/* 
	    Добавить к каждому элементу вектора сумму всех чисел из
		заданного интервала этого же вектора ; 
	*/
	interval(container);

	/*
	    Заменить все числа, модуль которых есть четное число, на
		разность максимального и минимального элемента этого
		вектора;

	*/
	replacEvenNum(container);

	/*
		Удалить из последовательности все равные по модулю числа,
		кроме первого из них.
	*/
	deleteRepeat(container);

	return 0;
}