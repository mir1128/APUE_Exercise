#include <iostream>
#include <unistd.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		std::cout << "fork error" << std::endl;
	} else if (pid == 0)
	{
		if (execl("/Users/jieliu/caller.sh", "caller.sh", "arg1", "arg2", NULL) < 0)
		{
			std::cout << "error : " << strerror(errno) << std::endl;
		}
		exit(0);
	}

	return 0;
}
