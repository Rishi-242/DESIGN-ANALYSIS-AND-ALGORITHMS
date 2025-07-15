//1.find the closect pair of point?
//Points: (1,2),(3,4),(6,8),(10,12)
 //   Closest Pair: The closest pair of points is (1,2) and (3,4)
#include<stdio.h>
#include<math.h>
#include<limits.h>
struct point
{
int x,y;
};
int main()
{
int n,p1,p2,p3,p4;
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
p3=p[j].x;
p4=p[j].y;
}}}
printf(" %d,%d,%d,%d the closest pair",p1,p2,p3,p4);

}



