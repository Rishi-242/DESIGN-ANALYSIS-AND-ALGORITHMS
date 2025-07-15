#include<stdio.h>
#define MAX_SIZE 100
int fib(int);
int a[MAX_SIZE];
int main()
{
int i,n=0;
printf("enter the value");
scanf("%d",&n);
for(i=0;i<MAX_SIZE;i++)
{
a[i]=-1;
}
for(i=0;i<n;i++)
{
printf("%d ",fib(i));
}
return 0;
}
int fib(int n){
if(a[n]!=-1)
return a[n];
for(int i=0;i<=n;i++)
{
if(n==0||n==1)
{
return a[i]=1;
}
else
{
return a[i]=fib(n-1)+fib(n-2);
}
}
}
