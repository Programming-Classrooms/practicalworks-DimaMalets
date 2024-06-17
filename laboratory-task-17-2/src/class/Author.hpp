#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <vector>

class Author
{
    private:
    std::string surname;
    std::string name;
    std::string patronymic;

    public:
    /* Конструкторы */
    Author();
    Author(const Author&);

    /* Деструктор */
    ~Author() = default;

    /* Геттеры */
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;

    /* Чтение из файла */
    void virtual readFile(std::istream&,int16_t);

    /* Добавить автора */
    void virtual addAuthor();

    /* Операторы сравнения */
    bool operator < (const Author&) const;
    bool operator == (const Author&) const;

    /* Вывод информации */
    void  printData() const;
    
};

#endif // Author.hpp
