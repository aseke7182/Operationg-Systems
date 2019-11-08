#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <unistd.h>


sem_t mutex;
sem_t full;
sem_t empty;

int item = 0;

void* consum(void* a){
	while(1){
		sem_wait(&full);
		sem_wait(&mutex);
		printf("item number %d was removed from buffer\n", item );
		item--;
		sem_post(&mutex);
		sem_post(&empty);
		sleep(2);
	}
}

void* produce(void* a) 
{ 
	while(1){
		item++;
		printf("trying to producing new item...%d\n", item);
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("item %d added to buffer\n", item);
		sem_post(&mutex);
		sem_post(&full);
		sleep(1);
	}
} 

int main() 
{ 

	int n; 
	scanf("%d", &n);
	pthread_t thread_id[1]; 

	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,n);

	pthread_create(&thread_id[0], NULL, consum,0);
	pthread_create(&thread_id[1], NULL, produce,0);

	for (int i = 0; i < 2; i++) 
		pthread_join(thread_id[i], NULL); 
} 
