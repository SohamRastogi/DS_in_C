#include<stdio.h>

#define MAX_SIZE 10
char stack[MAX_SIZE];
int top = -1;


void push();
void pop();


int main()
{
    char arr[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        scanf("%c" ,&arr[i]);
    }

    // for(int i = 0 ; i < 10 ; i++)
    // {
    //     printf("%c ", arr[i]);
    // }

    int n = 10;
    
    while ( n-- )
    {
        static int l = 0;

        if(arr[l] == '(')
        {
            push();
        }
        else 
        {
            if(top == -1 )
            { 
                printf("NO");
                return 0 ;
            }
            else pop();
       }

       l++;

    
    }

    if(top == -1) printf("YES");
    else printf("NO");

    return 0 ;
}  



void push()
{
    top++;
    stack[top] = '(';
    return ;
}




void pop()
{
    top -- ;
    return ;
}