#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a[100];
int n;
int count = 0;

void *processA(void *mess){
    while(1){
        int temp = rand();
        a[count++] = temp;
        printf("Sau khi them 1 phan tu vao mang a, Co %d phan tu trong mang a\n", count);
    }
}

void *processB(void *mess){
    while(1){
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
    }
}

int main(){
    scanf("%d", &n);
    pthread_t pA, pB;

    pthread_create(&pA, NULL, &processA, NULL);
    pthread_create(&pB, NULL, &processB, NULL);

    while(1){}
    return 0;
}