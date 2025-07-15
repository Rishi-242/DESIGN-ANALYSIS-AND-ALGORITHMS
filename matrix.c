#include<stdio.h>
#include<limits.h>
int mcm(int arr[],int i,int j)
{
    int val;
    if(i==j)
    {
        return 0;
    }
    int min=INT_MAX;
    for(int k=i;k<j;k++)
    {
        val=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
    }
    if(val<min)
    {
        min=val;   
    }
    return min;
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    printf("Minimum number of multiplications is %d ",mcm(arr, 0, N - 1));
    getchar();
    return 0;
}
