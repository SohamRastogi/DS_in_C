#include <stdio.h>
#include <math.h>

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
        int alpha = (2 * arr[i] + 3) % m;
        if(hash_table[alpha] == -1) hash_table[alpha] = arr[i];

        else 
        {
            for(int j = 1 ; j < m ; j ++)
            {
                int beta = alpha + pow(j , 2);
                beta = beta % m;
                if(hash_table[beta] == -1) {
                    hash_table[beta] = arr[i];
                    break ;
                }
            }
        }
    }

    for(int i = 0 ; i < m ; i ++)
    {
        printf("%d ",hash_table[i]);
    }


    return 0 ;
}