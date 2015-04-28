#include <unistd.h>
#include <iostream>

int main()
{
	const int BUFFER_SIZE = 16;

	char buf[BUFFER_SIZE] = {0};
	int n = 0;

	while ( (n = read(STDIN_FILENO, buf, BUFFER_SIZE))  > 0)
	{
		n = write(STDOUT_FILENO, buf, BUFFER_SIZE);
		if (n < BUFFER_SIZE)
		{
			std::cout << "error" << std::endl;
		}
	}

	return 0;
}
