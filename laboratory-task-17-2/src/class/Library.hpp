 #ifndef LIBRARY_HPP
 #define LIBRARY_HPP

 #include "Book.hpp"

class Library 
{
    private:
    std::set <Book> Lib;

    public:
    /* Конструкторы */
    Library() = default;

     /* Деструктор */
    ~Library() = default;

    /* Чтение из файла */
    void readFile(std::istream&) ;

    /* Добавить книгу */
    void addBooks();

    /* Удалить книгу */
    void deleteBook();

    /* Поиск по названию */
    void findByTitle();

    /* Поиск по автору */
    void findByAuthor();

    /* Вывод информации о всех книгах */
    void printInfo();

};



 #endif // Library.hpp