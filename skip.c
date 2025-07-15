//4.single character skip? 
//5. the count of the string occur in main string?
#include <stdio.h>
#include <string.h>

void main() {
    char str1[100], str2[200];
    int i, j, f, count = 0;
printf("Enter the main string: ");
gets(str1);
printf("Enter the substring: ");
gets(str2);
int a = strlen(str1);
int b = strlen(str2);  // Print alternate characters of the main string
printf("The alternate characters of the string:\n");
for (i = 0; i < a; i += 2) {
printf("%c\n", str1[i]);
}
// Count occurrences of the substring in the main string
for (i = 0; i <= a - b; i++) {
f = 1;
for (j = 0; j < b; j++) {
if (str1[i + j] != str2[j]) {
f = 0;
break;
}}if (f == 1) {
count++;
}}
if (count > 0) {
printf("The substring is present\n");
printf("The count: %d\n", count);
} else {
printf("The substring is not present\n");
    }
}

