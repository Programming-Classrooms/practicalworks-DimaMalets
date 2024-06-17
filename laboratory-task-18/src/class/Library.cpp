#include "Library.hpp"

/* Конструктор с параметрами */
Library::Library(const std::map<std::string,Book> & rhs):myLibrary(rhs)
{}

/* Конструктор копирования */
Library::Library(const Library & rhs):myLibrary(rhs.myLibrary)
{}

/* Добавление книги */
void Library::addBook()
{
    Book tmp;
    std::cin >> tmp;
    myLibrary.emplace(std::make_pair(tmp.getISBN(),tmp));
}

/* Найти книгу(по ISBN) */
void Library::seekBook()
{
    std::cout << "\nВведите ISBN книги, которую хотите найти ";
    std::string temp ;
    std::cin >> temp;
    if(myLibrary.count(temp))
    {
        auto it = myLibrary.find(temp);
        std::cout << "\nКнига с ISBN:" << temp; 
        std::cout << it->second;
    }
    else
    {
        std::cout << "Книги с таким ISBN нет в коллекции";
    }
}

/* Удалить книгу(по ISBN) */
void Library::deleteBook()
{
    std::cout << "\nВведите ISBN книги, которую хотите удалить ";
    std::string temp ;
    std::cin >> temp;
    if(myLibrary.count(temp))
    {
       myLibrary.erase(temp);
       std::cout << "Книга былва удалена";
    }
    else
    {
        std::cout << "Книги с таким ISBN нет в коллекции";
    }
}

/* Просмотреть список книг */
void Library::printListBook()
{
    if(myLibrary.empty())
    {
        throw std::invalid_argument ("Список книг пуст");
    }
    else
    {   std::cout << "\n\nСписок всех книг: ";
        for (const auto& [ISBN, Books] : myLibrary)
        std::cout << "\n" <<  Books;
    }
}

/* Добавить автора(по ISBN) */
void Library::addAuthor()
{
    std::cout << "\nВведите ISBN книги для которой хотите добавить автора ";
    std::string temp ;
    std::cin.clear();
    std::cin.ignore();
    std::cin >> temp;
    if(myLibrary.count(temp))
    {
      auto it = myLibrary.find(temp);
      it->second.addAuthor();
    }
    else
    {
        std::cout << "Книги с таким ISBN нет в коллекции";
    }
}

/* Удалить автора(по ISBN) */
void Library::deleteAuthor()
{
    std::cout << "\nВведите ISBN книги у которой хотите удалить автора ";
    std::string temp ;
    std::cin >> temp;
    if(myLibrary.count(temp))
    {
      auto it = myLibrary.find(temp);
      it->second.deleteAllAuthors();
    }
    else
    {
        std::cout << "Книги с таким ISBN нет в коллекции";
    }
}

bool cmp(const Book& a, const Book& b) 
{ 
    return a.getTitle() < b.getTitle(); 
} 

/* Сортировка по названиям книг */
void Library::sortByTtile()
{
    if(myLibrary.empty())
    {
        throw std::invalid_argument ("Список книг пуст");
    }
    std::vector<Book> tempList;
    for (const auto& [ISBN, Books] : myLibrary)
    {
        tempList.push_back(Books);
    }
    std::sort(tempList.begin(),tempList.end(),cmp);  
    std::cout << "\n\nСписок книг после сортировки по названиям: ";
    for(const auto& elem: tempList)
    {
        std::cout << "\n" << elem;
    }
}
