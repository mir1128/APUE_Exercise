#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>

int main()
{
	if (symlink("./makefile", "make_") < 0 )
	{
		std::cout << "create link error : " << strerror(errno) << std::endl;
	}

	char * buffer = new char[20];

	ssize_t n = readlink("./make_", (char*)buffer, 128);
	std::cout << buffer << "  " << n << std::endl;

	delete [] buffer;
	return 0;
}
