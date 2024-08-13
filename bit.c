#include<stdio.h>
#include<string.h>
int main()
{
char ch, array[50]="01111110",read_array[50];
int count=0,i=8,j,k;
printf("Enter data to be transmitted:");
do
{
scanf("%c",&ch);
if(ch=='\n')
break;
if(ch=='1')
count++;
else
count=0;
array[i++]=ch;
if(count==5)
{
array[i++]='0';
count=0;
}
} while(ch!='\n');
strcat(array,"01111110"); /* FLAG pattern for START and END of HDLC frame format*/
printf("\n Transmitted bit stream(After stuffing) at the transmitter side is:%s", array);
/*DESTUFFING*/
j=strlen(array);
count=0;
k=0;
for(i=8;i<j-8;i++)
{
if(array[i]=='1')
count++;
else
count=0;
read_array[k]=array[i];
k++;
if(count==5 && array[i+1]=='0')
{
i++;
count=0;
}
}
read_array[k]='\0';
printf("\n Destuffed data at the receiver is :");
for(i=0;i<k;i++)
printf("%c",read_array[i]);
return 0;
}
