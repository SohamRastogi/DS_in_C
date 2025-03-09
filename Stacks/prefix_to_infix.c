#include<stdio.h>


#define N 7
char arr[N];
char stack[N];
int top = -1;


void push(char ch)
{
    top++;
    stack[top] = ch;
    return ;
}

char pop()
{
    char returner = stack[top];
    top--;
    return returner;
}

int main()
{
    for(int i = 0 ; i < N ; i ++){
        scanf("%c",&arr[i]);
    }

    // for(int i = 0 ; i < N ; i ++){
    //     printf("%c",arr[i]);
    // }

    int alpha = 6;

    while(alpha >= 1)
    {
        int flag = 0 ;

        if(arr[alpha] == '+' || arr[alpha] == '-' || arr[alpha] == '*' || arr[alpha] == '/'){
            flag = 1;
        }
        if(flag == 0){
            push(arr[alpha]);
        }

        else 
        {
            char a = pop();
            char b = pop();

            push(b);
            push(arr[alpha]);
            push(a);

        }
        alpha--;

    }

    char a1 = pop();
    char a2 = pop();
    char a3 = pop();
    char a4 = pop();
    char a5 = pop();
    char a6 = pop();
    printf("%c ",a1);
    printf("%c ",a2);
    printf("%c ",a3);
    printf("%c ",arr[0]);
    printf("%c ",a4);
    printf("%c ",a5);
    printf("%c ",a6);


    return 0 ;
}