#include<stdio.h>
//#define MAX_SIZE 100
int a[20];
void fill(int n,int k,int weight);
int print(int n,int weight);
int wei[10],val[10];
int max=0;
int main()
{
int n,values,weight;

printf("enter the values");
scanf("%d",&n);

printf("enter the weights");
for(int i=0;i<n;i++){
scanf("%d",&wei[i]);
}

printf("enter the values");
for(int i=0;i<n;i++)
{
scanf("%d",&val[i]);
}

printf("enter the weights");
scanf("%d",&weight);

fill(n,0,weight);

printf("%d",max);
}
void fill(int n,int k,int weight)
{
if(k==n)
{
print(n,weight);
return;
}
for(int i=0;i<n;i++)
{
a[k]=i;
fill(n,k+1,weight);
}
}
int print(int n,int weight)
{
int ws=0,vs=0;
for(int i=0;i<n;i++)
{
if(a[i]==1)
{
ws=ws+wei[i];
vs=vs+val[i];
}
}
if(ws<=weight)
{
if(vs>max)
{
max=vs;
}
}
return max;
}
