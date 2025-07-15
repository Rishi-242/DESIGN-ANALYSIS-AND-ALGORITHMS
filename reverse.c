//3.reverse of a substring present in main string?
/*#include<stdio.h>
#include<string.h>
void main()
{
char str1[30],str2[30];
int i,j,a,b,f=0,c=0;
printf("enter the main String");
gets(str1);
printf("enter the substring");
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
}}
int l=strlen(str2);
  	for(i=l-1;i>=0;i--){
  	printf("%c\n",str2[i]);
 	}
if(f==0)
{
//c++;
printf("sub string is not  present\n ");
}
else
{
c++;
printf("the substring is   present\n");
}
printf("count %d\n",c);
}*/
#include<stdio.h>
#include<string.h>

void main() {
char str1[30],str2[30];
int i,j,a,b,c=0;
printf("Enter the main string: ");
gets(str1);
printf("Enter the substring: ");
gets(str2);
a = strlen(str1);
b = strlen(str2);
for (i=0;i<=a-b;i++) {
if (str1[i]==str2[0]) {
c=1;
for (j=0;j<b;j++) {
if (str1[i+j]!=str2[j]) {
c=0;
break;
}}if(c){
 break;
}}}
if (c) {
printf("The substring is present.\n");
printf("Reversed substring: ");
for (i=b-1;i>=0;i--) {
printf("%c", str2[i]);
}
printf("\n");
} else {
printf("The substring is not present.\n");
}
}


