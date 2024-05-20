#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include <algorithm>
#include <map>

class Library: public Book
{

private:

std::map<std::string,Book> myLibrary;

public:

/* Конструкторы */
Library() = default;
Library(const std::map<std::string,Book>&);
Library(const Library&);

/* Деструктор */
~Library() = default;

/* Добавление книги */
void addBook();

/* Найти книгу(по ISBN) */
void seekBook();

/* Удалить книгу(по ISBN) */
void deleteBook();

/* Просмотреть список книг */
void printListBook();

/* Добавить автора(по ISBN) */
void addAuthor();

/* Удалить автора(по ISBN) */
void deleteAuthor();

/* Сортировка по названиям книг */
void sortByTtile();

};

#endif // Library.hpp
