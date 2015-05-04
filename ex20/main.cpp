#include <iostream>
#include <unistd.h>

static void sig_child(int)
{
	printf("\nreceive a SIGCHLD interupt.\n");
}



int main()
{
	pid_t pid;
	if ( (pid = fork() ) < 0)
	{
		std::cout << "fork error." << std::endl;
	}

	signal(SIGCHLD, sig_child);

	if (pid == 0 )
	{
		std::cout << "this is the child process" << std::endl;
		return 0;
	}

	int n;
	while (std::cin >> n)
	{

		std::cout << "n*n is : " << n*n << std::endl;
	}

	return 0;
}
