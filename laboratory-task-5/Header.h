#pragma once
#include <iostream>

void enterEps(double& eps);

void enterLimits(double& upper, double& lower);

double func1(double x);

double func2(double x);

double func3(double x);

double theFormAvgRec(double eps, double lower, double upper, double (*f)(double), uint64_t & numberOfSegments);

void choice(double eps, double lower, double upper, uint64_t numberOfSegments);