// we assume that we are given a max heap already and we just have to insert a node in the max heap.

#include<stdio.h>

void insertHeap (int arr[] , int* n , int value) 
{
    *n = *n + 1; // n = 11
    arr[*n-1] = value;

    int i = *n-1;

    while(i > 1)
    {
        if(arr[i/2] < arr[i])
        {
            int temp;
            temp = arr[i/2];
            arr[i/2] = arr[i];
            arr[i] = temp;
            i = i/2 ;
        }
        else break;
    }

    return ;
}

int main()
{
    int n = 10;

    int arr[n];
    arr[0] = -1;
    
    arr[1] = 70;
    arr[2] = 50;
    arr[3] = 40;
    arr[4] = 45;
    arr[5] = 35;
    arr[6] = 39;
    arr[7] = 16;
    arr[8] = 10;
    arr[9] = 9;

    int value = 60; // this is the value to be inserted.

    insertHeap(arr , &n , value);

    for(int i = 1 ; i < n ; i ++)
    {
        printf("%d ",arr[i]);
    }

    return 0 ;

}