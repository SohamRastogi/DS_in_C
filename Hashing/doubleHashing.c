#include<stdio.h>

int main()
{
    int n = 8;
    int arr[8] = {3 , 2 , 9 , 6 , 11 , 13 , 7 , 12};

    int m = 10;

    int hash_table[m];

    // hash function 1 : 2*k + 3.
    // hash function 2 : 3*k + 1.

    for(int i = 0 ; i < 10 ; i  ++)
    {
        hash_table[i] = -1;
    }

    for(int i = 0 ; i < 8 ; i ++)
    {
        int u = (2*arr[i] + 3) % m;

        if(hash_table[u] == -1) hash_table[u] = arr[i];

        else 
        {
            int v = (3*arr[i] + 1) % m;
            
            for(int j = 1 ; j < m ; j ++)
            {
                if(hash_table[(u + j*v) % m] == -1){
                    hash_table[(u + j*v) % m] = arr[i];
                    break;
                } 
            }
        }
    }

    for(int i = 0 ; i < m ; i ++)
    {
        printf("%d ", hash_table[i]);
    }

    return 0 ;


}