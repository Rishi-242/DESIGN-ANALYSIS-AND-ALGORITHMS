#include<stdio.h>
#include<math.h>
#include<limits.h>
struct point
{
int x,y;
};
int main()
{
struct point p[50];
int a,b,c,i,k,j,n,val;
int np=0,nn=0;
int count=0;
printf("enter the values");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d%d",&p[i].x,&p[i].y);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
a=p[j].y-p[i].y;
b=p[i].x-p[j].x;
c=p[i].x*p[j].y-p[j].x*p[i].y;
for(k=0;k<n;k++)
{
val=a*p[k].x+b*p[k].y-c;
}
if(val>0)
{
np++;
}
else 
{
nn++;
}
}
if(np==0 ||nn==0)
{
printf("both are convex halls %d%d\n",p[i].x,p[ i].y);
count++;
printf("both are convex halls %d%d\n",p[j].x,p[j].y);
count++;
}
}
printf("the no.of edges:%d",count);
}
