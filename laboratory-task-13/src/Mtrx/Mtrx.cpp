#include "Mtrx.hpp"


/* Выделение памяти */
void Mtrx::allocMemory()
{
	matrix = new double* [rows];
	for (size_t i = 0; i < rows; ++i) {
		matrix[i] = new double[columns];
	}
}

/* Консруктор по умолчанию */
Mtrx::Mtrx():rows(1),columns(1)
{
	allocMemory();
	matrix[0][0] = 0;
}

/* Конструктор с параметрами */
Mtrx::Mtrx(int32_t rows, int32_t columns):rows(rows),columns(columns)
{
	allocMemory();
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			matrix[i][j] = 0;
		}
	}
}

/* Конструктор копирования */
Mtrx::Mtrx(const Mtrx& rhs):rows(rhs.rows),columns(rhs.columns)
{
	allocMemory();
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			matrix[i][j] = rhs.matrix[i][j];
		}
	}
}

// Деструктор 
Mtrx::~Mtrx()
{
	for (size_t i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}


	/* Получение элемента */
double Mtrx::getElements(const int32_t i , const int32_t j)
{
	return matrix[i][j];
}


// 
void Mtrx::setRows(int32_t row)
{
	if (row <= 0) {
		throw std::invalid_argument("The number of rows must be a natural number!!");
	}
	else {
		this->rows = row;
	}
}

void Mtrx::setColumns(int32_t col)
{
	if (col <= 0) {
		throw std::invalid_argument("The number of columns must be a natural number!!");
	}
	else {
		this->columns = col;
	}
}

	/* Оператор присваивания */
Mtrx& Mtrx::operator=(const Mtrx& rhs)
{
	if (this != &rhs) {
		this->rows = rhs.rows;
		this->columns = rhs.columns;
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < columns; ++j) {
				matrix[i][j] = rhs.matrix[i][j];
			}
		}
	}
	return *this;
}

		//  Состаной оператор присваивния(сложение)  //
Mtrx& Mtrx::operator+=(const Mtrx& rhs)
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Mismatch of matrix sizes");
	}
	*this = *this + rhs;
	return *this;
}

		//  Состаной оператор присваивния(вычитание)  //
Mtrx& Mtrx::operator-=(const Mtrx& rhs)
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Mismatch of matrix sizes");
	}
	*this = *this - rhs;
	return *this;
}

//  Состаной оператор присваивния(умножение на матрицу)  //
Mtrx& Mtrx::operator*=(const Mtrx& rhs)
{
	*this = *this * rhs;
	return *this;
}

//  Состаной оператор присваивния(умножение на число)  //
Mtrx& Mtrx::operator*=(const int32_t& num)
{
	*this = *this * num;
	return *this;
}

//  Состаной оператор присваивния(деление на число)  //
Mtrx& Mtrx::operator/=(const int32_t& num)
{
	*this = *this / num;
	return *this;
}

/* Оператор сложения */
Mtrx Mtrx::operator+(const Mtrx& rhs) const
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Mismatch of matrix sizes");
	}
	else {
		Mtrx reserve(*this);
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < columns; ++j) {
				reserve.matrix[i][j] += rhs.matrix[i][j];
			}
		}
		return reserve;
	}
}

/* Оператор вычитания */
Mtrx Mtrx::operator-(const Mtrx& rhs) const
{
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		throw std::invalid_argument("Mismatch of matrix sizes");
	}
	else {
		Mtrx reserve(*this);
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < columns; ++j) {
				reserve.matrix[i][j] -= rhs.matrix[i][j];
			}
		}
		return reserve;
	}
}

//  Оператор умножения
Mtrx Mtrx::operator*(const Mtrx& rhs) const
{

	if (this->columns != rhs.rows) {
		throw std::invalid_argument(" The number of columns of the first matrix is not equal to the number of rows of the second!!! ");
	}
	else {
		Mtrx reserve(this->columns,rhs.rows);
		for (size_t i = 0; i < this->rows; i++)
		{
			for (size_t j = 0; j < rhs.columns; j++)
			{    
				for (size_t k = 0; k < this->columns; k++)
					reserve.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
			}
		}
		return reserve;
	}
}

/* Опеартор умножения (матрица * число) */
Mtrx Mtrx::operator*(const int32_t& num) const
{
	Mtrx reserve(*this);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			reserve.matrix[i][j] *= num;
		}
	}
	return reserve;
}


/* Оператор умножения ( число * матрицу ) */
Mtrx operator*(const int32_t& num, const Mtrx& rhs)
{
	Mtrx reserve(rhs);
	for (size_t i = 0; i < rhs.rows; ++i) {
		for (size_t j = 0; j < rhs.columns; ++j) {
			reserve.matrix[i][j] *= num;
		}
	}
	return reserve;
}

/* Оператор деления */
Mtrx Mtrx::operator/(const int32_t& num) const
{
	Mtrx reserve(*this);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			reserve.matrix[i][j] /= num;
		}
	}
	return reserve;
}

			/* Операторы сравнения */
bool Mtrx::operator==(const Mtrx& rhs) const
{
	bool flag = true;
	if (this->rows != rhs.rows || this->columns != rhs.columns) {
		flag = false;
		return flag;
	}
	else {
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < columns; ++j) {
				if (matrix[i][j] != rhs.matrix[i][j]) {
					flag = false;
					return flag;
				}
					
			}
		}
	}
	return flag;
}

bool Mtrx::operator!=(const Mtrx& rhs) const
{
	return !(*this == rhs );
}

		/// Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, Mtrx& rhs)
{
		std::cout << " Enter the number of rows = ";
		std::cin >> rhs.rows;
		std::cout << " \nEnter the number of columns = ";
		std::cin >> rhs.columns;

	while (rhs.rows <= 0 || rhs.columns <= 0) {
		std::cout << " Enter the number of rows = ";
		std::cin >> rhs.rows;
		std::cout << " \nEnter the number of columns = ";
		std::cin >> rhs.columns;
	}

	rhs.allocMemory();
	std::cout << " Now fill in the matrix \n";
	for (size_t i = 0; i < rhs.rows; ++i) {
		for (size_t j = 0; j < rhs.columns; ++j) {
			std::cin >> rhs.matrix[i][j];
		}
		std::cout << '\n';
	}
	return in;
}

		/// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Mtrx& rhs)
{
	for (size_t i = 0; i < rhs.rows; ++i) {
		for (size_t j = 0; j < rhs.columns; ++j) {
			std::cout<<std::setw(3) << rhs.matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return out;
}
