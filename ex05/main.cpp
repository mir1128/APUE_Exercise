#include <fcntl.h>
#include <iostream>
#include <unistd.h>

int main()
{
	int fd = creat("file.hole", O_CREAT | O_WRONLY);

	if (fd < 0 )
	{
		std::cout << "open failed." << std::endl;
	}

	char buf1[] = "abcdef";
	char buf2[] = "ABCDEF";

	int n = write(fd, buf1, sizeof(buf1));
	if (n != sizeof(buf1))
	{
		std::cout << "write buf1 failed." << std::endl;
	}

	if (lseek(fd, 123456, SEEK_SET) < 0 )
	{
		std::cout << "write buf1 error." << std::endl;
	}

	n = write(fd, buf2, sizeof(buf2));

	if (n != sizeof(buf1))
	{
		std::cout << "write buf2 failed." << std::endl;
	}

	return  0;
}