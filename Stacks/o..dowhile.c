#include<stdio.h>

#define MAX_SIZE 10
int stack[10] ;
int top = -1 ;

void push(int* stack,int* top){
    
    if(*top == MAX_SIZE-1){
        printf("stack_overflow");
    }
    else {
        int n;
        printf("enter a number : ");
        scanf("%d",&n);
        *top = *top +1;
        stack[*top] = n;
    }

    printf("\n");
    return ;
}

void pop (int* stack,int* top){
    if(*top == -1){
        printf("stack is emoty");
    }
    else {
        int alpha = stack[*top];
        printf("the popped element is : %d",alpha);
        *top = *top -1;
    }
    printf("\n");
    return ;
}

void display (int* stack,int* top){
    if(*top == -1){
        printf("stack is empty");
    }
    else {
        printf("the elements of the stack are : ");
        printf("\n");
        for(int i = *top ; i >= 0 ; i--){
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
    return ;
}


int main()
{
    int choice ;
    
    
    printf("--------stack menu-----------");
    printf("\n");
    printf("1. push");
    printf("\n");
    printf("2. pop");
    printf("\n");
    printf("3. display");
    printf("\n");
    printf("4. exit");
    printf("\n-----------\n");
    // int choice;
    // printf("enter your choice : ");
    scanf("%d",&choice);

    while(choice != 4){

    switch (choice){
        case 1 : push(stack, &top);
                 break;
        
        case 2 : pop(stack, &top);
                 break;
        case 3 : display(stack, &top);
                 break;
        case 4 : return 0 ;
        // printf("enter your choice : ");
        // scanf("%d",&choice);
    }
    printf("enter your choice : ");
    scanf("%d",&choice);
    }
    return 0 ;
    


}