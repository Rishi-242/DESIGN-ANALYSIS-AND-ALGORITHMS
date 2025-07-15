#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int arr[100];
int mcm(int arr[],int i,int j){
int val;
if(i==j)
{
return 0;
}
int min=INT_MAX;
for(int k=i;k<j;k++)
{
val=mcm(arr,i,k)+mcm(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
if(val<min)
{
min=val;
}
}
return min;
}
int main()
{
int n;
printf("enter the no.of matrices");
scanf("%d",&n);
printf("enter  the dimension");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("minimum number of multiplication is %d\n",mcm(arr,1,n-1));
//free(arr);
return 0;
}

           
