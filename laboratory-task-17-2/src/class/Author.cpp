#include "Author.hpp"


bool Author::operator<(const Author & rhs) const
{
    return (this->surname < rhs.surname) ;
}

bool Author::operator==(const Author & rhs) const
{
    return (this->surname == rhs.surname && this->name == rhs.name && this->patronymic == rhs.patronymic);
}

Author::Author()
{}

Author::Author(const Author &rhs)
{
    this->surname = rhs.surname;
    this->name = rhs.name;
    this->patronymic = rhs.patronymic;
}

std::string Author::getSurname() const
{
    return this->surname;
}

std::string Author::getName() const
{
    return this->name;
}

std::string Author::getPatronymic() const
{
    return this->patronymic;
}

void Author::printData() const
{
    std::cout << "\nФамилия автора: " << this->surname;
    std::cout << "\nИмя автора: " << this->name;
    std::cout << "\nОтчество автора: " << this->patronymic;
}

void Author::readFile(std::istream& in,int16_t count)
{
    in >> this->surname;
    in >> this->name;
    in >> this->patronymic;
}

void Author::addAuthor()
{
    std::cout << "Введите фамилию автора: ";
    std::cin >> this->surname;
    std::cout << "Введите имя автора: ";
    std::cin >> this->name;
    std::cout << "Введите отчество автора: ";
    std::cin >> this->patronymic;
}
