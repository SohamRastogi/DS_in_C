// double ended queues

#include<stdio.h>

#define N 5
int deque[N];
int r = -1;
int f = -1;

    

void enqueuefront(int x)
{
    if(((r+1) % N) == f){
        printf("deque overflow \n");
        // printf("%d" , (r+1)%N);
       
    }
    else if( f == -1 && r == -1){
        f = 0;
        r = 0 ;
        deque[f] = x;
    }

    else if (f == 0){
        f = N-1;
        deque[f] = x;
    }
    else {
        f--;
        deque[f] = x;
    }

    return ;
}


void enqueuerear(int x){
    if((r+1) % N == f){
        printf("deque overflow");
    }

    else if(f == -1 && r == -1){
        f = 0 ; r = 0;
        deque[r] = x;
    }

    else {
        r = (r+1) % N;
        deque[r] = x;
    }

    return ;
}

void display()
{
    if(f==-1 && r == -1){
        printf("empty deque");
    }
    else {
        for(int i = f ; i != r ; i = ( i + 1 ) % N){
            printf("%d ",deque[i]);
        }
        printf("%d ",deque[r]);
    }
    return ;
}


void getfront(){
    if(f==-1 && r == -1){
        printf("empty_deque");
    }
    else 
    {
        printf("%d ",deque[f] );

    }
    return ;
}

void dequeuefront()
{
    if(f == - 1 && r == -1){
        printf("deque_empty");
    }
    else if (f==r){
        f = -1;
        r = -1;
    }
    else {
        f = (f+1) % N;
    }
    return ;

}

void dequeuerear(){
    if(f==-1 && r==-1){
        printf("empty_deque");
    }

    else if ( f == r){
        f = -1; r = -1;
    }
    else if (r == 0){
        r = N-1;
    }
    else {
        r--;
    }
    return ;
}



int main()
{

    // printf("%d", (r+1) % N);
    // printf("\n%d",f);


    enqueuefront(2);
    // enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    // display();
    // getfront();
    dequeuefront();
    dequeuerear();
    display();


    return 0 ;
}
