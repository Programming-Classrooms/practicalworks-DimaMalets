#include "List.hpp"


template <typename T>
 struct List<T>::Node
{
    T data;
    Node* next;
    Node(T value):data(value),next(nullptr)
    {}
};

/* Конструктор по умолчанию */
template <typename T>
List<T>::List() : first(nullptr), last(nullptr)
{}

/* Конструктор копирования */
template <typename T>
List<T>::List(const List<T> & rhs)
{
    *this = rhs;
}

/* Проверка на пустоту */
template <typename T>
bool List<T>::isEmpty()
{
return first == nullptr;
}

/* Перегрузка оператора присваивания */
template <typename T>
List<T>& List<T>::operator=(const List<T> & rhs)
{
   if(rhs.first == nullptr){
    return *this;
   }
    Node* current = new Node(rhs.first->data);
    first = current;
    Node* temp =rhs.first;
    while(temp->next != nullptr){
        temp = temp->next;
        Node* NewEl = new Node(temp->data);
        current->next = NewEl;
        current = NewEl;
    }
    return *this;
}

/* Добавление в конец списка */
template <typename T>
void List<T>::pushBack(T value)
{
    Node* p = new Node(value);
    if(isEmpty()){
        first = p;
        last =p;
        return;
    }
    last->next = p;
    last = p;
}

/* Добавление в начало списка */
template <typename T>
void List<T>::pushFront(T value)
{
    Node* p = new Node(value);
    if(isEmpty()){
        first = p;
        last =p;
        return;
    }
    p->next = first;
    first = p;
}

/* Удаление первого элемента */
template <typename T>
void List<T>::popFront()
{
    if(isEmpty()){
        std::cerr << " List is empty";
        return;
    }
    Node* temp = first;
    first = first->next;
    delete temp;
}

/* Удаление последнего элемента */
template <typename T>
void List<T>::popBack()
{
    if(isEmpty()){
        std::cerr << " List is empty";
        return;
    }
    if(last == first){
        popFront();
        return;
    }
    Node* temp = first;
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = nullptr;
    delete last;
    last = temp;
}

/* Удаление элемента по значению */
template <typename T>
void List<T>::deleteValue(T value)
{
    if(isEmpty()){
        std::cerr << " List is empty";
        return;
    }
    else if(first -> data == value){
        popFront();
        return;
    }
    Node* slow = first;
    Node* fast = first -> next;
    while(fast && fast->data != value){
        slow = slow->next;
        fast = fast->next;
    }
    if(!fast){
        std::cout << "This element does not exist";
    }
    slow->next = fast ->next;
    delete fast;

}

/* Поиск элемнта с подсчетом числа сравнений */
template <typename T>
bool List<T>::find(T value)
{
    if(first ->data == value){
        std::cout << "Number of comparisons = 1";
        return true;
    }
    size_t counter =1;
    Node* fast = first;
    while(fast && fast->data != value){
        fast = fast->next;
        ++counter;
    }
    if(!fast){
        std::cout << "This element does not exist";
        return false;
    }
    std::cout << "Number of comparisons = " << counter;
    return true;
}

/* Просмотр списка с изменением значений */
template <typename T>
void List<T>::printAndChange()
{
    if(isEmpty()){
        std::cout  << " List is empty !!!";
        return;
    }
    Node* f = first;
    while(f != nullptr){
        std::cout << "Еhe value of the element = " << f-> data << '\n';
        std::cout << "Enter new value = ";
        std::cin >> f->data;
        f = f->next; 
    }
}

/* Просмотр списка */
template <typename T>
 void List<T>::printListWithCallback(void func(T)) const
{
    Node* current = first;
    while(current != nullptr){
        func(current->data);
        current = current -> next;
    }
}

/* Очистка списка */
template <typename T>
void List<T>::clear()
{
    while(first != nullptr){
        popFront();
    }
}

/* Деструктор */
template <typename T>
List<T>::~List()
{
    clear();
}
