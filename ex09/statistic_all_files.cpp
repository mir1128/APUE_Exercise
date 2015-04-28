#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <map>
#include <functional>

class FileVisitor
{
public:
	void visit(const std::string& name)
	{
		struct stat st;
		lstat(name.c_str(), &st);
		if (file_modes.count(st.st_mode) > 0)
		{
			file_modes[st.st_mode] += 1;
		} else
		{
			file_modes[st.st_mode] = 1;
		}
	}

	void dump()
	{
		std::map<int, int>::iterator it = file_modes.begin();
		for (; it != file_modes.end(); ++it)
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
	}

private:
	std::map<int, int> file_modes;
};

class FileTraversal
{
public:
	void traversal(const std::string& path, FileVisitor& visitor)
	{
		std::cout << path << std::endl;

		visitor.visit(path);

		struct  stat st;
		struct dirent *dir;

		if(lstat(path.c_str(), &st) < 0)
		{
			std::cout << "error : " << strerror(errno) << std::endl;
			return;
		}

		if (S_ISDIR(st.st_mode))
		{
			DIR * dirp = opendir(path.c_str());
			while((dir = readdir(dirp)) != NULL)
			{
				if (std::string(dir->d_name) == "." || std::string(dir->d_name) == "..")
					continue;

				if (path.back() != '/')
				{
					traversal(path + "/" +std::string(dir->d_name), visitor);
				} else{
					traversal(path + std::string(dir->d_name), visitor);
				}
			}
			closedir(dirp);
		}
	}
};

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "please input a path. " << std::endl;
		return 0;
	}

	FileTraversal fileTraversal;
	FileVisitor   fileVisitor;

	fileTraversal.traversal(argv[1], fileVisitor);
	fileVisitor.dump();
	return  0;
}
