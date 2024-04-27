//6.write a program to skip the multiple characters from the main string?
//7.the count of substring present in main string?
#include<stdio.h>
#include<string.h>
int main()
{
char str1[100],str2[100];
int i,j,n=1,f=0,c=0;
printf("enter the string");
gets(str1);
printf("enter the substring");
gets(str2);
int a=strlen(str1);
int b=strlen(str2);
for(i=0;i<a;i+=n){
printf("the alternative characters:%c\n",str1[i]);
n++;
for(j=0;j<b;j++)
{
if(str1[i]==str2[0])
{
f=0;
if(str1[i+j]!=str2[i])
{
f=1;
c++;
break;
}
}
}
}
if(f==1)
{
printf("the string is present\n");
}
else
{
printf("the string is not present\n");
}
printf("the count:%d\n",c);
}
