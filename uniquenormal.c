#include<stdio.h>
#include<stdbool.h>
int main()
{
    int arr[] = {1,1,2,2,4 , 0 ,0 ,2};
    int index =0;
    int s= sizeof(arr)/sizeof(int);
    int unique[s];
    for(int i =0 ; i< s ; i++)
    {
        bool test = true;
        for( int j =i-1 ; j>=0 ; j-- )
        {
            if( arr[i] == arr[j] )
            {
                test = false;
                break;
            }
        }
        if( test )
        {
            unique[index++] = arr[i];
        }
    }
    for( int i =0 ; i< index ; i++ )
    {
        printf("%d\n" , unique[i]);
    }
}