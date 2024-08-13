#include<stdio.h>
#include<conio.h>
#define DEGREE 16
int mod2add(int,int);
int getnext(int*,int);
int result[30];
void calc_crc(int length)
{
int ccitt[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int i=0,pos=0,newpos;
while(pos<length-DEGREE)
{
for(i=pos;i<pos+DEGREE+1;++i)
result[i]=mod2add(result[i],ccitt[i-pos]);
newpos=getnext(result,pos);
if(newpos>pos+1)
pos=newpos-1;
++pos;
}
}
int getnext(int array[],intpos)
{
int i=pos;
while(array[i]==0)
++i;
return i;
}
int mod2add(intx,int y)
{
return(x==y?0:1);
}
int main()
{
int array[30],length,i=0;
char ch;
printf("Enter the data (Message) stream:");
do{
scanf("%c",&ch);
if(ch=='\n')
break;
array[i++]=ch-'0';
} while(ch!='\n');
length=i;
/*Appending DEGREE number of zeros to the message*/
for(i=0;i<DEGREE;++i)
array[i+length]=0;
length+=DEGREE;
for(i=0;i<length;++i)
result[i]=array[i]; /*Copy into result Array*/
calc_crc(length); /*CRC Calculation*/
printf("\nThe transmitted frame is :");
for(i=0;i<length-DEGREE;++i)
printf("%d",array[i]); /*Message*/
for(i=length-DEGREE;i<length;++i)
printf("%d",result[i]); /*Remainder*/
/*Decoding*/
printf("\n Enter the stream for which CRC has to be checked:");
i=0;
do{
scanf("%c",&ch);
if(ch=='\n')
break;
array[i++]=ch-'0';
}while(ch!='\n');
length=i;
for(i=0;i<length;i++)
  result[i]=array[i];
calc_crc(length);
printf("\n Calculated Checksum:");
for(i=length-DEGREE;i<length;i++)
printf("%d",result[i]);
return 0;
}
