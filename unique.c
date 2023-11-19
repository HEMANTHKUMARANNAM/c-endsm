#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int index =0;
int* unique( int a[] , int n )
{
    int* unique = malloc(sizeof(int)*n );
    index =0;
    for(int i =0 ; i< n ; i++ )
    {
        bool test = true;
        for(int j =i-1 ; j>=0 ; j--)
        {
            if( a[i] == a[j] )
            {
                test = false;
                break;
            }
        }
        if (test)
        {
            unique[index++] = a[i];
        }
        
    }
    return unique;
}

int main()
{
    int arr[] = { 1 , 3, 5, 0 ,-1 , 4, 9 ,2, 12 , 78 ,45 , 8 , 1,3 ,0 ,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    int * uni = unique( arr ,n );

    for( int i =0 ; i< index ; i++ )
    {
        printf("%d\n" , uni[i] );
    }


}