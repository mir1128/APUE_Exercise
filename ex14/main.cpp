#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include <string>

int main(int argc, char *argv[])
{
	FILE *f = tmpfile();

	int fd = fileno(f);

	char path[PATH_MAX] = {0};
	if (fcntl(fd, F_GETPATH, path) < 0)
	{
		std::cout << "fcntl error: " << strerror(errno) << std::endl;
	} else
	{
		std::cout << std::string(path) << std::endl;
	}

	int a[] = {1, 2, 3};

	std::cout << fwrite(a, sizeof(int), 3, f) << std::endl;

	std::cout << tempnam(".", "hello") << std::endl;

	char p[] = "XXXX";
	char p1[]= "XXXXXXXXX";
	std::cout << mkdtemp(p) << std::endl;
	std::cout << mktemp(p1) << std::endl;

	int n;
	std::cin >> n;

	return 0;
}


