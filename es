#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
char seq[36]="qwertyuiopasdfghjklzxcvvnm1234567890";
char data[50];
char encoded[50];
int i,j,len,present=0;
printf("\nEnter data:");
gets(data);
len=strlen(data);
for(i=0;i<len;i++)
{
if(isupper(data[i]))
encoded[i]=seq[data[i]]-'A';
elseif(islower(data[i]))
encoded[i]=toupper(seq[data[i]-'a']);
elseif(isdigit(data[i]))
encoded[i]=seq[data[i]-'0'+26];
else
encoded[i]=data[i];
}
encoded[len]='\0';
printf("\n encoded string is:%s",encoded);
return 0;
}
