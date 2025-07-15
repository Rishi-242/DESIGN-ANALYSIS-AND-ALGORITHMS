#include<stdio.h>
#define MAX_SIZE 100
int ks(int n,int w,int val[],int weight[]);
int main()
{
int i,n,w;
int val[MAX_SIZE],weight[MAX_SIZE];

printf("enter the values");
scanf("%d",&n);

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
if(n==0||w==0)
{
return 0;
}
if(weight[n-1]>w)
{
return ks(n-1,w,val,weight);
}
else
{
return max(val[n-1]+ks(n,w-weight[n-1],val,weight),ks(n-1,w,val,weight));
}
}
