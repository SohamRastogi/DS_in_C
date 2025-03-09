#include<stdio.h>

#define N 5
int s1[5];
int s2[5];
int top1 = -1;
int top2 = -1;

int count = 0;

void push1(int x);
void push2(int x);
int pop1();
int pop2();

void enqueue(int x);
void dequeue();
void display();


int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);

    // display();
    // return 0 ;

    dequeue();
    enqueue(7);
    display();

    return 0 ;
}

void push1(int x){
    if(top1 == N-1) printf("stack_overflow");
    else{
        top1++;
        s1[top1] = x;
    }
    return ;
}

void push2(int x){
    if(top2 == N-1) printf("stack_overflow");
    else 
    {
        top2++;
        s2[top2] = x;
    }
    return ;
}

int pop1()
{
    int a;
    if(top1 == -1) printf("stack_empty");
    

    else 
    {
        a = s1[top1];
        top1--;
    }
    return a;
}

int pop2()
{
    int a;

    if(top2 == -1) printf("stack_empty");


    else 
    {
        a = s2[top2];
        top2--;
    }
    return a;

}


void enqueue(int x)
{
    if(top1 == N-1)  printf("queue_overflow");
    else 
    {
        push1(x);
        count++;
    }
    return ;
}

void display()
{
    printf("the elements of the queue are : ");
    for(int i = 0 ; i <= top1 ; i++){
        printf("%d ",s1[i]);
    }
    printf("\n");
    return ;
}

void dequeue()
{
    if(top1 == -1) printf("no elements to be dequeued as queue is empty\n");
    else 
    {
        while(top1 != -1){ 
        int a = pop1();
        push2(a);
        }
    
        int b = pop2();

        while(top2 != -1)
        {
            int a = pop2();
            push1(a);
        }

        return ;

     
    }

    
}