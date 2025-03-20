#include<stdio.h>

void insert_node(int brr[] , int* n , int value , int alpha)
{
    *n = *n + 1;
    brr[*n - 1] = value;
    int i = alpha;

    while(i > 1)
    {
        if(brr[i/2] < brr[i])
        {
            int temp;
            temp = brr[i];
            brr[i] = brr[i/2];
            brr[i/2] = temp;
            i = i/2;
        }
        else {
            break;
        }
    }
    return ;
}

int main()
{
    int beta = 6;
    int arr[6] = {-1 , 15 , 20 , 7 , 9 , 30};

    int brr[6];
    brr[0] = -1;

    int n = 1;

    for(int i = 1 ; i < 6 ; i++)
    {
        insert_node(brr , &n , arr[i] , i);
    }

    // brr is max heaped !!

    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d ",brr[i]);
    }

    return 0 ;

}