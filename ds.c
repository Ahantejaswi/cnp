#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
char seq[36]="qwertyuiopasdfghjklzxcvbnm1234567890";
char data[100];
char decoded[100];
int i,j,len,present=0;
printf("\n Enter data:");
gets(data);
len=strlen(data);
for(i=0;i<len;i++)
{
for(j=0;j<36 && !present;++j)
