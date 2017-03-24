#include <iostream>
#include "String.h"

int main (int argc, char*argv[]) {
	int x = 45689;
	Comet::String abc ("abc");
	Comet::String str("abc");
	str.Insert (0, "Now I know my ");
	str.Append ('s');

	str.Lower ();

	std::cout << str << std::endl;

	std::cout << str.Length () << std::endl;

	std::cout << str.Search ('w') << std::endl;

	std::cout << str.Substr (str.Search ("i know my"), 9);
}
