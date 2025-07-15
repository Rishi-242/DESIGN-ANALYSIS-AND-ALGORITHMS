//dp(coin change->no.of ways)
//5.#coin change(recursion)
#include<stdio.h>

int ccw(int wt[],int n,int s)
{
    if(s<=0)
      return 1;//bcz not considering is also 1 way
     if(n<=0)
       return 0;//no chance to take 
     else if(wt[n-1]<=s)
      return ccw(wt,n,s-wt[n-1])+ccw(wt,n-1,s);
     else 
       return ccw(wt,n-1,s);
}  


int main()
{
    int i,n,coins[n],sum;

    printf("enter the size:");
    scanf("%d",&n);
    printf("enter the coin values:");
   for(i=0;i<n;i++)
    {
     scanf("%d",&coins[i]);
    }
    printf("enter the total sum:");
    scanf("%d",&sum);
    printf("total no.of ways to pick coins are:%d\n",ccw(coins,n,sum));


}
/*
no.of values are:3
enter the values:1 4 5
sum:8
no.of ways to pick the coins is :4
*/
