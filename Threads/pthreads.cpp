#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define SIZE 8
int inputNumbers[SIZE];

void printNumbers()
{
    for (int i = 0; i < SIZE; i++)
        printf("%d ", inputNumbers[i]);
}

void *runner(void *arg)
{
    printf("\nSecond thread ID is: %ld", (long)pthread_self());
    int temp = 0;

    for (int i = 0; i < SIZE; i++)
        for (int j = 1; j < SIZE - i; j++)
            if (inputNumbers[j - 1] > inputNumbers[j])
            {
                temp = inputNumbers[j - 1];
                inputNumbers[j - 1] = inputNumbers[j];
                inputNumbers[j] = temp;
            }

    pthread_exit(0);
}

int main()
{
    printf("First thread ID is: %ld\n", (long)pthread_self());
    pthread_t c_pid;

    
    cout << "Input 8 (eight) numbers: ";
    for (int i = 0; i < SIZE; i++)
        cin >> inputNumbers[i];

    cout << "Before thread execution the numbers array looked as follows: ";
    printNumbers();
    cout<<endl;
    // создание потока с сортировкой
    pthread_create(&c_pid, NULL, runner, NULL);

    printf("Second thread ID is: %ld\n", c_pid);

    // ждем пока поток закончится
    pthread_join(c_pid, NULL);

    cout << "\nAfter thread execution the numbers array looks as follows: ";
    printNumbers();
    cout<<endl;
}