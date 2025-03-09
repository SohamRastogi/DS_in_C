#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* add;
};

struct node* start = NULL;
struct node* new1;
struct node* temp;
struct node* prev;
struct node* next;

void create();
void middle_dlt();
void display();

int main()
{
    create();

    middle_dlt();

    display();

    return 0 ;
}

void create()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> add = NULL;

    temp = start ;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);

    }
    temp = start;
    while (temp-> add != NULL)
    {
        temp = temp -> add;
    }
    temp -> add = start ;
    // temp = start ;
    return ;
}



void display()
{
    temp = start ;
    while (temp -> add != start)
    {
        printf("%d ",temp -> data);
        temp = temp -> add;
    }
    printf("%d",temp -> data);
    return ;
}




void middle_dlt()
{
    int pos;
    printf("enter the position : ");
    scanf("%d",&pos);

    temp = start;
    pos--;
    while(pos>1)
    {
        temp = temp -> add;
        pos--;
    }
    prev = temp ;
    new1 = prev -> add;
    next = new1 -> add;

    prev -> add = next ;

    printf("deleted element is : %d",new1 -> data);
    printf("\n");
    free(new1);

    return ;


}