#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
	FILE* f = freopen("./testreopen", "w+", stdout);

	int n;
	std::cin >> n;

	return 0;
}

