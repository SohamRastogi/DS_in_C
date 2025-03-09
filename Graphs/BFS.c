#include<stdio.h>
#include<stdlib.h>

int queue[7];
int front = 0;
int rear = -1;

void enqueue(int data)
{
    rear++;
    queue[rear] = data;
    return ;
}

int dequeue()
{
    int alpha = queue[front];
    front++;
    return alpha;
}

int main()
{
    int visited[7] = {0};
    
    int i = 0;
    visited[i] = 1;
    
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,0,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d ",i);

    enqueue(i);

    while(front <= rear)
    {
        int node = dequeue();
        for(int j = 0 ; j < 7 ; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ",j);
                enqueue(j);
                visited[j] = 1;
            }
        }

    }
    return 0 ;
}