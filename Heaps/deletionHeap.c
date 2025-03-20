// we assume that we are given a max heap array and we have to delete the root node from it.

#include<stdio.h>

int main()
{
    int n = 10;
    int arr[10] = {-1 , 50 , 45 , 35 , 33 , 16 , 25 , 34 , 12 , 10};

    // delete root node.

    int temp;
    temp = arr[1];
    arr[1] = arr[n-1];
    arr[n-1] = temp; 

    int i = 1;

    while(2*i <= n-3 && 2*i + 1 <= n-2)
    {
        int left_child = 2*i;
        int right_child = 2*i + 1;

        if(arr[left_child] > arr[right_child] && arr[left_child] > arr[i])
        {
            int temp;
            temp = arr[left_child];
            arr[left_child] = arr[i];
            arr[i] = temp ;
            i = left_child;
        }
        else if(arr[right_child] > arr[left_child] && arr[right_child] > arr[i])
        {
            int temp;
            temp = arr[right_child];
            arr[right_child] = arr[i];
            arr[i] = temp ;
            i = right_child;
        }
        else break;
    }
    if(2*i <= n-2)
    {
        if(arr[i] < arr[2*i])
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[2*i];
            arr[2*i] = temp;
        }
    }

    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d ",arr[i]);
    }
    return 0 ;
}