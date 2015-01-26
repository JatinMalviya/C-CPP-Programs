#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void binary(int b[],int x)
{
int i;
for(i=0;i<4;i++)
b[i]=0;
i=3;
while(x>0)
{
 b[i]=x%2;
 x=x/2;
 i--;
}
}

int add(int p[],int k[],int carry)
{
int x,j;
for(j=3;j>=0;j--)
{
 x=p[j];
 p[j]=x^k[j]^carry;
if(((x==1)&&(k[j]==1))||((k[j]==1)&&(carry==1))||((carry==1)&&(x==1)))
 {
 carry=1;
 }
 else
 carry=0;
 }
 return carry;
}

void rightshift(int x,int *y)
{
int i;
for(i=3;i>0;i--)
y[i]=y[i-1];
y[0]=x;
}

void main()
{
int M,Q,m[4],q[4],i,j,y,c=0,z=0,s=0;
int a[4]={0,0,0,0};
int ans[8];
clrscr();
printf("\n Enter the Multiplicant: ");
scanf("%d",&M);
printf("\n Enter the Multiplier: ");
scanf("%d",&Q);

binary(m,M);
printf("\n\n Binary conversion of Multiplicant %d is: ",M);
for(i=0;i<4;i++)
{
 printf("%d",m[i]);
}

binary(q,Q);
printf("\n\n\ Binary conversion of Multiplier %d is: ",Q);
for(i=0;i<4;i++)
{
 printf("%d",q[i]);
}
printf("\n\n\n Operation\tCarry \t     Accumulator      Multiplier \n");
printf("\n INITIAL ");
printf("\t %d",c);
printf("\t\t");
for(i=0;i<4;i++)
 {
  printf("%d",a[i]);
 }
 printf("\t\t");
for(i=0;i<4;i++)
 {
  printf("%d",q[i]);
 }
for(j=0;j<4;j++)
 {
 if(q[3]==1)
 {
 printf("\n a=a+m\t ");

 c=add(a,m,c) ;
 printf("\t %d",c);
 printf("\t\t");
 for(i=0;i<4;i++)
 {
  printf("%d",a[i]);
 }
  printf("\t\t");
 for(i=0;i<4;i++)
 {
  printf("%d",q[i]);
 }
 }
  printf("\n Shift \t");
  y=a[3];
  rightshift(c,a);
  rightshift(y,q);
  c=0;
  printf("\t %d",c);
  printf("\t\t");

  for(i=0;i<4;i++)
  {
   printf("%d",a[i]);
  }
   printf("\t\t");
  for(i=0;i<4;i++)
  {
   printf("%d",q[i]);
  }
 }
 printf("\n\n The answer in binary form is : ");
 for(i=0;i<4;i++)
 {
 ans[i]=a[i];
 }
 for(i=0;i<4;i++)
 {
 ans[i+4]=q[i];
 }
 for(i=0;i<8;i++)
 {
 printf("%d",ans[i]);
 }
 printf("\n\n Its decimal form is: ");
 for(i=7;i>=0;i--)
 {
 s=s+(pow (2,z)*ans[i]);
 z++;
 }
 printf("%d",s);
 getch();
}


