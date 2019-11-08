#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <unistd.h>


sem_t mutex;
sem_t wrt;
int readcount = 0;


void* writer(void* a){
	while(1){
		sem_wait(&wrt);
		printf("Writing... is performed\n");
		sem_post(&wrt);
		sleep(2);
	}
}

void* reader(void* a){
	while(1){
		sem_wait(&mutex);
		readcount++;
		if(readcount==1) sem_wait(&wrt);
		sem_post(&mutex);

		printf("Reading... \n");
		printf("Readers: %d\n\n",readcount );
		sleep(5);
		printf("Reading is performed\n");

		sem_wait(&mutex);
		readcount--;
		if(readcount==0) sem_post(&wrt);
		sem_post(&mutex);
		sleep(1);
	}
}


int main() 
{ 

	pthread_t thread_id[4]; 

	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);

	pthread_create(&thread_id[0], NULL, reader,0);
	pthread_create(&thread_id[1], NULL, writer,0);
	pthread_create(&thread_id[2], NULL, reader,0);
	pthread_create(&thread_id[3], NULL, reader,0);

	for (int i = 0; i < 4; i++) 
		pthread_join(thread_id[i], NULL); 
} 
