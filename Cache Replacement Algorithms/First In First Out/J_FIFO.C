#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
int frame[4]={0,0,0,0},data[15],i,j,k,fault=0,hit=0,count=0,n,flag;
clrscr();
printf("\nEnter the no. of element in data sequence : ");
scanf("%d",&n);
printf("\nEnter the elements : \n");
for(i=0;i<n;i++)
{ 	scanf("\n%d",&data[i]);
}

for(i=0;i<n;i++)
{	flag=0;
	if(count==4)
	{	count=0;
	}
	for(j=0;j<4;j++)
	{
		if(data[i]==frame[j])
		{
			flag=1;
			break;
		}
	}

	if(flag==0)
	{	 frame[count]=data[i];
		 fault++;
		 count++;
	}
	else if(flag==1)
	{       hit++;
	}


	for(k=0;k<4;k++)
	{printf("\t%d",frame[k]);
	}
	printf("\n");
}
printf("\n Faults = %d  Hits = %d",fault,hit);
getch();
}

