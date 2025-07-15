#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int freq[10];
int sum(int,int);
int obst(int i,int j){
if(i>j)
return 0;
if(i==j){
return freq[i];}
int min=INT_MAX;
for(int k=i;k<=j;k++){
int val=obst(i,k-1)+obst((k+1),j)+sum(i,j);
if(val<min)
min=val;
}
return min;
}
int sum(int i,int j){
int s=0;
for(int k=i;k<=j;k++){
s=s+freq[k];
}
return s;
}
int main(){
int n;
printf("enter the size");
scanf("%d",&n);
printf("enter the frequency");
for(int i=0;i<n;i++){
scanf("%d",&freq[i]);}
int r=obst(0,n-1);
printf("after getting the frequency:%d",r);
}

