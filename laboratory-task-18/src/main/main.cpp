#include "../class/Library.hpp"

int main()
{
  try
  {
    Library a;
    a.addBook();
    a.addBook();
    a.addBook();
    a.printListBook();
    a.addAuthor();
    a.printListBook();
    a.seekBook();
    a.deleteBook();
    a.printListBook();
    a.addAuthor();
    a.printListBook();
    a.deleteAuthor();
    a.printListBook();
    a.sortByTtile();
    return 0;
  }
  catch(std::invalid_argument e)
  {
    std::cerr << e.what() << '\n';
  }
  
}
