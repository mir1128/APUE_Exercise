#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>


#if 0
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "usage : ./ex09 filepath" << std::endl;
		return  0;
	}

	struct stat st;
	for (int i = 1; i < argc; ++i)
	{
		if (lstat(argv[i], &st) == -1)
		{
			std::cout << "lstat error message :  " << strerror(errno) << std::endl;
			continue;
		}

		if (S_ISLNK(st.st_mode))
		{
			std::cout << " S_ISLNK : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISREG(st.st_mode))
		{
			std::cout << " S_ISREG : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISDIR(st.st_mode))
		{
			std::cout << " S_ISDIR : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISCHR(st.st_mode))
		{
			std::cout << " S_ISCHR : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISBLK(st.st_mode))
		{
			std::cout << " S_ISBLK : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISFIFO(st.st_mode))
		{
			std::cout << " S_ISFIFO : " << argv[i] << std::endl;
			continue;
		}

		if (S_ISSOCK(st.st_mode))
		{
			std::cout << " S_ISSOCK : " << argv[i] << std::endl;
			continue;
		}

		std::cout << "others : " << argv[i] << std::endl;
	}
	return 8;
}

#endif
