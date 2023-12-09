#include <iostream>
#include <stdint.h>
#include "Header.h"

int main() {
	uint64_t n = 4;
	double eps, a, b;
	enterLimits(b, a);
	enterEps(eps);
	choice(eps, a, b, n);
}
