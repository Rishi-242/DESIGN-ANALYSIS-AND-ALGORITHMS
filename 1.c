//binary knapsack without repetiton//
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int a[10];
void permute(int n,int k);
bool issafe(int k, int i) {
    for (int j=0;j<k;j++) {
        if (a[j] == i)
            return false; // Not safe
        }
    return true; // Safe
}

int main()
{
int n,k;
printf("enter the k values");
scanf("%d",&k);
printf("enter the n values");
scanf("%d",&n);
permute(n,0);
return 0;
}
void permute(int n,int k)
{
if(k==n)
{
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
return;
}
for(int i=0;i<n;i++)
{
if(issafe(k,i))
{
a[k]=i;
permute(n,k+1);
}
}
}

