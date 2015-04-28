#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("the processid is %d, and the group id is %d\n", getpid(), getgid());
	return 0;
}

