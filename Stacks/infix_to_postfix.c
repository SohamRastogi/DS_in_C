#include<stdio.h>

#define N 9

char stack[9];
char arr[9];
int top = -1;

int precedence(char ch)
{
    if(ch == '*' || ch == '/'){
        return 10;
    }
    else if(ch == '+' || ch == '-'){
        return 5;
    }
}

void push(char ch)
{
    top++;
    stack[top] = ch;
    return  ;
}

void pop()
{
    top--;
    return ;
}


int main()
{
    for(int i = 0; i < 9 ; i++){
        scanf("%c",&arr[i]);
    }

    int alpha = 0;



    while ( alpha <= 8 )
    {

        int flag = 0;

        if(arr[alpha] == '*') flag = 1;
        if(arr[alpha] == '/') flag = 2;
        if(arr[alpha] == '+') flag = 3;
        if(arr[alpha] == '-') flag = 4;

        if(flag == 0){
            printf("%c ",arr[alpha]);
        }

        else{

        if(top == -1){
            push(arr[alpha]);
        }

        else if(precedence(arr[alpha]) > precedence(stack[top])){
            push(arr[alpha]);
        }

        else if(precedence(arr[alpha]) <= precedence(stack[top])){

            printf("%c ",stack[top]);
            pop();

            while(precedence(arr[alpha]) <= precedence(stack[top]) && top != -1){
                printf("%c ",stack[top]);
                pop();
            }
            
            push(arr[alpha]);
        }
        }


        alpha++;
    }

    if(top != -1){
        for(int i = top ; i >= 0 ; i--){
            printf("%c ",stack[i]);
        }
    }



    // for(int i = 0 ; i < 9 ; i ++){
    //     printf("%c ",arr[i]);
    // }

    return 0 ;
}