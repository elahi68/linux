#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void* print_message(void *);

int main()
{
	int it1,it2;
	pthread_t t1,t2;
	const char* ms1 = "thread1";
	const char* ms2 = "thread2";

	it1  = pthread_create(&t1,NULL,print_message,ms1);
	if(it1)
	{
		perror("Thread1");
	}

	it2 = pthread_create(&t2,NULL,print_message,ms2);
	if(it2)
	{
		perror("Thread2");
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	exit(EXIT_SUCCESS);
}
void* print_message(void* args)
{
	char* message = (char*)args;
	printf("%s\n",message);
}
