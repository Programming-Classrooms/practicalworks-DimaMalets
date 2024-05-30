#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>



class CarUnderReraip
{

private:
std::string carBrand;  // марка автомобиля
double repairPrice;    // цена за ремонт
std::string descriptionBreakdown; // описание поломки
double repairTime;      // время ремонта в днях

public:
// Конструкторы
CarUnderReraip() = default;

CarUnderReraip(
std::string iCarBrand,
double iRepairPrice,
std::string idescriptionBreakdown,
double iRepairTime);

CarUnderReraip(const CarUnderReraip& rhs);

// Деструктор
~CarUnderReraip(){};

// Геттеры
std::string getCarBrand() const;
double getrepairPrice() const;
std::string getdescriptionBreakdown() const;
double getrepairTime() const;


// Сеттеры
void setCarBrand(std::string iCarBrand);
void setRepairPrice(double iRepairPrice);
void setDescriptionBreakdown(std::string iDescriptionBreakdown);
void setRepairTime(double iRepairTime);

// Очистка всех данных
void clear();

// Ручное заполнение
void manualFill();

// Перегрузка операторов сравнения
bool operator == (const CarUnderReraip& rhs);

// Перегрузка оператора вывода
friend std::ostream& operator << (std::ostream& out, const CarUnderReraip& rhs);
};






#endif //Car.hpp
