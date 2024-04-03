#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>


class MyString
{
    private:
        char* pStr;
        size_t size;

    public:
        // Конструкторы
        MyString();
        MyString(size_t);
        MyString(const char*);
        MyString(const MyString&);
        MyString(MyString&&) noexcept;

        // Деструктор 
        ~MyString();

        // GET- метод
        size_t getSize() const;
        const char* getStr() const;

        // Оператор сложения
        MyString operator+(const MyString&) const;
        MyString operator+(const char*) const;

        // Операторы присваивания
        MyString& operator=(const MyString&);
        MyString& operator=(const char*);
        MyString& operator+=(const MyString&);
        MyString& operator+=(const char*);

        // Операторы сравнения
        bool operator!=(const MyString&) const;
        bool operator!=(const char*) const;
        bool operator<(const MyString&) const;
        bool operator<(const char*) const;

        // Очистка строки
        void clear();

        // Получение элемента
        char& operator[](size_t);

        // Операторы ввода и вывода
        friend std::ostream& operator<<(std::ostream&, const MyString&);
        friend std::istream& operator>>(std::istream&, MyString&);

    };

#endif // MYSTRING_HPP
