#include<unistd.h>
#include <stdio.h>
#include <pthread.h>
int A = 10;
int B = 10;
int C = 10;
pthread_mutex_t l;
pthread_mutex_t u;
pthread_mutex_t b;


void *X()
{
	int x;
	pthread_mutex_lock(&l);
	sleep(1);
	pthread_mutex_lock(&u);
	pthread_mutex_unlock(&u);
	pthread_mutex_lock(&b);
	pthread_mutex_unlock(&b);
	pthread_mutex_unlock(&l);

}

void *Y(){

	int y;
	pthread_mutex_lock(&u);
	sleep(1);
	pthread_mutex_lock(&l);
	pthread_mutex_unlock(&l);
	pthread_mutex_lock(&b);
	pthread_mutex_unlock(&b);
	pthread_mutex_unlock(&u);
}

void *Z(){


	int z;
	pthread_mutex_lock(&b);
	sleep(1);
	pthread_mutex_lock(&l);
	pthread_mutex_unlock(&l);
	pthread_mutex_lock(&u);
	pthread_mutex_unlock(&u);
	pthread_mutex_unlock(&b);
}

int main()
{
	pthread_mutex_init(&l,NULL);
	pthread_t p1,p2,p3;
	pthread_create(&p1,NULL,X,NULL);
	pthread_create(&p2,NULL,Y,NULL);
	pthread_create(&p3,NULL,Z,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
	

}