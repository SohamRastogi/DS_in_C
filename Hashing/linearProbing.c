#include<stdio.h>

int main()
{
    int n = 8;
    int arr[8] = {3 , 2 , 9 , 6 , 11 , 13 , 7 , 12};

    int hash_table[10] ;

    int m = 10;

    // hash function is : 2*k + 3.

    for(int i = 0 ; i < 10 ; i ++)
    {
        hash_table[i] = -1;
    }

    for(int i = 0 ; i < 8 ; i ++)
    {
        int alpha = (2*arr[i] + 3) % m ;
        
        if(hash_table[alpha] == -1) hash_table[alpha] = arr[i];
        else 
        {
            int count = 0;
            while(count < 10)
            {
                alpha = (alpha + 1) % m;

                if(hash_table[alpha] == -1) {
                    hash_table[alpha] = arr[i];
                    break;
                }
                count ++ ;
            }
        }
    }

    for(int i = 0 ; i < 10 ; i ++)
    {
        printf("%d ",hash_table[i]);
    }


    return 0 ;
}