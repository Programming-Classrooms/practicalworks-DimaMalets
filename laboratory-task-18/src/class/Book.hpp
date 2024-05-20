#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>


class Book
{

protected:

    static int32_t counter;
    std::string ISBN;
    std::string title;
    std::vector<std::string> authors;
    double price;
    int32_t count;

public:

/* Конструкторы */
Book();
Book(std::string,const std::vector<std::string>&, double, int32_t);
Book(const Book&);

/* Деструктор  */
~Book() = default;

/* Операторы ввода и вывода */
friend std::istream& operator >>(std::istream&, Book&);
friend std::ostream& operator <<(std::ostream&, const Book&);

/* Получение ISBN */
std::string getISBN() const;

/* Получение  названия  */
std::string getTitle() const;

/* Добавление автора */
void addAuthor();

/* Удаление автора */
void deleteAllAuthors();

};

#endif // Book.hpp
