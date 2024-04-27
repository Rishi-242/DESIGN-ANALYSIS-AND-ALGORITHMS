//2.find the nearest point?
#include<stdio.h>
#include<math.h>
#include<limits.h>
struct point
{
int x,y;
};
int main()
{
int n,p1,p2;
printf("enter the number of values");
scanf("%d",&n);
struct point p[n];
printf("enter the  values");
for(int i=0;i<n;i++)
{
scanf("%d%d",&p[i].x,&p[i].y);
}
float  min=INFINITY;
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
{
int d=sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
if(d<min)
{
min=d;
p1=p[i].x;
p2=p[i].y;
}}}
printf(" %d%d the closest points are",p1,p2);

}
