#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* add;
};

struct node* start = NULL;
struct node* temp;
struct node* new1;

void create();
void search();

int main()
{
    create();
    search();

    return 0 ;
}

void create()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> add = NULL;

    temp = start;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while( n != 0 )
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n ;
        new1 -> add = NULL;

        temp -> add = new1;
        temp = new1 ;

        printf("do you want to continue ? ");
        scanf("%d",&n);
    }
    return ;
}



void search()
{

    
    int n;
    printf("enter element to be searched : \n");
    scanf("%d",&n);

    temp = start;
    int count = 1;

    int flag = 0;

    while (temp != NULL)
    {
        if(temp -> data == n)
        {
            printf("the element is at node number : %d",count);
            flag = 1;
            
            break;
        }
        
        count ++;
        temp = temp -> add;
    }
    if(flag == 0)
    {
        printf("element is not present in the linked list ");
    }
    return ;
}