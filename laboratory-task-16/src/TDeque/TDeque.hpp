#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>

template <typename TInfo>
class TDeque
{
protected:

struct TDequeItem // элемент дека
{
    TInfo Info; // данные
    TDequeItem* next; // указатель на следующий элемент
    TDequeItem* prev; // указатель на предыдущий элемент
    TDequeItem(TInfo data);// конструктор
    ~TDequeItem();  //деструктор
};
/* указатели на первый и последний элементы в списке */
TDequeItem* front; 

TDequeItem* rear; 

int size; // количество элементов в деке

void Erase(); // удаление всех элементов

void Clone(const TDeque&);

void DeleteItem(TDequeItem*); // удаление элемента по указателю

TDequeItem* PtrByIndex(int16_t)const; // указатель на элемент с заданным индексом

public:
TDeque(); // конструктор
TDeque(const TDeque &); // конструктор копирования
~TDeque(); // деструктор

void InsFront(TInfo); // включить элемент в голову дека

void InsRear(TInfo); // включить элемент в хвост дека

bool DelFront(); // исключить элемент из головы дека

bool DelRear(); // исключить элемент из хвоста дека

const TDeque& operator = (const TDeque &);// оператор присваивания

TDequeItem& operator [] (int16_t position); // operator []

bool findElement (TInfo data); // поиск элемента в очереди 

void exportInStream(std::ostream& stream) const; // вывод в поток 

const TInfo& GetByIndex(int16_t)const; // получить элемент по индексу

void SetByIndex(TInfo, int16_t); // изменить элемент по индексу

void BrowseWithModification(std::function<void(TInfo&)>); // просмотр с изменением элементов

void BrowseWithoutModification(std::function<void(TInfo)>) const; // просмотр без изменения элементов
};


#include "TDeque.inl"

#endif // TDeque.hpp
