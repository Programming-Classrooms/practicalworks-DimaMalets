#include "Car.hpp"

// Конструктор с параметрами
CarUnderReraip::CarUnderReraip(
std::string iCarBrand,
double iRepairPrice,
std::string idescriptionBreakdown,
double iRepairTime):

carBrand(iCarBrand),
repairPrice(iRepairPrice),
descriptionBreakdown(idescriptionBreakdown),
repairTime(iRepairTime)
{}

// Конструктор копирования
CarUnderReraip::CarUnderReraip(const CarUnderReraip &rhs):
carBrand(rhs.carBrand),
repairPrice(rhs.repairPrice),
descriptionBreakdown(rhs.descriptionBreakdown),
repairTime(rhs.repairTime)
{}

//************ Геттеры ************

std::string CarUnderReraip::getCarBrand() const
{
    return this->carBrand;
}

double CarUnderReraip::getrepairPrice() const
{
    return this->repairPrice;
}

std::string CarUnderReraip::getdescriptionBreakdown() const
{
    return this->descriptionBreakdown;
}

double CarUnderReraip::getrepairTime() const
{
    return this->repairTime;
}

//************ Cеттеры ************

void CarUnderReraip::setCarBrand(std::string iCarBrand)
{
    this->carBrand = iCarBrand;
}

void CarUnderReraip::setRepairPrice(double iRepairPrice)
{
    this->repairPrice = iRepairPrice;
}

void CarUnderReraip::setDescriptionBreakdown(std::string iDescriptionBreakdown)
{
    this->descriptionBreakdown = iDescriptionBreakdown;
}

void CarUnderReraip::setRepairTime(double iRepairTime)
{
    this->repairTime = iRepairTime;
}

/* Очистка всех данных */
void CarUnderReraip::clear()
{
    this->carBrand.clear();
    this->repairPrice = 0;
    this->descriptionBreakdown.clear();
    this->repairTime = 0;
}

/* Ручное заполнение */
void CarUnderReraip::manualFill()
{
    std::cout << "\nВведите марку авто: ";
    std::cin >> this->carBrand;
    std::cout << "\nВведите цену за ремонт авто: ";
    std::cin >> this->repairPrice;
    std::cout << "\nОписание поломки(Нажмите enter в конце описания):\n";
    getline(std::cin,this->descriptionBreakdown);
    std::cout << "\nВведите кол-во дней нужных для ремонта:";
    std::cin >> this->repairTime;
}
