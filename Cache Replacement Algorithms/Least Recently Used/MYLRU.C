#include<stdio.h>
#include<stdlib.h>

int main()
{
int frame[4]={-1,-1,-1,-1},fs[4],data[15],x,p,l,m,index,y,z,fault=0,hit=0,n,flag1=0,flag2=0;
printf("\nEnter the no. of element in data sequence (Max 15): ");
scanf("%d",&n);
printf("\nEnter the elements : \n");
for(x=0;x<n;x++)
{
	scanf("\n%d",&data[x]);
}
for(x=0;x<n;x++)
{	flag1=0;
	flag2=0;

	for(y=0;y<4;y++)
	{
		if(frame[y]==data[x])
		{
			flag1=1;
			flag2=1;
			break;
		}
	}

	if(flag1==0)
	{	 for(z=0;z<4;z++)
		{	if(frame[z]==-1)
			{
				frame[z]=data[x];
				flag2=1;
				break;
			}
		}
	}

	else if(flag1==1)
	{       hit++;
	}

	if(flag2==0)
	{
		for(z=0;z<4;z++)
		{
			fs[z]=0;
		}
		for(p=x-1,l=1;l<4;p--,l++)
		{	for(z=0;z<4;z++)
			{
				if(frame[z]==data[p])
				{
					fs[z]=1;
				}
			}
		}
		for(m=0;m<4;m++)
		{
			if(fs[m]==0)
			{
				index=m;
			}
		}
		frame[index]=data[x];
		fault++;
	}

	for(z=0;z<4;z++)
	{printf("\t%d",frame[z]);
	}
	printf("\n");
}
printf("\n Faults = %d  Hits = %d\n",fault,hit);
return 0;
}
