#include <grp.h>
#include <iostream>

int main()
{
	struct group* p = getgrnam("staff");
	if (p == nullptr)
	{
		std::cout << strerror(errno) << std::endl;
		return  0;
	}

	char** name = p->gr_mem;
	while (*name != NULL)
	{
		std::cout << *name << std::endl;
		++name;
	}
	std::cout << "finish!"  << std::endl;
	return  0;
}
