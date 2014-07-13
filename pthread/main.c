/*
 * main.c
 *
 *  Created on: 2013Äê10ÔÂ4ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <pthread.h>

#ifdef WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif

void *pp(void *arg)
{
	printf("%s\n", (char *) arg);
	return NULL;
}

int main()
{
	pthread_t pid;
	pthread_create(&pid, NULL, pp, "hello world");
	printf("I am main thread\n");
    pthread_join(pid,NULL);
	return 0;
}
