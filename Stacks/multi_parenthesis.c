#include<stdio.h>

char stack[8];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
    return ;
}

void pop()
{
    top--;

    return ;
}

void display()
{
    int alpha = top;
    while(alpha>=0)
    {
        printf("%c ",stack[alpha]);
        alpha--;
    }
    return ;
}

int main()
{
    char arr[8];
    for(int i = 0 ; i < 8 ; i++){
        scanf("%c",&arr[i]);
    }

    int ele = 0;

    // printf("%c",arr[ele]);
    // return 0 ;

    while(ele < 8)
    {
        if(arr[ele] == '(' || arr[ele] == '{' || arr[ele] == '[' ){
            push(arr[ele]);


            // display();
            // return 0 ;

        }
            else  if (arr[ele] == ')' || arr[ele] == '}' || arr[ele] == ']'){
            char checker = stack[top];
            pop();
            if(arr[ele] == ')' && checker == '{') {
                printf("NO");
                return 0 ;
            }
            if(arr[ele] == ')' && checker == '[') {
                printf("NO");
                return 0 ;
            }
            if(arr[ele] == '}' && checker == '(') {
                printf("NO");
                return 0 ;
            }
            if(arr[ele] == '}' && checker == '[') {
                printf("NO");
                return 0 ;
            }
            if(arr[ele] == ']' && checker == '(') {
                printf("NO");
                return 0 ;
            }
            if(arr[ele] == ']' && checker == '{') {
                printf("NO");
                return 0 ;
            }
        }
        ele++;
    }    

    if(top == -1) printf("YES");
    else printf("NO");

   return 0 ;
}