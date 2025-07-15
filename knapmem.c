#include<stdio.h>
#define MAX_SIZE 100
int ks(int n,int w,int val[],int weight[]);
int a[MAX_SIZE][MAX_SIZE];
int main()
{
int i,n,w;
int val[MAX_SIZE],weight[MAX_SIZE];
printf("enter the values");
scanf("%d",&n);

for(i=0;i<MAX_SIZE;i++)
{
for(int j=0;j<MAX_SIZE;j++)
{
a[i][j]=-1;
}
}
printf("enter the weights");  
for(i=0;i<n;i++)
{
scanf("%d",&weight[i]);
}
printf("enter the values"); 
for(i=0;i<n;i++)
{
scanf("%d",&val[i]);
}
printf("enter the maximum weight capacity");
scanf("%d",&w);


int result=ks(n,w,val,weight);
printf("the maximum vales %d",result);
return 0;
}
int max(int a,int b){
return (a>b)?a:b;
}
int ks(int n,int w,int val[],int weight[])
{
if(a[n][w]!=-1)
return a[n][w];

if(n==0||w==0)
{
return a[n][w]=0;
}
if(weight[n-1]>w)
{
return a[n][w]=ks(n-1,w,val,weight);
}
else
{
return a[n][w]=max(val[n-1]+ks(n-1,w-weight[n-1],val,weight),ks(n-1,w,val,weight));
}
}

