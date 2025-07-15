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
else if(n==0)
{
return a[n]=0;
}
else if(n==1){
return a[n]=1;
}
else
{
return a[n]=fib(n-1)+fib(n-2);
}
}
