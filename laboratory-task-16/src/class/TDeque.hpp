#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>

template <typename TInfo>
class TDeque
{
protected:

struct TDequeItem // элемент дека
{
    TInfo Info; // данные
    TDequeItem* next; // указатель на следующий элемент
    TDequeItem* prev; // указатель на предыдущий элемент
    TDequeItem(TInfo data ,TDequeItem* previ = nullptr, TDequeItem * current = nullptr):
    Info(data), next(current), prev(previ)
    {
        if(previ != nullptr){
            previ->next = this;
        }
        if(current != nullptr){
            current->prev = this;
        }
    }
};
/* указатели на первый и последний элементы в списке */
TDequeItem* front; 

TDequeItem* rear; 

int size; // количество элементов в деке

void Erase(); // удаление всех элементов

void Clone(const TDeque&);

void DeleteItem(TDequeItem*); // удаление элемента по указателю

void* PtrByIndex(unsigned)const; // указатель на элемент с заданным индексом

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

const TInfo& GetByIndex(unsigned)const; // получить элемент по индексу

void SetByIndex(TInfo, unsigned); // изменить элемент по индексу

void Browse(void(TInfo&)); // просмотр с изменением элементов

void Browse(void(TInfo)) const; // просмотр без изменения элементов
};

template <typename TInfo>
inline void TDeque<TInfo>::Erase()
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
inline void TDeque<TInfo>::Clone(const TDeque & rhs)
{
    TDequeItem* temp = rhs.front;
    while(temp != nullptr)
    {
        this->InsRear(temp->Info);
        temp = temp->next;
        this->size++;
    }
}

template <typename TInfo>
inline void TDeque<TInfo>::DeleteItem(TDequeItem * ptr)
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

template <typename TInfo>
inline TDeque<TInfo>::TDeque() : size(0), front(nullptr), rear(nullptr)
{}

template <typename TInfo>
inline TDeque<TInfo>::TDeque(const TDeque &rhs)
{
    this->Clone(rhs);
}

template <typename TInfo>
inline TDeque<TInfo>::~TDeque()
{
    this->Erase();
}

template <typename TInfo>
inline void TDeque<TInfo>::Print()
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

template <typename TInfo>
inline void TDeque<TInfo>::InsFront(TInfo data)
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

template <typename TInfo>
inline void TDeque<TInfo>::InsRear(TInfo data)
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
        TDequeItem* temp = rear;
        this->rear->next = newEl;
        this->rear = newEl;
        this->rear->prev = temp;
        this->size++;
    }
}

template <typename TInfo>
inline bool TDeque<TInfo>::DelFront()
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

template <typename TInfo>
inline bool TDeque<TInfo>::DelRear()
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

template <typename TInfo>
inline const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque & rhs)
{
    return *this->Clone(rhs);
}

template <typename TInfo>
inline void TDeque<TInfo>::Browse(void(TInfo)) const
{
}


#endif // TDeque.hpp
