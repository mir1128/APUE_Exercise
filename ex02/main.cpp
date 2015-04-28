#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* thread_function(void*)
{
	printf("the child thread errno address is : %p\n", &errno);
	return NULL;
}

int main()
{
	printf("the main thread errno address is : %p\n", &errno);

	pthread_t t;

	int ret = pthread_create(&t, NULL, thread_function, NULL);

	pthread_join(t, NULL);

	char buf[32];
	int n = read(STDIN_FILENO, buf, 1024 );
	printf("the main thread errno address is : %p\n", &errno);
	return  0;
}

