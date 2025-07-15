#include<stdio.h>
#include<limits.h>
int mcmTable(int a[],int n)
{
int m[n][n];
int i,j,k,l,q;

for(i=1;i<n;i++)
m[i][i]=0;

for(l=2;l<n;l++)
{
for(i=1;i<n-l+1;i++)
{
j=i+l-1;
m[i][j]=INT_MAX;

for(k=i;k<=j-1;k++)
{
q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];

if(q<m[i][j])
m[i][j]=q;
}
}
}
return m[1][n-1];
}

int main()
{
int i,n;
printf("enter the n value");
scanf("%d",&n);
int a[n];
printf("enter the array values");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("the minimum no.of multiplication:%d",mcmTable(a,n));
}
