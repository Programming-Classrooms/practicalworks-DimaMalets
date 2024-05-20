#include "Book.hpp"

/* Инициализация статической перемнной */
int32_t Book::counter = 0;

/* Конструктор по умолчанию */
Book::Book():
ISBN(std::to_string(++counter)),
title(""),
price(-1),
count(0)
{}

/* Конструктор с параметрами */
Book::Book(std::string newTitle, const std::vector<std::string> & listAuthors, double newPrice, int32_t newCount):
ISBN(std::to_string(++counter)),
title(newTitle),
authors(listAuthors),
price(newPrice),
count(newCount)
{}

/* Конструктор копирования */
Book::Book(const Book & rhs):
ISBN(rhs.ISBN),
title(rhs.title),
authors(rhs.authors),
price(rhs.price),
count(rhs.count)
{}

/* Получение ISBN */
std::string Book::getISBN() const
{
    return this->ISBN;
}

std::string Book::getTitle() const
{
    return this->title;
}

/* Добавление автора */
void Book::addAuthor()
{
    std::string author;
    std::cout << "Введите ФИО автора(через пробел)";
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin,author);
    this->authors.push_back(author);
}

void Book::deleteAllAuthors()
{
    this->authors.clear();
}

/* Перегрузка оператора ввода */
std::istream &operator>>(std::istream & in, Book & rhs)
{   
    std::cout << "Введите назвние книги: ";
    in >> rhs.title;
    int16_t counter = 0;
    std::string author;
    std::cout << "Введите количество авторов: ";
    in >> counter;
    in.ignore();
    for(size_t i = 1; i <= counter; ++i)
    {
        std::cout << "Введите автора(ФИО через пробел): ";
        std::getline(in,author);
        rhs.authors.push_back(author);
    }
    std::cout << "Введите цену книги: ";
    in >> rhs.price;
    std::cout << "Введите количество экземпляров: ";
    in >> rhs.count;


    return in;
}

/* Перегрузка оператора вывода */
std::ostream &operator<<(std::ostream & out, const Book & rhs)
{
    out << "\nISBN: " << rhs.ISBN;
    out << "\nНазвание книги: " << rhs.title;
    out << "\nАвторы:\n";
    for(size_t i = 0 ;i < rhs.authors.size(); ++i)
    {
        out << rhs.authors[i] << "\n" ;
    }
    out << "Цена: " << rhs.price;
    out << "\nКоличество экземпляров: " << rhs.count;

    return out;
}
