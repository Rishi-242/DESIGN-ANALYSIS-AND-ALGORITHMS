//3.find the farest point?
#include<stdio.h>
#include<math.h>
#include<limits.h>
struct point
{
int x,y;
};
int main()
{
int p1,p2;
int n,i,j;
printf("enter the number of values");
scanf("%d",&n);
struct point p[n];
printf("enter the  values");
for(i=0;i<n;i++)
{
scanf("%d%d",&p[i].x,&p[i].y);
}
float  min=0;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
int d=sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
if(d>min)
{
min=d;
p1=p[j].x;
p2=p[j].y;
}}}
printf(" %d%d the farest points are",p1,p2);
}
