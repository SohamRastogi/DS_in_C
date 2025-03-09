#include<stdio.h>
#include<stdlib.h>

#define N 5


struct node{
    int data;
    struct node* add;
};
struct node* start = NULL;
struct node* temp ;
struct node* new1 ;




void sort()
{
    temp = start;
    while(temp -> add != NULL){
        temp = temp -> add;
    }

    for(int i = 0 ; i < 4 ; i++){
        for(struct node* j = start ; j != temp ; j = j->add){
            new1 = j->add;
            if(j->data > new1->data){
                int temp;
                temp = new1->data;
                new1->data = j->data;
                j->data = temp;
            }
        }
    }
}



void display()
{
    temp = start;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->add;
    }
    return ;
}



int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

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

    sort();
    display();

    return 0 ;
}