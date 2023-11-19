#include<stdio.h>
void sort(int a[] , int n )
{
    for(int i =0 ; i< n ; i++)
    {
        for(int j =0 ; j< n-1 ; j++)
        {
            if( a[j] > a[j+1] )
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

int main()
{
    int arr[] = { 1 , 3, 5, 0 ,-1 , 4, 9 ,2, 12 , 78 ,45};
    sort(arr , sizeof(arr)/sizeof(int));
    for(int i =0 ;i< sizeof(arr)/sizeof(int) ; i++ )
    {
        printf("%d\n" , arr[i]);
    }
}