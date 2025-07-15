#include <stdio.h>
#include <stdbool.h>
void hc(int n,int k);
void hc1(int n,int k,int s);
bool issafe(int k,int i);
int adj[10][10];
int a[10];
int main()
{
int n,k,s;
printf("enter the values");
scanf("%d",&n);
printf("enter the starting edge");
scanf("%d",&s);
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
scanf("%d",&adj[i][j]);
}
}
hc1(n,0,s);
return 0;
}
//issafe function
bool issafe(int k,int i)
{
if(adj[a[k-1]][i]!=1)
return false;
for(int j=0;j<k;j++)
{
if(a[j]==i)
return false;
}
return true;
}


void hc1(int n,int k,int s)
{
a[0]=s;
for(int i=1;i<n;i++)
{
a[i]=-1;
}
hc(n,1);
}


void  hc(int n,int k)
{
if(k==n)
{
if(adj[a[k-1]][a[0]]==1){
printf("hamoltonian cycle ");
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}
return;
}
for(int i=0;i<n;i++)
{
if(issafe(k,i))
{
a[k]=i;
hc(n,k+1);
a[k]=-1;
}
}
}




/*
0 1 0 0 0 1
1 0 1 0 1 0
0 1 0 1 0 1
0 0 1 0 1 0
0 1 0 1 0 1
1 0 1 0 1 0 

0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0
*/
/*
no.of values are :4
0 1 1 1 
1 0 1 1
1 1 0 1
1 1 1 0
output:
hamoltonian cycle 0 1 2 3 
hamoltonian cycle 0 1 3 2 
hamoltonian cycle 0 2 1 3 
hamoltonian cycle 0 2 3 1 
hamoltonian cycle 0 3 1 2 
hamoltonian cycle 0 3 2 1 
*/
