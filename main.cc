#include <iostream>
#include "String.h"

int exp (int, int);

int main (int argc, char*argv[]) {
	int x = 45689;
	Comet::String str("abc");

	str.Insert(0, "Now I know my ");
	str.Append("s");
	str.Upper(14, 16);
	std::cout << str << std::endl;
	std::cout << str.Length() << std::endl;
	return 1;
}

int exp (int x, int power) {
	if (power == 0) return 1;
	else if (power == 1) return x;
	else {
		for (int i = 1; i < power; i++) { x *= x; };
		return x;
	}
}
