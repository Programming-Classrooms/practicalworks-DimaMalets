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
    if(iRepairPrice < 0)
    {
        throw std::invalid_argument ("Цена не может быть отрицательной");
    }
    this->repairPrice = iRepairPrice;
}

void CarUnderReraip::setDescriptionBreakdown(std::string iDescriptionBreakdown)
{
    this->descriptionBreakdown = iDescriptionBreakdown;
}

void CarUnderReraip::setRepairTime(double iRepairTime)
{
    if(iRepairTime < 0)
    {
        throw std::invalid_argument ("Время не может быть отрицательным");
    }
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
    std::cin.clear();
    std::cin.ignore();
    getline(std::cin,this->descriptionBreakdown);
    std::cout << "\nВведите кол-во дней нужных для ремонта: ";
    std::cin >> this->repairTime;
}

// Перегрузка оператора сравнения
bool CarUnderReraip::operator == (const CarUnderReraip &rhs)
{
    return (this->carBrand == rhs.carBrand && this->descriptionBreakdown == rhs.descriptionBreakdown && this->repairPrice == rhs.repairPrice && this->repairTime == rhs.repairTime) ;
}

// Перегрузка оператора вывода
std::ostream &operator<<(std::ostream &out, const CarUnderReraip &rhs)
{
    out << "\nМарка авто: ";
    out << rhs.carBrand;
    out << "\nЦена за ремонт авто: ";
    out << rhs.repairPrice;
    out << "\nОписание поломки: ";
    out << rhs.descriptionBreakdown;
    out << "\nКол-во дней нужных для ремонта: ";
    out << rhs.repairTime;
    return out;
}
