#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

int a[100];
int n;
int count = 0;

pthread_mutex_t mutex;
sem_t sem1, sem2;

void *processA(void *mess){
    while(1){
        sem_wait(&sem2);
        pthread_mutex_lock(&mutex);

        int temp = rand();
        a[count++] = temp;
        printf("Sau khi them 1 phan tu vao mang a, Co %d phan tu trong mang a\n", count);

        pthread_mutex_unlock(&mutex);
        sem_post(&sem1);
    }
}

void *processB(void *mess){
    while(1){
        sem_wait(&sem1);
        pthread_mutex_lock(&mutex);

        if (count == 0){
            printf("Nothing in array a\n");
        }

        else{
            count--;
            
            if (count == 0){
                printf("Nothing in array a\n");
            }

            else{
                printf("Sau khi lay phan tu cuoi cung ra, co %d phan tu trong mang a\n", count);
            }
        }

        pthread_mutex_unlock(&mutex);
        sem_post(&sem2);
    }
}

int main(){
    scanf("%d", &n);

    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, n);
    pthread_t pA, pB;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&pA, NULL, &processA, NULL);
    pthread_create(&pB, NULL, &processB, NULL);

    while(1){}
    return 0;
}