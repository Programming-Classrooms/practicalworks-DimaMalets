#include <iostream>
#include "Header.h"

void enterEps(double& eps) {
	std::cout << "Enter eps = ";
	std::cin >> eps;
}

void enterLimits(double& b, double& a) {
	std::cout << "Enter integration limits" << std::endl;
	std::cout << "Enter the upper limit = ";
	std::cin >> b;
	std::cout << "Enter the lower limit = ";
	std::cin >> a;
	if (b <= a) {
		std::cout << "invalid value" << std::endl;
		enterLimits(b, a);
	}
}

double f1(double x) {
	//f(x) = x * sqrt(1 + x)
	return x * sqrt(1 + x);
}

double f2(double x) {
	//f(x) = (asin(sqrt(x)))/(sqrt( x * (1 - x)))
	return (asin(sqrt(x))) / (sqrt(x * (1 - x)));
}

double f3(double x) {
	//f(x) = (pow(2,x))/(1 + pow(4,x))
	return (pow(2, x)) / (1 + pow(4, x));
}

double theFormAvgRec(double eps, double a, double b, double (*f)(double), uint64_t & n ) {
	double x = 0, h = 0;
	double resultFirst = 0;
	double resultSecond = eps +1;
	while (fabs(resultSecond - resultFirst) > eps) {
		resultFirst = resultSecond;
		resultSecond = 0;
		n *= 2;
		h = (b - a) / n;
		for (size_t i = 0; i < n; ++i) {
			x = a + i * h - h / 2;
			resultSecond += h * f(x);
		}
	}
	return resultSecond;
}

double theFormSimpson(double eps, double a, double b, double(*f)(double), uint64_t& n) {
	double  h = 0;
	double s1 = 0;
	double resultFirst = 0;
	double resultSecond = eps + 1;
	while (fabs(resultSecond - resultFirst) > eps) {
		resultFirst = resultSecond;
		resultSecond = 0;
		n *= 2;
		h = (b - a) /  n;
		for (size_t i = 1; i < n; i += 2) {
			s1 += 4 * f(a + i * h);
		}
		for (size_t i = 2; i < n; i += 2) {
			s1 += 2 * f(a + i * h);
		}
		resultSecond = h / 6 * s1;
	}
	return resultSecond ;
}

void valueIntegralSimpson(double eps, double a, double b, uint64_t n) {
	int16_t op;
	std::cout << "Enter the number of the integral you want to calculate = ";
	std::cin >> op;
	switch (op) {
	case 1:
		std::cout << "The value of the first integral = " << theFormAvgRec(eps, a, b, f1, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
		break;
	case 2:
		std::cout << "The value of the second integral = " << theFormAvgRec(eps, a, b, f2, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
	case 3:
		std::cout << "The value of the second integral = " << theFormAvgRec(eps, a, b, f3, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
	}
 }

void valueIntegralAvgRec(double eps, double a, double b, uint64_t n) {
	int16_t op;
	std::cout << "Enter the number of the integral you want to calculate = ";
	std::cin >> op;
	switch (op) {
	case 1:
		std::cout << "The value of the first integral = " << theFormAvgRec(eps, a, b, f1, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
		break;
	case 2:
		std::cout << "The value of the second integral = " << theFormAvgRec(eps, a, b, f2, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
	case 3: 
		std::cout << "The value of the second integral = " << theFormAvgRec(eps, a, b, f3, n) << '\n';
		std::cout << "The value is reached at n = " << n << '\n' << '\n';
	}
}

void choice(double eps, double a, double b, uint64_t n) {
	int16_t op;
	std::cout << "Choose which method to use to calculate the integral" << '\n';
	std::cout << "1 - The formula of average rectangles   0 - Simpson 's Formula" << '\n';
	std::cin >> op;
	switch (op) {
	case 0:
		valueIntegralSimpson(eps, a, b, n);
		break;
	case 1:
		valueIntegralAvgRec(eps, a, b, n);
		break;
	}
}