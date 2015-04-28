#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP |S_IWGRP | S_IROTH | S_IWOTH)

int main()
{
	umask(0);

	if (creat("foo", RWRWRW) < 0 )
	{
		std::cout << strerror(errno) << std::endl;
	}

	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if (creat("bar", RWRWRW) < 0 )
	{
		std::cout << strerror(errno) << std::endl;
	}

	return 0;
}
