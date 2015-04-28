#include <unistd.h>
#include <iostream>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_CREAT | O_EXCL);

	if (fd < 0)
	{
		std::cout << "open error." << std::endl;
	}
	std::cout << "fd is : " << fd << std::endl;

	int fd1 = dup(fd);

	std::cout << "fd1 is : " << fd1 << std::endl;

	return 0;
}
