#include "../Fraction/Fraction.hpp"
#include "../Mtrx/Mtrx.hpp"
#include "../List/List.hpp"


void demonstrationMethodsMtrx(){
		std::cout << " Demonstration Methods Matrix \n ";
		Mtrx first;
		Mtrx second;

		std::cin >> first;
		std::cout << '\n';
		std::cin >> second;
		std::cout << "\n first matrix\n = \n" << first;
		std::cout << "\nsecond matrix\n = \n" << second;

		Mtrx test = first + second;

		std::cout << "\n*****************************************************************************\n";
		std::cout <<'\n' << first << "\n + \n\n" << second << "\n = \n\n" << test;
		std::cout << "\n*****************************************************************************\n";

		test = first - second;
		std::cout << '\n' << first << "\n - \n\n" << second << "\n = \n\n" << test;
		std::cout << "\n*****************************************************************************\n";



		test = first * second;
		std::cout << '\n' << first << "\n * \n\n" << second << "\n = \n\n" << test;
		std::cout << "\n*****************************************************************************\n";

		test = 5 * first;
		std::cout << '\n' << " 5\n" << "\n * \n\n" << first << "\n = \n\n" << test;
		std::cout << "\n*****************************************************************************\n";

		test = first * 8;
		std::cout << '\n' << first << "\n * \n\n" << " 8\n" << "\n = \n\n" << test;
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << test << "\n / \n\n" << " 8\n" << "\n = \n\n";
		test /= 8;
		std::cout << test;
		std::cout << "\n*****************************************************************************\n";

		test *= 8;

		std::cout << '\n' << first << "\n == \n\n" << second << "\n = \n\n" << ((first==second) ? "true" : "false");
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n == \n\n" << test << "\n = \n\n" << ((first == test) ? "true" : "false");
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n != \n\n" << second << "\n = \n\n" << ((first != second) ? "true" : "false");
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n != \n\n" << test << "\n = \n\n" << ((first != test) ? "true" : "false");
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n += \n\n" << test << "\n = \n\n";
		first += test;
		std::cout << first;
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n -= \n\n" << test << "\n = \n\n";
		first -= test;
		std::cout << first;
		std::cout << "\n*****************************************************************************\n";

		std::cout << '\n' << first << "\n *= \n\n" << test << "\n = \n\n";
		first *= test;
		std::cout << first;
		std::cout << "\n*****************************************************************************\n";
}

void demonstrationMethodsFraction(){
		std::cout << " Demonstration Methods Fraction \n";
	std::cout << "\n*****************************************************************************\n";
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
		std::cout << "\n*****************************************************************************\n";
}

void demonstrationMethodsList(){
	std::cout << " Demonstration Methods List \n";
	std::cout << "\n*****************************************************************************\n";
	List<int> a;
		a.pushBack(3);
		a.pushBack(5);
		a.pushFront(-2);
		a.pushFront(1);
		std::cout << "List \n";
		List<int> b;
		b = a;
		a.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Method popBack \n";
		a.popBack();
		a.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Method popFront \n";
		a.popFront();
		a.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Method clear \n";
		a.clear();
		a.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Operator b = a \n";
		b.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Mehod delete with value  -2\n";
		b.deleteValue(-2);
		b.printListWithCallback([](int element){std::cout << element << " ";});
		std::cout << std::endl;
		std::cout << "Mehod print with change \n";
		b.printAndChange();
		b.printListWithCallback([](int element){std::cout << element << " ";});
		b.isEmpty()? std::cout << "\nList is empty" : std::cout << "\nList is not empty";
		std::cout << "\n*****************************************************************************\n";
}
int main() {
	try {
		demonstrationMethodsMtrx();
		demonstrationMethodsFraction();
		demonstrationMethodsList();
     	return 0;
	}	
	catch(std::invalid_argument e){
		std::cout << e.what();
	}
	catch ( std::runtime_error e) {
		std::cout << e.what();
	}
}
