#include<stdio.h>

#define MAX_SIZE 10 
int queue[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue (int* queue, int* front , int* rear){

    if(*rear == MAX_SIZE - 1){
        printf("queue_overflow");

    }
    else {
        int x;
        printf("enter a number : ");
        scanf("%d",&x);
        *rear = *rear + 1;
        queue[*rear] = x;
    }
    printf("\n");
    return ;
}

void dequeue (int* queue , int* front , int* rear){
    if(*front > *rear){
        printf("empty_queue");
    }
    else {
        int alpha ;
        alpha = queue[*front];
        printf("the removed element is : %d",alpha);
        *front = *front + 1;
    }
    printf("\n");
    return ;
}

void display (int* queue, int* front, int* rear){

    if( *front > * rear){
        printf("empty_queue");

    }
    else {
        for(int i = *rear ; i >= *front ; i--){
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
    return ;
}


int main()
{
    int choice ;

    do {

    printf("\n");
    printf("----------queue menu----------");
    printf("\n");
    printf("1. enqueue");
    printf("\n");
    printf("2. dequeue");
    printf("\n");
    printf("3. display");
    printf("\n");
    printf("4. exit");
    printf("\n");

    printf("enter choice : ");
    scanf("%d", &choice);

    switch (choice) {

        case 1 : enqueue (queue, &front, &rear);
                 break;
        case 2 : dequeue (queue, &front, &rear);
                 break;
        case 3 : display (queue, &front, &rear);
                 break;
        
    }
    } while (choice != 4);

    return 0 ;


}