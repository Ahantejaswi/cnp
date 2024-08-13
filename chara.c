#include<stdio.h>
#include<string.h>
#define DLE 16
#define STX 2
#define ETX 3
int main()
{
char ch;
char arr[100]={DLE,STX};
int i=2,j;
printf("\n Enter the data stream(CTRL+B->STX,CTRL+C->ETX,CTRL+P->DLE):\n");
do
{
scanf("%c", &ch);
printf("char is ",ch);
if(ch=='\n')
break;
if(ch==DLE)
{
arr[i++]=DLE;
printf("DLE");
}
else if(ch==2)
printf("STX");
else if(ch==3)
printf("ETX");
else
printf("%c",ch);
arr[i++]=ch;
}while(ch!='\n');
arr[i++]=DLE;
arr[i++]=ETX;
printf("\n The stuffed stream is \n");
for(j=0;j<i;j++)
{
if(arr[j]==DLE)
printf("DLE");
else if(arr[j]==STX)
printf("STX");
else if(arr[j]==ETX)
printf("ETX");
else
printf("%c",arr[j]);
}
printf("\n The de-stuffed data is \n");
for(j=2;j<i-2;j++)
{
if(arr[j]==DLE)
{
printf("DLE");
j++;
}
else if(arr[j]==STX)
printf("STX");
else if(arr[j]==ETX)
printf("ETX");
else
printf("%c",arr[j]);
}
return 0;
}
