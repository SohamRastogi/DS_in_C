#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    int arr[8] = {3 , 2 , 9 , 6 , 11 , 13 , 7 , 12};

    int m = 10;

    // hash function is : 2*k + 3.

    vector<int> hash_table[10] ;

    for(int i = 0 ; i < 8 ; i ++)
    {
        int alpha = 2*arr[i] + 3;
        alpha = alpha % m ;

        hash_table[alpha].push_back(arr[i]);
    }

    return 0 ;

}