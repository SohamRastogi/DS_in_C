#include<stdio.h>

#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;

void push ()
{
    if(top == MAX_SIZE-1){
        printf("stack_overflow");

    }
    else{
        int n;
        printf("enter a number : ");
        scanf("%d",&n);
        top++;
        stack[top] = n ;
    }
    printf("\n");
    return  ;
}

void pop ()
{
    if(top == -1){
        printf("stack_underflow ");
    }
    else {
        int alpha = stack[top] ;
        top--;
        printf("popped element is : %d",alpha);
    }
    printf("\n");
    return ;
}

void display()
{
    if(top==-1){
        printf("stack_underflow");

    }
    else {
        printf("elements are : \n");
        for(int i = top ; i>= 0 ; i--){
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
    return ;
}

int main()
{
    int choice ; 

    do{

    printf("----------stack menu----------\n");
    printf("1.push \n");
    printf("2. pop \n");
    printf("3. delete \n");
    printf("4. exit");
    printf("\n------------------------------");
    printf("\n");
    printf("enter your choice : ");
    scanf("%d",&choice);

    switch( choice )
    {
        case 1 : push(); break;
        case 2 : pop() ; break;
        case 3 : display() ; break;

    }
    }while (choice != 4);

    return 0 ;

    
}