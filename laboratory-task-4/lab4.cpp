/* 
 Вариант 6 
 В целочисленной прямоугольной матрице найти: 
 - сумму элементов в тех строках, которые не содержат нулей; 
 - переставить местами 1-ый и последний столбец, 2-ой и предпоследний и т. д. 
*/ 
 
 
#include <iostream> 
#include <iomanip> 
 
void enterSize(int16_t& size_i, int16_t& size_j) 
{ 
 std::cout << "Enter the number of rows and columns " << '\n'; 
 std::cin >> size_i; 
 std::cin >> size_j; 
 if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns (NATURAL NUMBER!!!!)" << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
  if (size_i <= 0 || size_j <= 0) { 
  std::cout << "Enter the number of rows and columns " << '\n'; 
  std::cin >> size_i; 
  std::cin >> size_j; 
 } 
} 
 
void newMemory(int32_t**& matrix, int16_t size_i, int16_t size_j) 
{ 
 matrix = new int* [size_i]; 
 for (size_t i = 0; i < size_i; ++i) { 
  matrix[i] = new int[size_j]; 
 } 
} 
 
void random(int32_t** matrix, int16_t size_i, int16_t size_j) 
{ 
 int16_t  first = 0, last = 0; 
 std::cout << "indicate boundaries from = "; 
 std::cin >> first; 
 std::cout << "before = "; 
 std::cin >> last; 
 if (first >= last) { 
  std::cout << "incorrect range"; 
 } 
 else { 
  for (size_t i = 0; i < size_i; ++i) { 
   for (size_t j = 0; j < size_j; ++j) { 
    int16_t temp = rand() % (last  - first ) + first ; 
    matrix[i][j] = temp; 
   } 
  } 
 } 
} 
 
void inputElements(int32_t** matrix, int16_t size_i, int16_t size_j) 
{ 
 for (size_t i = 0; i < size_i; ++i) { 
  for (size_t j = 0; j < size_j; ++j) { 
   std::cin >> matrix[i][j]; 
  } 
 } 
} 
 
void selctionInput(int32_t** matrix, int16_t size_i, int16_t size_j) 
{ 
 size_t op; 
 std::cout << " random - 1, keyboard input - 0 \n"; 
 std::cin >> op; 
 switch (op) 
 { 
 default:std::cout << "1 and 0"; 
  break; 
 case 0: 
  inputElements(matrix, size_i, size_j); 
  break; 
 case 1: 
  random(matrix, size_i, size_j); 
  break; 
 
 } 
} 
 
void sumElementsStr(int32_t** matrix, int16_t size_i, int16_t size_j) { 
 int64_t sum = 0; 
 bool isExist = true; 
 size_t counter = 0; 
 for (size_t i = 0; i < size_i; ++i) { 
  for (size_t j = 0; j < size_j; ++j) { 
   if (matrix[i][j] != 0) { 
    sum += matrix[i][j]; 
   } 
   else { 
    ++counter; 
    isExist = false; 
    break; 
   } 
  } 
  if (isExist) { 
   std::cout << " sum str - " << i + 1 << " = " << sum << std::endl; 
  } 
  sum = 0; 
 } 
 if (counter == size_i) { 
  std::cout << "All lines contain 0" << std::endl; 
 } 
 std::cout << std::endl; 
} 
 
void swapColumns(int32_t** matrix, int16_t size_i, int16_t size_j) 
{ 
 for (size_t i = 0; i < size_i; ++i) { 
  for (size_t j = 0; j < size_j / 2; ++j) { 
   std::swap(matrix[i][j], matrix[i][size_j - 1 - j]); 
  } 
 } 
} 
 
void outputMatrix(int32_t** matrix, int16_t size_i, int16_t size_j)
{
 for (size_t i = 0; i < size_i; ++i) {  
	for (size_t j = 0; j < size_j; ++j) {
   std::cout << std::setw(3) << matrix[i][j] << " ";  }
  std::cout << std::endl; }
 std::cout << '\n';}

void clearingMemory(int32_t**& matrix, int16_t size_i)
{ 
  for (size_t i = 0; i < size_i; ++i) {
  delete[] matrix[i]; 
  }
 delete[] matrix;
 }

int main() { 
int16_t size_i = 0, size_j = 0;
enterSize(size_i, size_j); 
int32_t** matrix = nullptr;
newMemory(matrix, size_i, size_j); 
selctionInput(matrix, size_i, size_j);
system("cls"); 
outputMatrix(matrix, size_i, size_j);
sumElementsStr(matrix, size_i, size_j); 
swapColumns(matrix, size_i, size_j);
outputMatrix(matrix, size_i, size_j); 
clearingMemory(matrix, size_i);
}
