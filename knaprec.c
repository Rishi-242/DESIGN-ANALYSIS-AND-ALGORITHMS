#include<stdio.h>
#define MAX_SIZE 100
int ks(int n,int w,int val[],int weight[]);
int a[10];
int main()
{
int i,n,val[MAX_SIZE],weight[MAX_SIZE],w;
printf("enter the size");
scanf("%d",&n);
printf("enter the values");
for(int i=0;i<n;i++)
{
scanf("%d",&val[i]);
}
printf("enter the weight");
for(int i=0;i<n;i++)
{
scanf("%d",&weight[i]);
}

printf("enter the maximum weight");
scanf("%d",&w);
int result=ks(n,w,val,weight);
printf("%d",result);
}
int max(int a,int b)
{
return (a>b)?a:b;
}
int ks(int n,int w,int val[],int weight[])
{
if(n==0 || w==0)
return 0;
if(weight[n-1]<=w)
return max(val[n-1]+ks(n-1,w-weight[n-1],val,weight),ks(n-1,w,val,weight));
else
return ks(n-1,w,val,weight);
}
