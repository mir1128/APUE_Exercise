#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static void sig_int(int)
{
	printf("\nreceive a signal interupt.\n");
}

int main()
{
	signal(SIGINT, sig_int);
	int n;

	while (true)
	{
		std::cin >> n;
		if (n == 0)
		{
			break;
		}
	}
	return 0;
}

