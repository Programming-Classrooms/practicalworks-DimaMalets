#pragma once
#include <iostream>
void enterEps(double& eps);
void enterLimits(double& b, double& a);
double f1(double x);
double f2(double x);
double f3(double x);
double theFormAvgRec(double eps, double a, double b, double (*f)(double), uint64_t & n);
void choice(double eps, double a, double b, uint64_t n);
