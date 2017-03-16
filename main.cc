#include <iostream>
#include "String.h"

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
