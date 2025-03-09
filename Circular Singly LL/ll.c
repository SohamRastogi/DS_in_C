#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node1{
    int data1 ;
    struct node1* add1;
};

struct node2{
    int data2;
    struct node2* add2;
};

struct node2* start2 = NULL;
struct node2* new2 ;
struct node2* temp2;

struct node1* start = NULL;
struct node1* new1;
struct node1* temp;

void create1();
void create2();

void display1();
void display2();

void sort1();
void sort2();

void merge_function();


int main()
{
    create1();

    create2();


    printf("list 1 entered : ");
    printf("\n");
    display1();

    printf("\n");
    
    printf("list 2 entered : ");
    printf("\n");
    display2();

    printf("\n");
    printf("\n");

    sort1();
    printf("sorted list 1 : ");
    printf("\n");
    display1();

    printf("\n");

    sort2();
    printf("sorted list 2 : ");
    printf("\n");
    display2();

    printf("\n");
    printf("\n");


    printf("required ans : \n");
    merge_function();

    return 0 ;
}

void create1()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node1*) malloc (sizeof(struct node1));

    start -> data1 = n;
    start -> add1 = NULL;

    temp = start ;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new1 = (struct node1*) malloc (sizeof(struct node1));

        new1 -> data1 = n;
        new1 -> add1 = NULL;
        temp -> add1 = new1;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);

    }
    temp = start;
    while (temp-> add1 != NULL)
    {
        temp = temp -> add1;
    }
    temp -> add1 = start ;
    // temp = start ;
    return ;
}



void display1()
{
    temp = start ;
    while (temp -> add1 != start)
    {
        printf("%d ",temp -> data1);
        temp = temp -> add1;
    }
    printf("%d",temp -> data1);
    return ;
}


void create2()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start2= (struct node2*) malloc (sizeof(struct node2));

    start2 -> data2 = n;
    start2 -> add2 = NULL;

    temp2 = start2 ;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new2 = (struct node2*) malloc (sizeof(struct node2));

        new2 -> data2 = n;
        new2 -> add2 = NULL;
        temp2 -> add2 = new2;
        temp2 = new2;

        printf("do you want to continue ? ");
        scanf("%d",&n);

    }
    temp2 = start2;
    while (temp2 -> add2 != NULL)
    {
        temp2 = temp2 -> add2;
    }
    temp2 -> add2 = start2 ;
    
    return ;
}



void display2()
{
    temp2 = start2 ;
    while (temp2 -> add2 != start2)
    {
        printf("%d ",temp2 -> data2);
        temp2 = temp2 -> add2;
    }
    printf("%d",temp2 -> data2);
    return ;
}

void sort1()
{
    temp = start;

    int count = 0;
    temp = temp -> add1;

    while(temp != start)
    {
        count++;
        temp = temp -> add1;
    }

    count++;

    temp = start;

    int min = __INT_MAX__;
    struct node1* min_node = NULL;

    int alpha = temp-> data1;

    temp = temp -> add1;


    while(temp != start)
    {
        if(temp -> data1 < min)
        {
            min = temp -> data1;
            min_node = temp;
            temp = temp -> add1;
            
        }
        else{
            temp = temp -> add1;
        }
    }

    // temp = start;
    // printf("%d ",temp -> data1);
   

    if(alpha > min)
    {
        temp = start;
        int tempo;
        tempo = temp -> data1;
        temp -> data1 = min_node -> data1;
        min_node -> data1 = tempo;
    }

     
    // printf("%d ",start -> data1);
    temp = start; 
    temp = temp -> add1;

    for(int i = 0 ; i < count - 2 ; i ++)
    {
        for(struct node1* j = temp ; j->add1!=start ; j = j -> add1){
            new1 = j -> add1;
            if(j -> data1 > new1 -> data1){
                int temp;
                temp = new1 -> data1;
                new1 -> data1 = j -> data1;
                j -> data1 = temp;
            }
        }
    }
    
    return ;
}


void sort2()
{
    temp2 = start2;

    int count = 0;
    temp2 = temp2 -> add2;

    while(temp2 != start2)
    {
        count++;
        temp2 = temp2 -> add2;
    }

    count++;

    temp2 = start2;

    int min = __INT_MAX__;
    struct node2* min_node = NULL;

    int alpha = temp2-> data2;

    temp2 = temp2 -> add2;


    while(temp2 != start2)
    {
        if(temp2 -> data2 < min)
        {
            min = temp2 -> data2;
            min_node = temp2;
            temp2 = temp2 -> add2;
            
        }
        else{
            temp2 = temp2 -> add2;
        }
    }

    // temp = start;
    // printf("%d ",temp -> data1);
   

    if(alpha > min)
    {
        temp2 = start2;
        int tempo;
        tempo = temp2 -> data2;
        temp2 -> data2 = min_node -> data2;
        min_node -> data2 = tempo;
    }

     
    temp2 = start2; 
    temp2 = temp2 -> add2;

    for(int i = 0 ; i < count - 2 ; i ++)
    {
        for(struct node2* j = temp2 ; j->add2!=start2 ; j = j -> add2){
            new2 = j -> add2;
            if(j -> data2 > new2 -> data2){
                int temp;
                temp = new2 -> data2;
                new2 -> data2 = j -> data2;
                j -> data2 = temp;
            }
        }
    }

    return ;

}

void merge_function()
{
    temp = start;
    temp2 = start2;

    // printing such that minimum element of first list, then min element of second list, then next min of first ...... ans so on ......

    printf("%d ",temp -> data1);
    printf("%d ",temp2 -> data2);

    temp = temp -> add1;

    temp2 = temp2 -> add2;

    while(temp != start && temp2 != start2)
    {
        printf("%d %d ",temp -> data1 , temp2 -> data2);
        temp = temp -> add1;
        temp2 = temp2 -> add2;
    }
    // also printing remaining elements if any :
    while(temp != start)
    {
        printf("%d ",temp -> data1);
        temp = temp -> add1;

    }
    while(temp2 != start2)
    {
        printf("%d ",temp2 -> data2);
        temp2 = temp2 -> add2;
    }

    return ;

}