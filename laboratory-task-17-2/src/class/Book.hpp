#ifndef BOOK_HPP
#define BOOK_HPP

#include "Author.hpp"
#include <set>
#include <vector>

class Book : protected Author
{
    private:

    int32_t UDK;
    std::set<Author> authors;
    std::string title;
    int32_t yearPublication;

    public:

    /* Конструкторы */
    Book() = default;

    /* Деструктор */
    ~Book() = default;

    /* Геттеры */
    std::string getTitle() const;
    std::set<Author> getAuthors()const;

    /* Чтение из файла */
    void virtual readFile(std::istream&, int16_t) override;

    /* Добавить книгу */
    void  addBook();

    /* Операторы сравнения */
    bool operator < (const Book&) const;
    bool operator == (const Book&) const;

     /* Вывод информации */
    void  printInfo() const;
};



#endif // Book.hpp