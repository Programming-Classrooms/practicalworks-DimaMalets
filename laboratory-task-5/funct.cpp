#include <iostream> 
#include <math.h> 
#include "Header.hpp" 
 

void enterEps(double& eps) 
{ 
 std::cout << "Enter eps = "; 
 std::cin >> eps; 

 while (eps > 1 || eps < 0) { 
  std::cout << "Enter eps (eps > 1 || eps < 0) = "; 
  std::cin >> eps; 
 }
} 
 
void enterIntegrationLimits(double& upper, double& lower) 
{ 
 std::cout << "Enter integration limits" << std::endl; 

 std::cout << "Enter the upper limit = "; 
 std::cin >> upper; 

 std::cout << "Enter the lower limit = "; 
 std::cin >> lower; 

 while(upper <= lower) { 
 td::cout << "Enter integration limits" << std::endl; 

 std::cout << "Enter the upper limit = "; 
 std::cin >> upper; 

 std::cout << "Enter the lower limit = "; 
 std::cin >> lower; 
 } 
} 
 
double func1(double x) 
{ 
 return x * sqrt(1 + x); 
} 
 
double func2(double x) 
{ 
 return (asin(sqrt(x))) / (sqrt(x * (1 - x))); 
} 
 
double func3(double x) 
{ 
 return (pow(2, x)) / (1 + pow(4, x)); 
} 
 
double theFormAvgRec(double eps, double lower, double upper, double (*f)(double), uint64_t& numberOfSegments) 
{ 
 double x = 0, h = 0; 
 double resultFirst = 0; 
 double resultSecond = eps + 1; 

 while (fabs(resultSecond - resultFirst) > eps) {
  resultFirst = resultSecond; 
  resultSecond = 0; 
  numberOfSegments *= 2; 
  h = (upper - lower) / numberOfSegments; 

  for (size_t i = 0; i < numberOfSegments; ++i) { 
   x = lower + i * h - h / 2; 
   resultSecond += h * f(x); 
  } 
 } 
 return resultSecond; 
} 
 
double theFormSimpson(double eps, double lower, double upper, double(*f)(double), uint64_t& numberOfSegments) 
{ 
 double  h = 0; 
 double s1 = 0; 
 double resultFirst = 0; 
 double resultSecond = eps + 1; 

 while (fabs(resultSecond - resultFirst) > eps) { 
  resultFirst = resultSecond; 
  resultSecond = 0; 
  numberOfSegments *= 2; 
  h = (upper - lower) / numberOfSegments; 

  for (size_t i = 1; i < numberOfSegments; i += 2) { 
   s1 += 4 * f(lower + i * h); 
  } 

  for (size_t i = 2; i < numberOfSegments; i += 2) { 
   s1 += 2 * f(lower + i * h); 
  } 

  resultSecond = h / 6 * s1; 
 } 
 return resultSecond; 
} 
 
void valueIntegralSimpson(double eps, double lower, double upper, uint64_t numberOfSegments)
{
 int16_t op; std::cout << "Enter the number of the integral you want to calculate = ";
 std::cin >> op;

 switch (op) {
 case 1:
  std::cout << "The value of the first integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func1, numberOfSegments) << std::endl;
  std::cout << "The value is reached at number of segments = "; 
  std::cout << numberOfSegments;
  break; 

 case 2:
  std::cout << "The value of the second integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func2, numberOfSegments) << std::endl;
  std::cout << "The value is reached at number of segments = ";
  std::cout << numberOfSegments;
  break;
 case 3:

  std::cout << "The value of the second integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func3, numberOfSegments) << std::endl;
  std::cout << "The value is reached at number of segments = ";
  std::cout << numberOfSegments;
  break; 
  }
}
void valueIntegralAvgRec(double eps, double lower, double upper, uint64_t numberOfSegments)
{
 int16_t op; 
 std::cout << "Enter the number of the integral you want to calculate = ";
 std::cin >> op; 

 switch (op) {
 case 1:  
  std::cout << "The value of the first integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func1, numberOfSegments) << '\n';
  std::cout << "The value is reached at number of segments = ";
  std::cout << numberOfSegments;   
  break;

 case 2:  
  std::cout << "The value of the second integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func2, numberOfSegments) << '\n';
  std::cout << "The value is reached at number of segments = ";
  std::cout << numberOfSegments << std::endl << std::endl;  
  break;

 case 3: 
  std::cout << "The value of the second integral = ";
  std::cout << theFormAvgRec(eps, lower, upper, func3, numberOfSegments) << '\n';
  std::cout << "The value is reached at number of segments = ";
  std::cout << numberOfSegments << std::endl << std::endl;  
  break;
  }
 }

void choosingMethod(double eps, double lower, double upper, uint64_t numberOfSegments)
{ 
 int16_t op;
 std::cout << "Choose which method to use to calculate the integral\n";
 std::cout << "1 - The formula of average rectangles   0 - Simpson 's Formula\n";
 std::cin >> op; 

 switch (op) {
 case 0:  
   valueIntegralSimpson(eps, lower, upper, numberOfSegments);
   break; 

  case 1:
   valueIntegralAvgRec(eps, lower, upper, numberOfSegments);  
   break;
 }
}
 