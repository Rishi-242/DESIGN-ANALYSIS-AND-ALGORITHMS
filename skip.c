//4.single character skip? 
//5. the count of the string occur in main string?
#include<stdio.h>
#include<string.h>
void main()
{
char str1[100],str2[200];
int i,j,f=0,c=0;
printf("enter the main String");
gets(str1);
int a=strlen(str1);
int b=strlen(str2);
for(int i=0;i<a;i=i+2)
{
printf("the alternate characters of a string:%c\n",str1[i]);
}
printf("enter the substring");
gets(str2);
for(i=0;i<a;i=i+2)
{
for(j=0;j<b;j++)
{
if(str1[i]==str2[0])
{
f=0;
if(str1[i+j]!=str2[i])
{
c++;
f=1;
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

