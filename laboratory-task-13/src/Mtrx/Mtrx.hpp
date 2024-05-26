#ifndef MTRX_HPP
#define MTRX_HPP

#include <iostream>
#include <iomanip>


class Mtrx
{
private:

	// Количество строк
	int32_t rows;
	// Количество столбцов
	int32_t columns;
	// Выделение памяти
	void allocMemory();
	// Массив указателей(матрица)
	double** matrix;

public:

	// Конструкторы
	Mtrx();
	Mtrx(int32_t, int32_t);
	Mtrx(const Mtrx&);

	// Деструктор 
	~Mtrx();

	// Get
	double getElements(const int32_t, const int32_t);

	// Set
	void setRows(int32_t);
	void setColumns(int32_t);

	// Составные операторы присваивания
	Mtrx& operator=(const Mtrx&);
	Mtrx& operator+=(const Mtrx&);
	Mtrx& operator-=(const Mtrx&);
	Mtrx& operator*=(const Mtrx&);
	Mtrx& operator*=(const int32_t&);
	Mtrx& operator/=(const int32_t&);

	// Арифметические опрации
	Mtrx operator+(const Mtrx&)const;
	Mtrx operator-(const Mtrx&)const;
	Mtrx operator*(const Mtrx&)const;
	Mtrx operator*(const int32_t&)const;
	friend Mtrx operator*(const int32_t& , const Mtrx&);
	Mtrx operator/(const int32_t&)const;

	// Сравнение матриц на ревнство и неравенство
	bool operator==(const Mtrx&)const;
	bool operator!=(const Mtrx&)const;

	// Перегрузка операторов ввода и вывода
	friend std::istream& operator >>(std::istream&, Mtrx&);
	friend std::ostream& operator <<(std::ostream&, const Mtrx&);
};

#endif //Mtrx.hpp
