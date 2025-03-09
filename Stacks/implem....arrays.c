#include<stdio.h>

#define MAX_SIZE 10

int stack [MAX_SIZE] ;
int top = -1 ;

void push (int* stack, int* top){

    if(*top == MAX_SIZE-1) {
        printf("stack overflow");
    }
    else {
        int n;
        printf("enter the element : ");
        scanf("%d",&n);
        *top = *top + 1;
        stack[*top] = n;
    }
    printf("\n");
    return ;
}


void pop (int* stack,int* top) {

    if(*top == -1){
        printf("empty stack");
    }
    else {
        int alpha = stack[*top];
        *top = *top -1;
        printf("the popped element is : %d",alpha);
    }
    printf("\n");
    return ;

}

void display (int* stack,int* top){

    if(*top == -1){
        printf("empty stack");
    }
    else{ 
        int i ;
        printf("the elements of the stack are : \n");
        for(i = *top ; i >= 0 ; i--){
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
    printf("---------stack----------");
    printf("\n");
    printf("1. push\n2. pop\n3. display\n4. exit");
    printf("\n");
    printf("enter your choice : ");
    scanf("%d", &choice);

    switch (choice) {

        case 1 : push(stack, &top);
                 break;
        case 2 : pop(stack,&top);
                 break;
        case 3 : display(stack,&top);
                 break;
        case 4 : return 0;
       

    }
    } while(choice != 4);

    return 0;
}