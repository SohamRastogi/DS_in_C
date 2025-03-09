#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* add;
};

struct node* start = NULL;
struct node* temp;
struct node* new1;


void enqueue(int n);
void dequeue();
void display();

int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc(sizeof(struct node));

    start -> data = n;
    start -> add = NULL;
    temp = start;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);
    }

    

    // printf("%d",start->data);
    enqueue(5);
    enqueue(10);
    dequeue();
    display();

    // while(new1 != NULL)
    // {
    //     printf("%d ",new1->data);
    //     new1 = new1 -> add;
    // }

    // temp points to the last address.

    return 0 ;
}

void enqueue(int n)
{
    // from the temp end.
    new1 = (struct node*) malloc(sizeof(struct node));

    new1 -> data = n;
    new1 -> add = NULL;
    temp -> add = new1;
    temp = new1;

    return ;

}

void dequeue()
{
    new1 = start;
    start = start -> add;
    free(new1);

    return ;
}

void display()
{
    new1 = start;

    while(new1 != NULL){
        printf("%d ",new1->data);
        new1 = new1 -> add;
    }

    return ;
}