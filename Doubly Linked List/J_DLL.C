#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
void insertbeg();
void insertend();
void insertmid();
void delbeg();
void delend();
void delmid();
void reverse();

struct dllnode
{
	int data;
	struct dllnode *next;
	struct dllnode *prev;

};

struct dllnode *head=NULL;


void insertbeg(struct dllnode *p)
{
	if(head==NULL)
	{
		head=(struct dllnode *)malloc(sizeof(struct dllnode));
		head->data=p->data;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		head->prev=p;
		p->next=head;
		head=p;
	}
	printf("\n Node has been inserted");
}


void insertend(struct dllnode *p)
{
	if(head==NULL)
	{
		head=(struct dllnode*)malloc(sizeof(struct dllnode));
		head->data=p->data;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		struct dllnode *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
		p->prev=temp;
		p->next=NULL;
	}
	printf("\n Node has been inserted ");
}


void insertmid(struct dllnode *p,int data)
{
	struct dllnode *temp;
	if(head==NULL)
	{
		head=(struct dllnode *)malloc(sizeof(struct dllnode));
		head->data=p->data;
		head->next=NULL;
		head->prev=NULL;
		printf("\n Node has been inserted ");
	}
	else
	{
		temp=head;
		while((temp!=NULL)&&(temp->data!=data))
		{
			temp=temp->next;
		}
		if(temp!=NULL)
		{
			p->next=temp->next;
			temp->next=p;
			p->prev=temp;
			if(p->next!=NULL)
			{
				p->next->prev=p;
			}
			printf("\n Node has been inserted ");
		}
		else
		printf("\n Node does not exist");
	}
}


void delbeg()
{
	struct dllnode *temp;
	if(head==NULL)
	{
		printf("\n LinkedList is empty");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
		head->prev=NULL;
		printf("\n Node has been deleted ");
	}
}


void delend()
{
	struct dllnode *temp;
	if(head==NULL)
	{
		printf("\n LinkedList is Empty");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		printf("\n Node has been deleted ");
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
		printf("\n Node has been deleted ");
	}
}


void delmid(int data)
{
	struct dllnode *temp;
	if(head==NULL)
	{
		printf("\n LinkedList is empty");
	}
	else if((head->next==NULL)&&(head->data==data))
	{
	  head=NULL;
	  printf("\n Node has been deleted ");
	}
	else
	{
		temp=head;
		while((temp!=NULL)&&(temp->data!=data))
		{
			temp=temp->next;
		}
	}
	if(temp!=NULL)
	{
		if(temp->prev!=NULL)
		{
			temp->prev->next=temp->next;
		}
		if(temp->next!=NULL)
		{
			temp->next->prev=temp->prev;
		}
		free(temp);
		printf("\n Node has been deleted ");
	}
	else
		printf("\n Node doesn't exist");
}


void printlist()
{
	struct dllnode * temp;
	if(head==NULL)
	{
		printf("\n LinkedList is empty");
	}
	else
	{
		printf("\n The LinkedList is : ");
		temp=head;
		while(temp->next!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
      }
}


void reverse()
{
	struct dllnode *prev,*temp,*next;
	prev=NULL;
	temp=head;
	while(temp!=NULL)
	{
		next=temp->next;
		temp->next=prev;
		prev=temp;
		temp=next;
	}
	head=prev;
	printf("\n LinkedList is reversed");
}


void main()
{
	int choice,x,y,data;
	struct dllnode *p;
	clrscr();

	head=NULL;

	do
	 {
		printf("\n\n Enter choice :  \n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at middle \n 4.Delete at beginning \n 5.Delete at end \n 6.Delete at middle \n 7.Print the list \n 8.Reverse \n 9.Exit ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			p=(struct dllnode*)malloc(sizeof(struct dllnode));
			printf("\n Enter data at new node : ");
			scanf("%d",&p->data);
			p->next=NULL;
			insertbeg(p);
			break;

		case 2:
			p=(struct dllnode*)malloc(sizeof(struct dllnode));
			printf("\n Enter data at end : ");
			scanf("%d",&p->data);
			p->next=NULL;
			insertend(p);
			break;
		case 3:
			p=(struct dllnode*)malloc(sizeof(struct dllnode));
			printf("\n Enter data after which you want to insert : ");
			scanf("%d",&data);
			printf("\n Enter data to be entered : ");
			scanf("%d",&p->data);
			p->next=NULL;
			insertmid(p,data);
			break;

		case 4:
			delbeg();
			break;

		case 5:
			delend();
			break;

		case 6:
			printf("\n Enter data to be deleted : ");
			scanf("%d",&x);
			delmid(x);
			break;

		case 7:
			printlist();
			break;

		case 8:
			reverse();
			break;

		case 9:
			exit(0);
			break;

		default: printf("\n Wrong choice!!");
		}
	}while(choice!=9);
}
