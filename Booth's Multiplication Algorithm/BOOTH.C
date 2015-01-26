#include<stdio.h>
#include<conio.h>
#include<math.h>

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
void binary(int a,int x[])
{
 int i,b[4]={0,0,0,0},c=0,t[4]={0,0,0,1};

  if(a>=0)
  {
   for(i=3;i>=0;i--)
   {
    b[i]=a%2;
    x[i]=a%2;
    a=a/2;
   }
  }
  else if(a<0)
  {
   a=a*(-1);
   for(i=3;i>=0;i--)
   {
    b[i]=a%2;
    x[i]=a%2;
    a=a/2;
   }
   for(i=0;i<4;i++)
   {
   b[i]=1-b[i];
   x[i]=1-x[i];
   }
   c=add(x,t,c);
  }
  for(i=0;i<4;i++)
  {
   x[i]=b[i];
  }
}

int sub(int p[],int k[],int carry)
{
 int i,x;
 int ones_compliment[4]={0,0,0,0},t[4]={0,0,0,1};
 for(i=0;i<4;i++)
 {
  ones_compliment[i]=1-k[i];
 }
 x=add(ones_compliment,t,carry);
 return add(p,ones_compliment,carry);
}


void shift(int x,int y[])
{
 int i;
 for(i=3;i>0;i--)
 y[i]=y[i-1];
 y[0]=x;
}

int main()
{
 int x,y,M[4]={0,0,0,0},Q[4]={0,0,0,0},i,ans[8],A[4]={0,0,0,0},c=0,j,q_1=0;
 int t[4]={0,0,0,1},T[4]={0,0,0,0};
 long int dec;
 //clrscr();
 printf("\n\n Enter multiplicant: ");
 scanf("%d",&x);
 binary(x,M);
 printf("\n Enter multiplier: ");
 scanf("%d",&y);

 binary(y,Q);
 printf("\n\n Binary of multiplicant: ");
 for(i=0;i<4;i++)
 {
  printf("%d",M[i]);
 }
 printf("\n Binary of multiplier: ");
 for(i=0;i<4;i++)
 {
  printf("%d",Q[i]);
 }
 getch();

 printf("\n\n Operation \t Accumulator \t Multiplier \t Q-1\n");
 printf("\n INITIAL ");
 printf("\t\t");
 for(i=0;i<4;i++)
  {
   printf("%d",A[i]);
  }
 printf("\t     ");
 for(i=0;i<4;i++)
 {
  printf("%d",Q[i]);
 }
 printf("\t   %d",q_1);

 for(j=0;j<4;j++)
 {
  if(Q[3]==1&&q_1==0)
 {
  printf("\n A=A-M \t");

  c=sub(A,M,c) ;
  printf("\t\t");
  for(i=0;i<4;i++)
   {
    printf("%d",A[i]);
   }
  printf("\t     ");
  for(i=0;i<4;i++)
   {
    printf("%d",Q[i]);
   }
  printf("\t   %d",q_1);
  printf("\t     ");
 }
 else if(Q[3]==0&&q_1==1)
 {
  printf("\n A=A+M \t");

  c=add(A,M,c) ;
  printf("\t\t");
  for(i=0;i<4;i++)
   {
    printf("%d",A[i]);
   }
  printf("\t     ");
  for(i=0;i<4;i++)
   {
    printf("%d",Q[i]);
   }
   printf("\t   %d",q_1);
  printf("\t     ");
 }
  printf("\n RShift ");
  y=A[3];
  shift(A[0],A);
  q_1=Q[3];
  shift(y,Q);

  printf("\t\t");
  for(i=0;i<4;i++)
   {
    printf("%d",A[i]);
   }
    printf("\t     ");
  for(i=0;i<4;i++)
   {
    printf("%d",Q[i]);
   }
   printf("\t   %d",q_1);
  printf("\t     ");

 }

 printf("\n \n The answer in binary form: ");
 for(i=0;i<4;i++)
 {
  ans[i]=A[i];
 }
 for(i=0;i<4;i++)
 {
  ans[i+4]=Q[i];
 }
 for(i=0;i<8;i++)
 {
  printf("%d",ans[i]);
 }
 if((x>=0&&y>=0)||(x<0&&y<0))
 {
  goto answer;
 }
 else
 {
  for(i=0;i<4;i++)
  {
   A[i]=1-A[i];
   Q[i]=1-Q[i];
  }
  c=0;
  c=add(Q,t,c);
  add(A,T,c);
  printf("\n \n Two's complement of answer: ");
  for(i=0;i<4;i++)
  {
   ans[i]=A[i];
  }
  for(i=0;i<4;i++)
  {
   ans[i+4]=Q[i];
  }
  for(i=0;i<8;i++)
  {
   printf("%d",ans[i]);
  }
  goto answer;
 }
 answer:
 dec=0;
 j=0;
 printf("\n\n The answer in decimal form: ");
  for(i=7;i>=0;i--)
  {
   dec+=((pow(2,j)*ans[i]));
   j++;
  }
  if((x>=0&&y>=0)||(x<0&&y<0))
  {
   printf("%d",dec);
  }
  else
  {
   printf("-%d",dec);
  }
  
  getch();
  return 0;
}
