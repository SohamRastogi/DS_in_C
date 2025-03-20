#include<stdio.h>

void heapify(int arr[] , int n , int i)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;

    if(l <= n-1 && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r<=n-1 && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(arr[largest] != arr[i])
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr , n , largest);
    }
    return  ;
}

int main()
{
    int n = 8;
    int arr[8] = {-1 , 15 , 5 , 20 , 1 , 17 , 10 , 30};

    for(int i = (n-1)/2 ; i >= 1 ; i --)
    {
        heapify(arr , n , i);
    }

    for(int i = n - 1; i >= 1 ; i --)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapify(arr , i , 1);
    }

    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d ",arr[i]);
    }

    return 0 ;
}