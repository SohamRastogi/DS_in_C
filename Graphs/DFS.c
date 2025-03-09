#include<stdio.h>
#include<stdlib.h>

int stack[7];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int alpha = stack[top];
    top--;
    return alpha;
}

int main()
{
    
    int i = 0;

    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,0,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };


    push(i);

    int checker_extra[7] = {0};

    while(top != -1)
    {
        int node = pop();
        if(checker_extra[node] == 0)
        {
            printf("%d ",node);
            checker_extra[node] = 1;
        }
        

        for(int j = 0 ; j < 7 ; j ++)
        {
            if(a[node][j] == 1 && checker_extra[j] == 0)
            {
                push(j);
                
            }
        }

    }

    
    return 0 ;
}