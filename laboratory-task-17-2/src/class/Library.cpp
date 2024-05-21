#include "Library.hpp"


void Library::readFile(std::istream & in)
{
    Book a,b;
    int16_t count;
    while(in >> count)
    {
       a.readFile(in,count);
       this->Lib.insert(a);
        a = b;
    }
    
}

void Library::addBooks()
{
    Book a;
    a.addBook();
    Lib.insert(a);
}

void Library::deleteBook()
{
    std::cout << "\n\nВведите название книги которую хотите удалить: ";
    std::string findTitle;
    std::cin >> findTitle;
}

void Library::findByTitle()
{
    std::cout << "\n\nВведите название книги для поиска: ";
    std::string findTitle;
    std::cin >> findTitle;
    bool flag = false;
    for( const auto& elem: Lib)
    {
        if(elem.getTitle() == findTitle)
        {
            elem.printInfo();
            flag =true;
        }
    } 
    if(!flag)
    {
        std::cout << "Книги с таким названием нет в библиотеке";
    }
}

void Library::findByAuthor()
{
    bool flag = false;
    std::string findSurname;
    std::string findName;
    std::string findPatronymic;
    std::cout << "\nВведите фамилию автора: ";
    std::cin >> findSurname;
    std::cout << "\nВведите имя автора: ";
    std::cin >> findName;
    std::cout << "\nВведите отчество автора: ";
    std::cin >> findPatronymic;
    std::set<Author> temp; 
    for( const auto& elem: Lib)
    {
       temp = elem.getAuthors();
       for( const auto& elem: temp)
        {
            if(elem.getName() == findName && elem.getSurname() == findSurname && elem.getPatronymic()== findPatronymic)
            {
              flag = true;
              elem.printData();
            }
        }
    }   
      if(!flag)
    {
        std::cout << "Книги с таким автором нет в библиотеке";
    }
}

void Library::printInfo()
{
    std::cout << "\n\nСписок книг в библиотеке:\n";
    for(const auto& elem: Lib)
    {
        elem.printInfo();
    }
}
