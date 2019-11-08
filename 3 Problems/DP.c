#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include <unistd.h>

#define N 5

int state[N]; 
int phil[N] = { 0, 1, 2, 3, 4 }; 

sem_t chopstick[N]; 
sem_t mutex;

void here(int i){
		
		// sem_wait(&mutex);
		printf("Philosopher %d wants to eat\n", i);
		sleep(2); 

		sem_wait(&chopstick[i]);
		sem_wait(&chopstick[(i+1)%5]);

		printf("Philosopher %d is eating\n", i );

		sleep(2); 

		sem_post(&chopstick[i]);
		sem_post(&chopstick[(i+1)%5]);
		
		// sem_post(&mutex);
		
		printf("Philosopher %d is thinking \n", i );
		sleep(2);

}

void* philospher(void* num) 
{ 
	while (1) { 
		int *a = num; 
		here(*a);
	} 
} 

int main() 
{ 

	int i; 
	pthread_t thread_id[N]; 

	sem_init(&mutex,0,1);

	for (i = 0; i < N; i++) 
		sem_init(&chopstick[i], 0, 1); 

	for (i = 0; i < N; i++) { 
		pthread_create(&thread_id[i], NULL, 
					philospher, &phil[i]); 
	} 

	for (i = 0; i < N; i++) 
		pthread_join(thread_id[i], NULL); 
} 
