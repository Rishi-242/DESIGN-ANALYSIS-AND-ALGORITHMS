#include<stdio.h>
int main()
{
int i,n,a[100];
printf("enter the value");
scanf("%d",&n);
int f=fib(n);
int fib(int);
for(i=0;i<n;i++)
{
printf("%d",fib(i));
}
}
int fib(int n)
{
if(n==0)
{
return 0;
}
else if(n==1)
{
return 1;
}
else
{
return fib(n-1)+fib(n-2);
}
}
