#include<stdio.h>
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
printf("enter the  values and weights");  
for(i=0;i<n;i++)
{
scanf("%d%d",&val[i],&weight[i]);
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

for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
{

if(n==0||w==0)
{
return a[i][j]=0;
}
if(weight[n-1]>w)
{
return a[i][j]=ks(n-1,w,val,weight);
}
else
{
return a[i][j]=max(val[n-1]+ks(n,w-weight[n-1],val,weight),ks(n-1,w,val,weight));
}
}
}
}

