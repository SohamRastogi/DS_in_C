#include<stdio.h>

int main()
{
    
    int arr[9] = {1,1,2,2,3,3,4,4,5};

    int count = 0;
    int count_array[8];
    int gamma = 0;

    for(int i = 0 ; i < 8 ; i ++)
    {
        if(arr[i] == arr[i+1]) {
            count++;
            count_array[gamma++] = count;
            
        }
        else if(arr[i] != arr[i+1])
        {
            count = 0 ;
            count_array[gamma++] = count;
        }
        
    }


    int max = -1;

    for(int i = 0 ; i < 9; i ++)
    {
        if(max < count_array[i])
        {
            max = count_array[i];
        }
    }

    int index_array[9] = {-1};
    int delta = 0;

    for(int i = 0 ; i < 8 ; i ++)
    {
        if(count_array[i] == max)
        {
            index_array[delta++] = i;
        }
    }

    int final_answer_array[delta] ;

    for(int i = 0 ; i < delta ; i ++)
    {
        final_answer_array[i] = arr[index_array[i]];
    }

    for(int i = 0 ; i < delta ; i ++)
    {
        printf("%d ",final_answer_array[i]);
    }


    return 0 ;
}