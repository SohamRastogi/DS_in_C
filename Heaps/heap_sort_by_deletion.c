#include<stdio.h>

void insert_node(int brr[] , int* n , int value , int alpha)
{
    *n = *n + 1;
    brr[*n - 1] = value;
    int i = alpha;

    while(i>1)
    {
        if(brr[i/2] < brr[i])
        {
            int temp;
            temp = brr[i];
            brr[i] = brr[i/2];
            brr[i/2] = temp;
            i = i / 2;
        }

        else break;

    }
    return ; 

}

void delete_node (int brr[] , int start , int end)
{
    int temp ;
    temp = brr[start];
    brr[start] = brr[end];
    brr[end] = temp ;

    int i = 1;
    while(2*i <= end-2 && 2*i + 1 <= end-1)
    {
        int left_child = 2*i;
        int right_child = 2*i + 1;

        if(brr[left_child] > brr[right_child] && brr[left_child] > brr[i])
        {
            int temp;
            temp = brr[left_child] ;
            brr[left_child] = brr[i];
            brr[i] = temp;
            i = left_child;
        }
        else if(brr[left_child] < brr[right_child] && brr[right_child] > brr[i])
        {
            int temp;
            temp = brr[right_child];
            brr[right_child] = brr[i];
            brr[i] = temp;
            i = right_child;
        }
        else break;
    }
    if(2*i == end-1)
    {
        if(brr[2*i] > brr[i])
        {
            int temp;
            temp = brr[2*i];
            brr[2*i] = brr[i];
            brr[i] = temp;
        }
    }

}

int main()
{
    int beta = 6;
    int arr[6] = {-1 , 15 , 20 , 7 , 9 , 30};

    int n = 1;
    int brr[n];

    brr[0] = -1;
    
    insert_node(brr , &n , arr[1] , 1);
    insert_node(brr , &n , arr[2] , 2);
    insert_node(brr , &n , arr[3] , 3);
    insert_node(brr , &n , arr[4] , 4);
    insert_node(brr , &n , arr[5] , 5);

    // brr is max heap sorted array.

    delete_node (brr , 1 , 5) ;
    delete_node (brr , 1 , 4) ;
    delete_node (brr , 1 , 3) ;
    delete_node (brr , 1 , 2) ;

    for(int i = 0 ; i < 6 ; i ++)
    {
        printf("%d ",brr[i]);
    }

    return 0 ;
}