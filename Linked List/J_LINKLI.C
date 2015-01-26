#include<stdio.h>
#include<conio.h>
void insertbeg();
void insertend();
void insertmid();
void delbeg();
void delend();
void delmid();
void reverse();

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;


void insertbeg(struct node *p)
{
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=p->data;
		head->next=NULL;
	}
	else
	{	p->next=head;
		head=p;
	}
	printf("\n Node has been inserted");
}


void insertend(struct node *p)
{
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=p->data;
		head->next=NULL;
	}
	else
	{
		struct node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
		p->next=NULL;
	}
	printf("\n Node has been inserted ");
}


void insertmid(struct node *p,int data)
{
	struct node *temp;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=p->data;
		head->next=NULL;
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
			printf("\n Node has been inserted ");
		}
		else
		printf("\n Node does not exist");
	}
}


void delbeg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\n LinkedList is empty");
	}
	else
	{
		temp=head;
		head=head->next;
		free(temp);
		printf("\n Node has been deleted ");
	}
}


void delend()
{
	struct node *temp,*prev;
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
			prev=temp;
			temp=temp->next;
		}
		free(temp);
		prev->next=NULL;
		printf("\n Node has been deleted ");
	}
}


void delmid(int data)
{
	struct node *temp,*prev;
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
		while(temp!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
	}
	if(temp!=NULL)
	{
		prev->next=temp->next;
		free(temp);
		printf("\n Node has been deleted ");
	}
	else
		printf("\n Node doesn't exist");
}


void printlist()
{
	struct node * temp;
	if(head==NULL)
	{
		printf("\n LinkedList is empty");
	}
	else
	{
		printf("\n The LinkedList is : ");
		temp=head;
		while(temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
      }
}


void reverse()
{
	struct node *prev,*temp,*next;
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
	struct node *p;
	clrscr();

	head=NULL;

	do
	 {
		printf("\n\n Enter choice :  \n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at middle \n 4.Delete at beginning \n 5.Delete at end \n 6.Delete at middle \n 7.Print the list \n 8.Reverse \n 9.Exit ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			p=(struct node*)malloc(sizeof(struct node));
			printf("\n Enter data at new node : ");
			scanf("%d",&p->data);
			p->next=NULL;
			insertbeg(p);
			break;

		case 2:
			p=(struct node*)malloc(sizeof(struct node));
			printf("\n Enter data at end : ");
			scanf("%d",&p->data);
			p->next=NULL;
			insertend(p);
			break;
		case 3:
			p=(struct node*)malloc(sizeof(struct node));
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
