#include <iostream>
#include "String.h"

int main (int argc, char*argv[]) {
	int x = 45689;
	Comet::String str("abc");
	str.Append ("LOMPO");
	str.Prepend ('A');
    std::cout << str << std::endl;
	return 1;
}
