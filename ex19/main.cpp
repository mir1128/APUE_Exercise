#include <unistd.h>
#include <iostream>

int main()
{
	int val = 11;

	int pid = fork();

	if (pid == 0)
	{
		val = 20;
	} else
	{
		sleep(2);
	}

	std::cout << "val: " << val << std::endl;

	return 0;
}