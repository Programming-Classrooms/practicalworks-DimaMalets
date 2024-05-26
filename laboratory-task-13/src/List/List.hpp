#ifndef LIST_HPP
#define LIST_HPP


#include <iostream>
#include <exception>

template <typename T>
class List
{
private:
struct Node;
Node* first;
Node* last;

public:

// Конструктр по умолчанию
List();

// Конструктор копирования
List(const List<T>&);

// Деструктор
~List();

// Проверка на пустоту списка
bool isEmpty();

// Перегрузка оператора присваивания
List<T>& operator= (const List<T>&);

// Вставка элемента в конец списка
void pushBack(T);

// Вставка элемента в начало списка
void pushFront(T);

// Удаление элемента в начале списка
void popFront();

// Удаление элемента в конце списка
void popBack();

// Удаление элемента по значению
void deleteValue(T);

// Поиск элемента с количеством итераций
bool find(T);

// Просмотр списка
void printAndChange();

// Просотр списка с использование callback-функции
 void printListWithCallback(void func(T)) const;

// Очистка листа
void clear();

};

#include "List.inl"
#endif //LIST_HPP
