#include "String.h"

int main()
{
	String* myStrClass = new String("Riun");

	std::cout << *myStrClass << "\n";

	*myStrClass = "Test String.";
	std::cout << *myStrClass << "\n";
	std::cout << myStrClass->Length() << "\n";


	std::cout << ((*myStrClass == "Riun") ? "True" : "False") << "\n";

	delete myStrClass;


	return 0;
}