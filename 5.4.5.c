#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

int x1, x2, x3, x4, x5, x6;
int y, z, v, w, ans;
sem_t sem0, sem1, sem2, sem3, sem4, sem5, sem6;

void *processInput(void *mess){
    printf("Enter x1: ");
    scanf("%d", &x1);
    printf("Enter x2: ");
    scanf("%d", &x2);
    printf("Enter x3: ");
    scanf("%d", &x3);
    printf("Enter x4: ");
    scanf("%d", &x4);
    printf("Enter x5: ");
    scanf("%d", &x5);
    printf("Enter x6: ");
    scanf("%d", &x6);
    sem_post(&sem0);
}
void *processA(void *mess){
    sem_wait(&sem3);
    w = x1 * x2;
    printf("w = %d\n", w);
    sem_post(&sem4);
}

void *processB(void *mess){ 
    sem_wait(&sem0);
    v = x3 * x4;
    printf("v = %d\n", v);
    sem_post(&sem1);
}

void *processC(void *mess){
        sem_wait(&sem1);
        y = v * x5;
        printf("y = %d\n", y);
        sem_post(&sem2);
}

void *processD(void *mess){
        sem_wait(&sem2);
        z = v * x6;
        printf("z = %d\n", z);
        sem_post(&sem3);
}

void *processE(void *mess){
        sem_wait(&sem4);
        y = w * y;
        printf("y = %d\n", y);
        sem_post(&sem5);
}

void *processF(void *mess){
        sem_wait(&sem5);
        z = w * z;
        printf("z = %d\n", z);
        sem_post(&sem6);
}

void *processG(void *mess){
        sem_wait(&sem6);
        ans = y + z;
        printf("ans = %d\n", ans);                                                                                                                                                                                                                                                                                                   
}

int main(){

    pthread_t pI, pA, pB, pC, pD, pE, pF, pG;
    sem_init(&sem0, 0, 0);
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);
    sem_init(&sem5, 0, 0);
    sem_init(&sem6, 0, 0);

    pthread_create(&pI, NULL, &processInput, NULL);
    pthread_create(&pA, NULL, &processA, NULL);
    pthread_create(&pB, NULL, &processB, NULL);
    pthread_create(&pC, NULL, &processC, NULL);
    pthread_create(&pD, NULL, &processD, NULL);
    pthread_create(&pE, NULL, &processE, NULL);
    pthread_create(&pF, NULL, &processF, NULL);
    pthread_create(&pG, NULL, &processG, NULL);

    while(1){}
    return 0;
}
