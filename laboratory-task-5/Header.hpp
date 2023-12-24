#ifndef  HEADER_HPP 
#define HEADER_HPP 

#include <iostream> 
 
void enterEps(double& eps); 
 
void enterIntegrationLimits(double& upper, double& lower); 
 
double func1(double x); 
 
double func2(double x); 
 
double func3(double x); 
 
double theFormAvgRec(double eps, double lower, double upper, double (*f)(double), uint64_t& numberOfSegments); 
 
double theFormSimpson(double eps, double lower, double upper, double(*f)(double), uint64_t& numberOfSegments); 
 
void choosIntegral(double eps, double lower, double upper, uint64_t numberOfSegments);

#endif  //Header.hpp  