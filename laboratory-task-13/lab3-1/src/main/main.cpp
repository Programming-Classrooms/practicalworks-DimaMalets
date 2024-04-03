#include "../func/Fraction.hpp"


int main() {
	try {
		Fraction first(5, 13);
		Fraction second(7, 13);
		Fraction test1(second);

		Fraction test = first + second;
		std::cout << first << " + " << second << " = " << test;

		test = first - second;
		std::cout << std::endl << first << " - " << second << " = " << test;

		test = first * second;
		std::cout << std::endl << first << " * " << second << " = " << test;

		test = first / second;
		std::cout << std::endl << first << " / " << second << " = " << test;

		std::cout << "\nFraction -> double  " << first << " -> " << double(first);

		std::cout << std::endl << first << " < " << second << " " << (first < second ? "true" : "false") << "\n";
		
		std::cout << first << " > " << second << " " << (first > second ? "true" : "false") << "\n";

		std::cout  << first << " == " << second << " " << (first == second ? "true" : "false") << "\n";
		std::cout << test1 << " == " << second << " " << (test1 == second ? "true" : "false") << "\n";

		std::cout << first << " != " << second << " " << (first != second ? "true" : "false") << "\n";
		std::cout << test1 << " != " << second << " " << (test1 != second ? "true" : "false") << "\n";
	}	
	catch(std::invalid_argument e){
		std::cout << e.what();
	}
	catch ( std::runtime_error e) {
		std::cout << e.what();
	}
}
