#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <string.h>

int set_fl(int fd, int flags)
{
	int fl = fcntl(fd, F_GETFL, 0);

	if ( fl < 0 )
	{
		std::cout << "get fl error." << std::endl;
		return -1;
	}

	fl |= flags;
	if(fcntl(fd, F_SETFL, fl) < 0 )
	{
		std::cout << "set fl error." << std::endl;
		return -1;
	}

	return  0;
}

int main()
{
	const int BUFFER_SIZE = 4096;
	char buf[BUFFER_SIZE] = {0};

	int fd1 = open ("/Users/jieliu/Downloads/ubuntukylin-14.04.2-desktop-amd64.iso", O_RDONLY);

	if (fd1 < 0 )
	{
		std::cout << "open error!" << std::endl;
		return  -1;
	}

	int fd2 = open ("/Users/jieliu/Downloads/ubuntukylin-14.04.2-desktop-amd64.iso.bak", O_CREAT | O_TRUNC | O_WRONLY);
	if (fd2 < 0 )
	{
		std::cout << "open error 2! "<< strerror(errno) << std::endl;
		return  -1;
	}

	if (set_fl(fd2, O_SYNC) < 0)
	{
		std::cout << "set sync error." << std::endl;
		return -1;
	}

	int n = 0;
	while ( (n = read(fd1, buf, BUFFER_SIZE)) > 0 )
	{
		write(fd2, buf, n);
	}

	close(fd1);
	close(fd2);

	return 0;
}

