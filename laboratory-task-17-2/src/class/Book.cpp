#include "Book.hpp"


void Book::readFile(std::istream& in, int16_t count)
{
    in >> UDK;
    Author temp;
    for(size_t i = 0; i < count; ++i)
    {
        temp.readFile(in,count);
        authors.insert(temp);
    }
    in >> title;
    in >> yearPublication;
}

void Book::addBook()
{
    std::cout << "\nВведите УДК книги: ";
    if(std::cin >> this->UDK)
    {}
    else
    {
        throw std::invalid_argument("УДК должкен состоять из цифр");
    }
    std::cout << "\nВведите количество авторов у книги: ";
    int16_t count;
    std::cin >> count;
    for(size_t i = 0; i < count; ++i)
    {
        Author a;
        a.addAuthor();
        authors.emplace(a);
    }
    std::cout <<"\nВведите название книги: ";
    std::cin >> this->title;
    std::cout <<"\nВведите год публикации: ";
    if(std::cin >> this->yearPublication)
    {}
    else
    {
        throw std::invalid_argument("Год публикации - это число");
    }
}

std::string Book::getTitle() const
{
    return this->title;
}

std::set<Author> Book::getAuthors() const
{
    std::set<Author> copy = this->authors;
    return copy;
}

bool Book::operator<(const Book & rhs) const
{
    return this->title < rhs.title;
}

bool Book::operator==(const Book & rhs) const
{
    return (this->title == rhs.title && this->UDK == rhs.UDK && this->yearPublication == rhs.yearPublication && this->authors == rhs.authors) ;
}

void Book::printInfo() const 
{
    std::cout << "\n\nУДК книги: " << this->UDK;
    for(const auto& elem: authors)
    {
        elem.printData();
    }
    std::cout << "\nНазвание книги: " << this->title;
    std::cout << "\nГод публикации: " << this->yearPublication;
}
