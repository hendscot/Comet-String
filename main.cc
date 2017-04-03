#include <iostream>
#include "String.h"

int main (int argc, char* argv[]) {
	Comet::String abc ("abc");
	Comet::String str("abc");
	str.Insert (0, "Now I know my ");
	str = str3;
	str.Lower ();

	std::cout << str << std::endl;

	std::cout << str.Length () << std::endl;

	if (str.Search("i know my") != Comet::String::strnf) {
		std::cout << "Item found" << std::endl;
	}

	std::cout << str.Substr (0, 3);
}
