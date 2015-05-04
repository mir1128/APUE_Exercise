#include <iostream>

int main()
{
	extern char** environ;

	for (int i = 0; environ[i] != NULL; ++i)
	{
		std::cout << environ[i] << std::endl;
	}
	return 0;
}
