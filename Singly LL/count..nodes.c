#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node* add;
};

struct node* start = NULL;
struct node* new1;
struct node* temp;

void create();
int count ();



int main()
{
    create();
    int cnt = count();

    printf("\nthe number of nodes in the linked list are : %d",cnt);
    
    return 0;
}

void create()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> add = NULL;

    temp = start ;

    printf("do you want to continue : ");
    scanf("%d",&n);

    while( n != 0 )
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1 ;

        printf("do you want to continue : ");
        scanf("%d",&n);
    }
    return ;
}

int count()
{

    int ans = 0 ;

    if(start == NULL) printf("empty list");

    // int ans = 0;

    else 
    {
        temp = start;
        while(temp != NULL)
        {
            ans++;
            temp = temp -> add;
        }

    }
    return ans ;
}