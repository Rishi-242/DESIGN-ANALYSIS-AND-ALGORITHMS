#include<stdio.h>
#include<stdlib.h>
int minm(int ,int);
int CCM(int n,int s,int wt[]){
if(s==0)
return 0;
if(n==0)
return 999999;
if(wt[n-1]<=s){
return minm(1+CCM(n,s-wt[n-1],wt),CCM(n-1,s,wt));
}
else{
return CCM(n-1,s,wt);
}}
int main(){
int n,s;
printf("enter the size");
scanf("%d",&n);
printf("enter the sim of bag");
scanf("%d",&s);
int wt[n];
printf("enter the items in a bag");
for(int i=0;i<n;i++){
scanf("%d",&wt[i]);
}
printf("min value of of a bag using coin change %d",CCM(n,s,wt));
return 0;
}
int minm(int a,int b){
return(a<b)?a:b;
}

