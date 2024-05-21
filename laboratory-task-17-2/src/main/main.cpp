#include "../class/Library.hpp"
#include <string>


int main() 
{
   try
   {
   std::ifstream in ("src/files/test.txt");
   Library a;
   a.readFile(in);
   a.printInfo();
   a.addBooks();
   a.printInfo();
   a.deleteBook();
   a.printInfo();
   a.findByAuthor();
   a.findByTitle();

   }

   catch(std::invalid_argument e)
   {
      std::cout << e.what();
   }
}
