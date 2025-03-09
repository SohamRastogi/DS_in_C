#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* add;
};

struct node* top = NULL;
struct node* temp ;

void push(int x);
void display();
void peek();
void pop();


int main()
{
    push(2);
    push(3);
    push(10);
    display();
    peek();
    pop();
    peek();
    display();
    return 0 ;
}

void push(int x)
{
    struct node* new1;
    new1 = (struct node*) malloc(sizeof(struct node));

    new1 -> data = x;
    new1 -> add = top;
    top = new1;

    return ;
}

void display()
{
    temp = top;

    if(temp == NULL) printf("empty_stack");
    else 
    {
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> add;
        }
    }
    printf("\n");
    return ;
}

void peek()
{
    if(top == NULL) printf("empty_stack");
    else 
    {
        printf("the topmost element is : %d\n",top->data);
    }
    return ;
}

void pop()
{
    temp = top;
    int alpha = top -> data;

    top = top->add;
    printf("the deleted element is : %d",alpha);

    printf("\n");

    free(temp);

    return ;
}