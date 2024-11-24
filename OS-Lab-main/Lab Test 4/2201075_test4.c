#include <stdlib.h>
#include "pthread.h"
#include "stdio.h"

pthread_mutex_t mutex; // We will use this to lock the index assignment variable

char *inputArray;
char *outputArray;
int inputSize;
int N;

int currentIndex = 0;


typedef struct {
    int procNo;
} Args;

void *f(void *vargs) {
    Args *args = (Args *) vargs;
    int index;
    while (currentIndex < inputSize) {
        pthread_mutex_lock(&mutex);
        index = currentIndex++;
        pthread_mutex_unlock(&mutex);
        if (index >= inputSize) break;
        printf("Proc No: %d is holding index %d\n", args->procNo, index);
        if ('a' <= inputArray[index] && inputArray[index] <= 'z') {
            outputArray[index] = inputArray[index] - ('a' - 'A');

        } else if ('A' <= inputArray[index] && inputArray[index] <= 'Z') {
            outputArray[index] = inputArray[index] + ('a' - 'A');
        } else {
            outputArray[index] = inputArray[index];
        }

    }

    return (void *) NULL;

}


int main() {
    pthread_mutex_init(&mutex, NULL);
    printf("Enter the size of input string: ");
    scanf("%d ", &inputSize);
    inputArray = malloc(sizeof(char) * inputSize);
    outputArray = malloc(sizeof(char) * inputSize);

    printf("Enter the input string: ");
    scanf("%[^\n]", inputArray);
    printf("---%s----\n", inputArray);

    printf("Enter the number of threads(n): ");
    scanf("%d", &N);

    pthread_t threads[inputSize];
    for (int i = 0; i < N; i++) {
        Args *args = malloc(sizeof(Args));
        args->procNo = i;
        pthread_create(&threads[i], NULL, f, args);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("The output array is : %s\n", outputArray);

}
