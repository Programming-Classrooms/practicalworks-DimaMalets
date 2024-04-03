#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>


class Fraction {

private:

	// Числитель //
	int32_t numerator;

	// Знаменатель //
    int32_t  denominator;

	// Сокращение дроби //
	void reduce();

public:

	// Конструкторы //
	Fraction(); 
	Fraction(int32_t num =0,int32_t denom =1);
	Fraction(const Fraction&);

	// Деструктор //
	~Fraction();

	// Геттеры //
	int32_t getDenominator() const;
	int32_t getNumerator() const;

	// Алгебраические операции //
		
		/* Сложение */
	Fraction operator+(const Fraction&)const;
	Fraction operator+(const int32_t&)const;
	friend Fraction operator+(const int32_t&, const Fraction&);
	
	    /* Вычитание */
	Fraction operator-(const Fraction&)const;
	Fraction operator-(const int32_t&)const;
	friend Fraction operator-(const int32_t&, const Fraction&);


		/* Умножение */
	Fraction operator*(const Fraction&)const;
	Fraction operator*(const int32_t&)const;
	friend Fraction operator*(const int32_t&, const Fraction&);


		/* Деление */
	Fraction operator/(const Fraction&)const;
	Fraction operator/(const int32_t&)const;
	friend Fraction operator/(const int32_t&, const Fraction&);


	// Операторы сравнения //
	bool operator == (const Fraction&)const;
	bool operator != (const Fraction&)const;
	bool operator < (const Fraction&)const;
	bool operator > (const Fraction&)const;

	// Операторы присваивания //
	Fraction& operator=(const Fraction&);

	Fraction& operator+=(const Fraction&);
	Fraction& operator+=(const int&);

	Fraction& operator-=(const Fraction&);
	Fraction& operator-=(const int&);

	Fraction& operator*=(const Fraction&);
	Fraction& operator*=(const int&);

	Fraction& operator/=(const Fraction&);
	Fraction& operator/=(const int&);

	// Унарные операторы //
	Fraction operator++(int);
	Fraction& operator++();
	Fraction operator--(int);
	Fraction& operator--();

	// Оператор отрицания //
	Fraction operator!()const;

	// Приведение к вещественному типу //
	explicit operator double() const;

	// Оператор ввода //
	friend std::istream& operator >>(std::istream&, Fraction&);

	// Оператор вывода //
	friend std::ostream& operator <<(std::ostream&, Fraction&);
};

#endif // Fraction.hpp
