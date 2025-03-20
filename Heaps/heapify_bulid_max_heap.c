#include<stdio.h>

void heapify (int arr[] , int n , int i)
{
    int target = i;
    int left_child = 2*i;
    int right_child = 2*i + 1;

    if(left_child <= n-1 && arr[left_child] > arr[target])
    {
        target = left_child;
    }
    if(right_child <= n-1 && arr[right_child] > arr[target])
    {
        target = right_child;
    }

    if(target != i)
    {
        int temp;
        temp = arr[target];
        arr[target] = arr[i];
        arr[i] = temp;
        heapify(arr , n , target);
    }

    return ;

}

int main()
{
    int n = 8;
    int arr[8] = {-1 , 15 , 5 , 20 , 1 ,17 , 10 , 30};

    for(int i = (n-1)/2 ; i >= 1 ; i --)
    {
        heapify(arr , n , i);
    }

    for(int i = 0 ; i < 8 ; i ++)
    {
        printf("%d ",arr[i]);
    }

    return 0 ;

}