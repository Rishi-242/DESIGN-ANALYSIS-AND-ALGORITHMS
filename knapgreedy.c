#include<stdio.h>
void ks(int n,float wt[],float val[],float w)
{
float x[20],tp=0;
int i,j,u;
u=w;

for(i=0;i<n;i++)
{
x[i]=0.0;
}
for(i=0;i<n;i++)
{
if(wt[i]>u)
break;

else
{
tp=tp+val[i];
u=u-wt[i];
}
}
if(i<n)
x[i]=u/wt[i];

tp=tp+(x[i]*val[i]);

printf("the resultant is ");
for(i=0;i<n;i++)
printf("%f\t",x[i]);

printf("the maximum profit is:%f",tp);
}
int main()
{
float wt[20],val[20],w;
int n,i,j;
float ratio[20],temp;
printf("enter the no.of items");
scanf("%d",&n);
printf("enter the weight");
scanf("%f",&w);
printf("enter the weights");
for(i=0;i<n;i++)
{
scanf("%f",&wt[i]);
}
printf("enter the values");
for(i=0;i<n;i++)
{
scanf("%f",&val[i]);
}
for(i=0;i<n;i++)
{
ratio[i]=val[i]/wt[i];
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(ratio[i]<ratio[j])
{
temp=ratio[j];
ratio[j]=ratio[i];
ratio[i]=temp;

temp=wt[j];
wt[j]=wt[i];
wt[i]=temp;

temp=val[j];
val[j]=val[i];
val[i]=temp;
}
}
}
ks(n,wt,val,w);
return 0;
}

