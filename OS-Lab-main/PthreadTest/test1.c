#include "pthread.h"
#include "semaphore.h"
#include "stdio.h"

pthread_t pthread;
sem_t sem;
pthread_mutex_t mutex;

void *f(void *args) {
    sem_wait(&sem);
    printf("Hello World");
    sem_post(&sem);
    return (void *) NULL;
}

int main() {
    sem_init(&sem, 0, -1);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&pthread, NULL, f, NULL);
    pthread_join(pthread, NULL);
    sem_destroy(&sem);
    pthread_mutex_destroy(&mutex);
    return 0;
}