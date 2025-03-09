#include <stdio.h>

#define N 10
int q1[N];
int q2[N];
int front1 = 0;
int rear1 = -1;
int front2 = 0;
int rear2 = -1;




void enqueue1(int x){
    if(rear1 == N-1){
        printf("overflow");
    }
    else{
        rear1++;
        q1[rear1] = x;
    }
    return ;
}

void enqueue2(int x){
    if(rear2 == N-1){
        printf("empty");
    }
    else{
        rear2++;
        q2[rear2] = x;
    }
    return ;
}

int dequeue1()
{
    int a = q1[front1];
    front1++;
    return a;
}

int dequeue2()
{
    int a = q2[front2];
    front2++;
    return a;
}

int remover()
{
    int a = q2[rear2];
    rear2--;
    return a;
}

void push(int x);
void pop();
void display();




int main()
{
    push(5);
    push(7);
    push(-1);
    pop();
    push(2);

    display();

    return 0 ;
}

void push(int x){
    if(rear1 == N-1) printf("overflow");
    else{
        enqueue1(x);
    }
    return ;
}

void display()
{
    printf("the elements of the stack are : ");
    for(int i = rear1 ; i >= front1 ; i--){
        printf("%d ",q1[i]);
    }
    printf("\n");
    return ;
}

void pop()
{
    if(front1 > rear1 ) printf("empty");
    else{
        while(rear1 >= front1){
            int a = dequeue1();
            enqueue2(a);
        }
        
        int b = remover();

        while(rear2 >= front2){
            int a = dequeue2();
            enqueue1(a);
        }
    }
    return ;
}