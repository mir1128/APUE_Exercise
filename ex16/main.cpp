#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <string>
#include <iostream>

int main()
{
	struct passwd *ptr;

	setpwent();

	while ((ptr = getpwent()) != NULL)
	{
		if (std::string(ptr->pw_name) == "jieliu")
		{
			break;
		}
	}
	endpwent();

	std::cout << ptr->pw_passwd << std::endl;
	std::cout << ptr->pw_uid << std::endl;
	return 0;
}

