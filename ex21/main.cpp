#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0)
	{
		std::cout << "fork error!" << std::endl;
	} else if (pid == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			sleep(2);
			std::cout << "parent id is : " << getppid() << std::endl;
		}
		exit(0);
	}

	int status;
	if (waitpid(pid, &status, 0) != pid)
	{
		std::cout << "error" << std::endl;
	}

	return 0;
}
