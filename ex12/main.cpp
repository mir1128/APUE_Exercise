#include <sys/stat.h>
#include <iostream>

int main(int argc, char *argv[])
{
	struct  stat buf;
	for (int i = 1; i < argc; ++i)
	{
		printf("%s: ", argv[i]);

		if (stat(argv[i], &buf) < 0)
		{
			continue;
		}

		printf("dev = %d/%d\n", major(buf.st_dev), minor(buf.st_dev));
	}
	return  0;
}
