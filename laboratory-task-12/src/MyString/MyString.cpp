#include "MyString.hpp"


/*  Конструктор по умолчанию   */
MyString::MyString():pStr(nullptr),size(0)
{}

/*  Конструктор с параметрами (размер)   */
MyString::MyString(size_t initSize):size(initSize)
{
	pStr = new char[initSize + 1];
}

/*  Конструктор с парамметрами (строка)  */
MyString::MyString(const char* initStr):size(strlen(initStr))
{
	pStr = new char[strlen(initStr) + 1];
	strcpy(pStr, initStr);
}

/*  Конструктор копирования   */
MyString::MyString(const MyString& rhs)
{
	if (rhs.pStr) {
		pStr = new char[strlen(rhs.pStr) + 1];
		strcpy(this->pStr, rhs.pStr);
		size = strlen(rhs.pStr);
	}
	else {
		pStr = nullptr;
		size = 0;
	}
}

/*  Конструктор перемещения   */
MyString::MyString(MyString&& rhs) noexcept {
	this->pStr = rhs.pStr;
	delete rhs.pStr;
	rhs.pStr =nullptr;
}

/*  Деструктор   */
MyString::~MyString()
{
	delete[] pStr;
}

/*  Получение размера  */
size_t MyString::getSize() const
{
	return this->size;
}

/*  Получение строки  */
const char* MyString::getStr()const
{
	return this->pStr;
}

/*  Оператор сложения (объект + объект)  */
MyString MyString::operator+(const MyString& rhs) const
{
	char* copy = new char[strlen(this->pStr) + strlen(rhs.pStr + 1)];
		strcpy(copy,this->pStr);
		strcat(copy, rhs.pStr);
		MyString myString(copy);
		delete [] copy;
		return myString;
}

/*  Оператор сложения (объект + строка)  */
MyString MyString::operator+(const char* text) const
{
	char* res = new char[this->size + strlen(text) + 1];
	strcat(res, this->pStr);
	strcat(res, text);
	MyString copy(res);
	delete[] res;
	return copy;
}

/*  Оператор присваивания (объект = строка)  */
MyString& MyString::operator=(const char* text)
{
	if (text) {
		delete[] this->pStr;
		pStr = nullptr;
		pStr = new char[strlen(text) + 1];
		strcpy(this->pStr, text);
		this->size = strlen(text);
	}
	else {
		delete[] this->pStr;
		this->pStr = nullptr;
	}
	return *this;
}

/*  Оператор присваивания (объект = объект)  */
MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs) {
		delete[] this->pStr;
		pStr = nullptr;
		pStr = new char[strlen(rhs.pStr) + 1];
		strcpy(this->pStr, rhs.pStr);
		this->size = rhs.size;
	}
	else {
		delete[] this->pStr;
		this->pStr = nullptr;
	}
	return *this;
}

/*  Оператор  составного присваивания (объект += объект)  */
MyString& MyString::operator+=(const MyString& rhs)
{
	*this = *this + rhs;
	return *this;
}

/*  Оператор  составного присваивания (объект += строка)  */
MyString& MyString::operator+=(const char* text)
{
	*this = *this + text;
	return *this;
}

/*  Оператор сравнения (объект != объект)  */
bool MyString::operator!=(const MyString& rhs) const
{
	if (strlen(this->pStr) != strlen(rhs.pStr)) {
		return false;
	}
	else {
		for (size_t i = 0; i < this->size; ++i) {
			if (this->pStr[i] != rhs.pStr[i]) {
				return false;
			}
		}
	}
	return true;
}

/*  Оператор сравнения (объект != строка)  */
bool MyString::operator!=(const char* text) const
{
	if (strlen(this->pStr) != strlen(text)) {
		return false;
	}
	else {
		for (size_t i = 0; i < this->size; ++i) {
			if (this->pStr[i] != text[i]) {
				return false;
			}
		}
	}
	return true;
}

/*  Оператор  сравнения (объект < объект)  */
bool MyString::operator<(const MyString& rhs) const
{
	if (strcmp(this->pStr, rhs.pStr) < 0) {
		return true;
	}
	return false;
}

/*  Оператор  сравнения (объект < строка)  */
bool MyString::operator<(const char* text) const
{
	if (strcmp(this->pStr, text) < 0) {
		return true;
	}
	return false;
}

/*  Метод очистки строки  */
void MyString::clear()
{
	delete[] pStr;
	this->size = 0;
	pStr = nullptr;
}

/*  Перегрузка получения элемента  */
char& MyString::operator[](size_t init)
{
	return this->pStr[init];
}

/*  Перегркзка оператора вывода  */
std::ostream& operator<<(std::ostream& out, const MyString& rhs)
{
	if (rhs.pStr) {
		out << rhs.pStr;
	}
	return out;
}

/*  Перегркзка оператора ввода  */
std::istream& operator>>(std::istream& in, MyString& rhs)
{
	char* temp = new char[3000];
	in.getline(temp,3000);
	rhs.size = strlen(temp);
	rhs.pStr = new char[strlen(temp) + 1];
	strcpy(rhs.pStr, temp);
	delete[] temp;
	return in;
}
