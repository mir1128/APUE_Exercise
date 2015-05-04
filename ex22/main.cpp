#include <unistd.h>
#include <stdio.h>
#include <iostream>

void output(char *chr)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);
	for (ptr = chr; (c = *ptr++) != 0;)
	{
		putc(c, stdout);
	}
}


int main()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		std::cout << "error" << std::endl;
	} else if (pid == 0)
	{
		output("this is the subprocess.\n");
	} else
	{
		output("this is the parent process.\n");
	}

	exit(0);
	return 0;
}
