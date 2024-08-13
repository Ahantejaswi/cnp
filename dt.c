#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
char data[100];
char wrd[]="MEGABUCK";
char cipher[20][8];
int seq[8];
int i,j,cnt,c;
for(i=0;i<strlen(wrd);i++)
{
cnt=0;
for(j=0;j<strlen(wrd);j++)
if(wrd[i]>wrd[j])
++cnt;
seq[i]=cnt;
}
printf("\nEnter data :");
gets(data);
cnt=strlen(data);
if(cnt%strlen(wrd)!=0)
printf("\nError: Invalid Input");
else
{
for(i=0;i<8;i++)
{
for(c=0;c<8;c++)
if(seq[c]==i)
break;
for(j=0;j<cnt/strlen(wrd);j++)
  cipher[j][c]=data[i*(cnt/strlen(wrd))+j];
}
for(j=0;j<strlen(wrd);j++)
{
if(cipher[cnt/strlen(wrd)-1][j]=='.')
cipher[cnt/strlen(wrd)][i%strlen(wrd)]==' ';
}
printf("Decrypted data:");
for(i=0;i<cnt;i++)
printf("%c",cipher[i/strlen(wrd)][i%strlen(wrd)]);
}
return 0;
}
