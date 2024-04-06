#include "Fraction.hpp"
#include <numeric>


/* Сокращение дроби */
void Fraction::reduce()
{
	int32_t divisor = std::gcd(this->numerator, this->denominator);
    if (divisor != 1) {
        this->numerator /= divisor;
        this->denominator /= divisor;
    }
}

/* Конструктор по умолчанию */
Fraction::Fraction(): 
    numerator(0),
    denominator(1)
{}

/* Конструктор с параметрами */
Fraction::Fraction(int32_t num , int32_t denom) :
    numerator(num),
    denominator(denom)
 
{
    if(denom == 0){
        throw std::invalid_argument("denominator != 0");
    }
    this->reduce();
}

/* Конструктор копирования */
Fraction::Fraction(const Fraction& obj):
    numerator(obj.numerator),
    denominator(obj.denominator)
{}

/* Деструктор */
Fraction::~Fraction()
{}

/* Получение числителя */
int32_t Fraction::getNumerator() const
{
    return numerator;
}

/* Получение знаменателя */
int32_t Fraction::getDenominator() const
{
    return denominator;
}

                    ///    Арифметические операции    

/* Сложение (дробь + дробь) */
Fraction Fraction::operator+(const Fraction& rhs)const
{
    Fraction reserve(*this);
    if (this->denominator != rhs.denominator) {
        reserve.denominator = this->denominator * rhs.denominator;
        reserve.numerator = this->denominator * rhs.numerator + this->numerator * rhs.denominator;
        reserve.reduce();
    }
    else {
        reserve.numerator += rhs.numerator;
        reserve.reduce();
    }
    return reserve ;
}

/* Сложение (дробь + целое число) */
Fraction Fraction::operator+(const int32_t& num)const
{
    Fraction reserve(num);
    return *this + reserve ;
}

/* Сложение (Целое число + дробь) */
Fraction operator+(const int32_t& num, const Fraction&rhs)
{
    Fraction reserve(num);
    return rhs + reserve;

}

/* Вычитание (дробь - дробь) */
Fraction Fraction::operator-(const Fraction& rhs)const
{
    Fraction reserve(*this);
    if (this->denominator != rhs.denominator) {
        reserve.denominator = this->denominator * rhs.denominator;
        reserve.numerator = this->numerator * rhs.denominator - this->denominator * rhs.numerator;
        reserve.reduce();
    }
    else {
        reserve.numerator -= rhs.numerator;
        reserve.reduce();
    }
    return reserve;
}

/* Вычитание (дробь - целое число) */
Fraction Fraction::operator-(const int32_t& num)const
{
    Fraction reserve(num);
    return *this - reserve;
}

/* Вычитание ( целое число - дробь) */
Fraction operator-(const int32_t& num, const Fraction& rhs)
{
    Fraction reserve(num);
    return reserve - rhs;

}

/* Умножение (дробь * дробь) */
Fraction Fraction::operator*(const Fraction& rhs)const
{
    Fraction reserve(*this);
    reserve.numerator *= rhs.numerator;
    reserve.denominator *= rhs.denominator;
    reserve.reduce();
    return reserve;
}

/* Умножение (дробь * целое число) */
Fraction Fraction::operator*(const int32_t& num)const
{
    Fraction reserve(*this);
    reserve.numerator *= num;
    reserve.reduce();
    return reserve;
}

/* Умножение ( целое число * дробь) */
Fraction operator*(const int32_t& num, const Fraction& rhs)
{
    Fraction reserve(num);
    return reserve * rhs;

}

/* Деление (дробь / дробь) */
Fraction Fraction::operator/(const Fraction& rhs)const
{  
    if (rhs.numerator == 0) {
        throw std::runtime_error("divised by zero");
    }

    return (*this)*(!rhs);
}

/* Деление (дробь / целое число) */
Fraction Fraction::operator/(const int32_t& num)const
{
    Fraction reserve(*this);
    reserve.denominator *= num;
    reserve.reduce();
    return reserve;
}

/* Деление ( целое число / дробь) */
Fraction operator/(const int32_t& num, const Fraction& rhs)
{
    Fraction reserve(num);
    return reserve / rhs;

}

                ///   Операторы сравнения   

bool Fraction::operator==(const Fraction& rhs) const
{
    return this->numerator == rhs.numerator && this->denominator  == rhs.denominator ;
}


bool Fraction::operator!=(const Fraction& rhs) const
{
    return !(*this ==rhs);
}

bool Fraction::operator<(const Fraction& rhs) const
{
    return this->numerator*rhs.denominator < this->denominator*rhs.numerator;
}

bool Fraction::operator>(const Fraction& rhs) const
{
    return *this!= rhs && !(*this < rhs);
}

                /* Оператор присваивания */
Fraction& Fraction::operator=(const Fraction& rhs)
{
    if (this != &rhs) {
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
    }
    return *this;
}

            /// Составные операторы присваивания 

 /* Составное сложение */
Fraction& Fraction::operator+=(const Fraction& rhs)
{
    *this = *this + rhs;
    return *this;
}

Fraction& Fraction::operator+=(const int& num)
{
    Fraction reserve(num);
    *this = *this + reserve;
    return *this;
}

/*  Составное вычитание */
Fraction& Fraction::operator-=(const Fraction& rhs)
{
    *this = *this - rhs;
    return *this;
}

Fraction& Fraction::operator-=(const int& num)
{
    Fraction reserve(num);
    *this = *this - reserve;
    return *this;
}

/* Составное умножение  */
Fraction& Fraction::operator*=(const Fraction& rhs)
{
    *this = *this * rhs;
    return *this;
}

Fraction& Fraction::operator*=(const int& num)
{
    Fraction reserve(num);
    *this = *this * reserve;
    return *this;
}

/* Составное деление  */
Fraction& Fraction::operator/=(const Fraction& rhs)
{
    *this = *this / rhs;
    return *this;
}

Fraction& Fraction::operator/=(const int& num)
{
    Fraction reserve(num);
    *this = *this / reserve;
    return *this;
}

               ///  Унарные операторы 

    /* Постфиксное */
Fraction Fraction::operator++(int)
{
    Fraction reserve(*this);
    *this = *this + 1;
    return reserve ;
}

    /* Префиксное */
Fraction& Fraction::operator++()
{
    *this = *this + 1;
    return *this;
}

    /* Постфиксное */
Fraction Fraction::operator--(int)
{
    Fraction reserve(*this);
    *this = *this - 1;
    return reserve;
}

    /* Префиксное*/
Fraction& Fraction::operator--()
{
    *this = *this - 1;
    return *this;
}

                /* Приведение к вещественному типу */
 Fraction::operator double() const
{
  return (static_cast<double>(this->numerator) / static_cast<double>(this->denominator));
}

                /* Получение обратной дроби */
Fraction Fraction::operator!()const
{
    return Fraction(this->denominator,this->numerator);
}

                /* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in , Fraction& rhs)
{
    char sign;
    std::cout << "\nEnter fraction sign = ";
    std::cin >> sign;

    std::cout << "\nEnter numerator = ";
    std::cin >> rhs.numerator;

    std::cout << "\nEnter denominator = ";
    std::cin >> rhs.denominator;

    if (sign == '-') {
        rhs.numerator *= -1;
    }
    rhs.reduce();
    return in;
}

                    /* Перегрузка оператора вывода */
std::ostream& operator<<(std::ostream& out, Fraction& rhs)
{
    if(rhs.numerator == 0){
        out << 0;
    }
    else{
    out << rhs.numerator << "/" << rhs.denominator;
    }
    return out;
}