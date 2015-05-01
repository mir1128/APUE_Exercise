#include <stdlib.h>
#include <iostream>

void func()
{
	std::cout << "hello world!" << std::endl;
}

int main()
{
	atexit(func);

	return 0;
}
