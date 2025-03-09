#include<stdio.h>
#include<math.h>


#define N 11
int stack[N];
char arr[N];
int top = -1;

void push(int ch)
{
    top++;
    stack[top] = ch;
    return ;
}

int pop()
{
    int topper = stack[top];
    top--;
    return topper;
}

void display()
{
    for(int i = top ; i >= 0 ; i --){
        printf("%c ",stack[i]);
    }
    return ;
}

int main()
{
    for(int i = 0 ; i < N ; i ++){
        scanf("%c",&arr[i]);
    }

    int alpha = 10;

    while(alpha >= 0)
    {

        int flag = 0;

        if(arr[alpha] == '*' || arr[alpha] == '+' || arr[alpha] == '/' || arr[alpha] == '-' || arr[alpha] == '^'){
            flag = 1;
        } 

        if(flag == 0) {
            int a = arr[alpha];
            int pusher = a - 48;
            push(pusher);
        }

        // printf("%d",stack[top]);
        // return 0 ;

         if(flag == 1)
        {
            
            char ops = arr[alpha];

            int a = pop();
            int b = pop();

            // int a = a1-48;
            // int b = b1-48;

            // printf("%d",a);
            // return 0 ;

            int result;
            if(ops == '^') result = pow(a,b);
            if(ops == '+') result = a+b;
            if(ops == '-') result = a-b;
            if(ops == '*') result = a*b;
            if(ops == '/') result = a/b;

            // printf("%d",result);
            // return 0 ;
            push(result); 

            // printf("%d",stack[top]);
            // return 0 ;

        }

        
        
        alpha --;
    }

    printf("%d",stack[top]);

    return 0 ;
}