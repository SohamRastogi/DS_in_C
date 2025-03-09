#include<stdio.h>

#define MAX_SIZE 10
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue (int* queue , int* f, int* r){

    int n ;

    if ( ((*r)+1) % MAX_SIZE == *f){
        printf("queue_overflow");
    }
    // int n;
    else {
        // int n;
        printf("enter a number : ");
        scanf("%d",&n);
        if(*f == -1 && *r == -1){
            *f = 0;
            *r = 0;
        }
        else{
            *r = (*r + 1) % MAX_SIZE;
        }

    }
    queue[*r] = n ;
    printf("\n");
    return ;
}

void dequeue (int* queue, int* f, int* r){
    if(*f == -1 && *r == -1){
        printf("queue_underflow");
    }
    else {
        int alpha ;
        alpha = queue[*f];
        if(*f == *r){
            *f = -1;
            *r = -1;
        }
        else {
            *f = (*f + 1) % MAX_SIZE;

        }
        printf("dlted element is : %d",alpha);
    }
    printf("\n");
    return ;
}

void display (int* queue,int* f , int* r){

    if(*f == -1 && *r == -1){
        printf("empty_queue");
    }
    else {
        printf("elements of the queue are : ");
        printf("\n");
        for(int i = *f ; i != *r ; i = (i + 1) % MAX_SIZE){
            printf("%d ",queue[i]);
        }
        printf("%d",queue[*r]);
        
    }
    printf("\n");
    return ;
}

int main()
{

    int choice ;

    do{

    printf("\n----------circular queue menu----------");
    printf("\n");
    printf("1. enqueue");
    printf("\n");
    printf("2. dequeue");
    printf("\n");
    printf("3. display");
    printf("\n");
    printf("4.exit");
    printf("\n");
    printf("--------------------\n");

    printf("enter your choice : ");
    scanf("%d",&choice);

    switch(choice){
        case 1 : enqueue(queue,&front,&rear);
                 break;
        case 2 : dequeue (queue , &front , &rear);
                 break;
        case 3 : display (queue , &front , &rear);
                 break;
        case 4 : return 0 ;
    }
    
    } while (choice != 4);

    return 0 ;

}