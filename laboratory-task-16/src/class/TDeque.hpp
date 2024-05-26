#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>
#include <cstring>
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
virtual ~TDeque(); // деструктор

void Print();

void InsFront(TInfo); // включить элемент в голову дека

void InsRear(TInfo); // включить элемент в хвост дека

bool DelFront(); // исключить элемент из головы дека

bool DelRear(); // исключить элемент из хвоста дека

const TDeque& operator = (const TDeque &);// оператор присваивания

const TInfo& GetByIndex(int16_t)const; // получить элемент по индексу

void SetByIndex(TInfo, int16_t); // изменить элемент по индексу

void BrowseWithModification(std::function<void(TInfo&)>); // просмотр с изменением элементов

void BrowseWithoutModification(std::function<void(TInfo)>) const; // просмотр без изменения элементов
};

template <typename TInfo>
TDeque<TInfo>::TDequeItem::TDequeItem(TInfo data):
Info(data), next(nullptr), prev(nullptr)
{}

template <typename TInfo>
TDeque<TInfo>::TDequeItem::~TDequeItem()
{}


template <>
TDeque<char*>::TDequeItem::~TDequeItem()
{
    if(this->Info != nullptr)
    {
        delete [] this->Info;
    }
}

template <>
TDeque<char*>::TDequeItem::TDequeItem(char* data):
next(nullptr), prev(nullptr)
{
    this->Info = new char[strlen(data) + 1];
    strcpy(this->Info,data);
}

// удаление всех элементов
template <typename TInfo>
void TDeque<TInfo>::Erase()
{
     TDequeItem* p  = rear;
    while(p != nullptr)
    {
       delete rear;
       rear = p->prev;
       p = rear;
    }
    this->size =0;
}


template <typename TInfo>
void TDeque<TInfo>::Clone(const TDeque & rhs)
{
    TDequeItem* temp = rhs.front;
    while(temp != nullptr)
    {
        this->InsRear(temp->Info);
        temp = temp->next;
        this->size++;
    }
}

// удаление элемента по указателю
template <typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem * ptr)
{
    TDequeItem* slow = front;
    TDequeItem* fast = front->next;
    if(front == ptr)
    {
        DelFront();
        return;
    }
    if(rear == ptr)
    {
        DelRear();
        return;
    }
    while(fast != ptr && fast != nullptr)
    {
        slow = slow->next;
        fast= fast->next;
    }
    if(fast == nullptr)
    {
        throw std::runtime_error ("ptr not found");
    }
    else
    {
        slow->next = fast->next;
        delete fast;
        slow = nullptr;
        delete slow;
    }
}

// указатель на элемент с заданным индексом
template<typename Tinfo>
typename TDeque<Tinfo>::TDequeItem* TDeque<Tinfo>::PtrByIndex(int16_t indx) const
{
    int16_t counter = 0;
   TDequeItem* temp = front;
   while(temp != nullptr && counter < indx)
   {
     temp =  temp->next;
     counter++;
   }
   if(temp == nullptr)
   {
    throw std::invalid_argument ("Элемента с таким индексом нет");
   }
   else
   {
   return temp;
   }
}

// конструктор
template <typename TInfo>
TDeque<TInfo>::TDeque() : size(0), front(nullptr), rear(nullptr)
{}

// конструктор копирования
template <typename TInfo>
TDeque<TInfo>::TDeque(const TDeque &rhs)
{
    this->Clone(rhs);
}

// деструктор
template <typename TInfo>
TDeque<TInfo>::~TDeque()
{
    this->Erase();
}

template <typename TInfo>
void TDeque<TInfo>::Print()
{
 TDequeItem* temp = front;
    if(temp == nullptr)
    {
        std::cout << "Deque is empty!";
    }
    else
    {
        while(temp != nullptr)
        {
            std::cout << temp->Info << " ";
            temp = temp->next;
        }
    }
}

// включить элемент в голову дека
template <typename TInfo>
void TDeque<TInfo>::InsFront(TInfo data)
{
    TDequeItem* newEl =  new TDequeItem(data);
    if(front == nullptr)
    {
        this->front = newEl;
        this->rear = newEl;
        this->size++;
    }
    else
    {
        TDequeItem* temp = front;
        this->front = newEl;
        this-> front->next = temp;
        this->size++;
        temp = nullptr;
        delete temp; 
    }
}

// включить элемент в хвост дека
template <typename TInfo>
void TDeque<TInfo>::InsRear(TInfo data)
{
    TDequeItem* newEl =  new TDequeItem(data);
    if(front == nullptr)
    {
        this->front = newEl;
        this->rear = newEl;
        this->size++;
    }
    else
    {
        TDequeItem* temp = this->rear;
        this->rear->next = newEl;
        this->rear = newEl;
        this->rear->prev = temp;
        this->size++;
    }
}

// исключить элемент из головы дека
template <typename TInfo>
bool TDeque<TInfo>::DelFront()
{   
    if(front == rear)
    {
        front = nullptr;
        rear = nullptr;
        (--size);
        return true;
    }
    if(front->next != nullptr)
    {
        TDequeItem* temp = front->next;
        delete front;
        front = temp;
        (--size);
        return true;
    }
    return false;
}

// исключить элемент из хвоста дека
template <typename TInfo>
bool TDeque<TInfo>::DelRear()
{
    if(front == rear)
    {
        front = nullptr;
        rear = nullptr;
        (--size);
        return true;
    }
    if(rear->prev != nullptr)
    {
        TDequeItem* temp = rear->prev;
        delete rear;
        temp->next = nullptr;
        this-> rear = temp;
        (--size);
        return true;
    }
    return false;
}

// оператор присваивания
template <typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque & rhs)
{   
    this->Clone(rhs);
    return *this;
}

// получить элемент по индексу
template <typename TInfo>
const TInfo &TDeque<TInfo>::GetByIndex(int16_t indx) const
{
  return PtrByIndex(indx)->Info;
}

// изменить элемент по индексу
template <typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo data, int16_t indx)
{
   PtrByIndex(indx)->Info = data;
}

// просмотр с изменением элементов
template <typename TInfo>
void TDeque<TInfo>::BrowseWithModification(std::function<void(TInfo &)> func)
{
    TDequeItem* temp = this->front;
    while (temp != nullptr) {
        func(temp->Info);
        temp = temp->next;
    }
}

// просмотр без изменения элементов
template <typename TInfo>
void TDeque<TInfo>::BrowseWithoutModification(std::function<void(TInfo)> func) const
{
    TDequeItem* temp = this->front;
    while (temp != nullptr) {
    func(temp->Info);
    temp = temp->next;
    }
}

#endif // TDeque.hpp
