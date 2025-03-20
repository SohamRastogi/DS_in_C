#include <stdio.h>

void heapify(int arr[] , int n , int i)
{
    int largest = i;
    int left_child = 2*i;
    int right_child = 2*i + 1;

    if(left_child <= n-1 && arr[left_child] > arr[largest])
    {
        largest = left_child ;
    }
    if(right_child <= n-1 && arr[right_child] > arr[largest])
    {
        largest = right_child ;
    }
    if(largest != i)
    {
        int temp;
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr , n , largest);
    }

    return ; 
}

int main()
{
    int n = 8;
    int arr[8] = {-1 , 15 , 5 , 20 , 1 , 17 , 10 , 30} ;

    for(int i = (n-1)/2 ; i >= 1 ; i--)
    {
        heapify(arr , n , i) ;
    }

    // now arr is a max heapified array.

    // now we have to delete the heapified array so that we can do the heap sort operation in O(n log n) time complexity.

    for(int i = n-1 ; i>=1 ; i--)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp ;

        heapify(arr , i-1 , 1);
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0 ;
}