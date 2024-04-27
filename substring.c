//1.no.of times the string occurance in the main string?
//2.the occurance of substring in the main string?
#include<stdio.h>
#include<string.h>
void main()
{
char str1[30],str2[30];
int i,j,a,b,f=0,c=0,f1=0;
printf("enter the main String");
//scanf("%[^\n]",str1);
gets(str1);
printf("enter the substring");
//scanf("%[^\n]",str2);
gets(str2);
a=strlen(str1);
b=strlen(str2);
for(i=0;i<=a-b;i++)
{
if(str2[0]==str1[i])
{
f=0;
for(j=0;j<b;j++)
{
if(str1[i+j]!=str2[j])
{
f=1;
break;
}}
if(f==0)
{
c++;
printf("sub string is  present at %d index number\n",i);
f1=1;
}
else
{
printf("sub string is not   present at %d index number\n",i);
//f1=1;
}}}
printf("count %d\n",c);
}


