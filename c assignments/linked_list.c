#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int no;
	struct node *next;
};


void create(struct node * head)                         //CREATION OF LINKED-LIST
{	
	printf("\nENTER NUMBER  ");
	scanf("%d",&head->no);
	int a;
	while(1)
	{
		struct node *temp;
		temp= (struct node *)malloc(sizeof(struct node));
		printf("\nENTER NUMBER  ");
		scanf("%d",&temp->no);
		head->next=temp;
		head=head->next;
		printf("\n\tCONTINUE ? (1/0)  ");
		scanf("%d",&a);
		if(a==0)
		{
			head->next=NULL;
			break;	
		}	
	}
}


void display(struct node *head)                      //DISPLAY THE LINKED LIST
{
	while(1)
	{
		if(head->next==NULL)
		{
			printf("\t%d\n",head->no);
			break;
		}
		else
		{
			printf("\t%d\n",head->no);
			head=head->next;
		}
	}
}	


struct node *first(struct node * head)
{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\nENTER NUMBER-  ");
		scanf("%d",&temp->no);
		temp->next=head;
		head=temp;
		return head;
}


struct node * after(struct node * head)
{
	int n,v=0;
	struct node * one;
	one=head;
	printf("\n\nENTER THE NUMBER AFTER WHICH NUMBER IS TO BE INSERTED ");
		scanf("%d",&n);
	while(1)
	{	
		while(1)
		{
			if(head->no==n)
			{
				struct node *temp;
				temp=(struct node*)malloc(sizeof(struct node));
				printf("\n\n\tENTER NUMBER-  ");
				scanf("%d",&temp->no);
				temp->next=head->next;
				head->next=temp;
				break;
			}
			else
			{		
				head=head->next;
				if(head==NULL)
				{
					printf("\n\n\tLOCATION NOT FOUND\n");
					v++;
					break;
				}
			}
		}
		head=one;
		return head;
	}	
}	


struct node * precede(struct node * head,int n)
{
	while(1)
	{
		if(head->next->no==n)
		{
			struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node));
			printf("\n\nENTER NUMBER-  ");
			scanf("%d",&temp->no);
			temp->next=head->next;
			head->next=temp;
			break;
		}
		else
			head=head->next;
	}
	return head;
}


struct node * before(struct node * head)
{
	int n,b=0,m,v=0;
	struct node *one;
	one=head;
	printf("\n\nENTER THE NUMBER BEFORE WHICH NUMBER IS TO BE INSERTED ");
	scanf("%d",&n);
	while(1)
	{
		while(1)
		{
			if(head->no==n)
			{
				b++;
				break;
			}
			else
			{	
				b=b+2;
				head=head->next;
				if(head==NULL)
				{
					printf("\n\n\tLOCATION NOT FOUND\n");
					v++;
					break;
				}
			}
		}
		if(v==1)
		{
			head=one;
			return head;
		}	
		while(head->next!=NULL)
		{	
			if(b==1)
			{
				head=first(head);
				return head;
			}
			else
			{
				head=one;
				head=precede(head,n);
				head=one;
				return head;
			}
		}
	}
}


struct node * insert(struct node * head)
{	
	while(1)
	{
		int a,b,c;
		printf("\n\t1.BEFORE ");
		printf("\n\t2.AFTER ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&a);
		if(a==1)
		{
			head=before(head);
			return head;			
		}
		else
		{
			head=after(head);
			return head;	
		}
	}
}


struct node * decline(struct node * head,int a)
{
	while(1)
	{
		if(head->next->no==a)
		{	
			head->next=head->next->next;	
			return head;
			break;
		}
		else
			head=head->next;
	}
}


struct node * delete(struct node * head)
{
	int a,b=0,v=0;
	struct node * one;
	one=head;
	printf("\nENTER THE VALUE TO BE DELETED  ");
	scanf("%d",&a);
	while(1)
	{
		while(1)
		{	
			if(head->no==a)
			{	
				b++;
				break;
			}
			else
			{
				b=b+2;
				head=head->next;
				if(head==NULL)
				{
					printf("\n\tLOCATION NOT FOUND\n ");
					v++;
				}
				break;
			}
		}
		if(v==1)
		{
			
			head=one;
			return head;
		}
		while(head->next!=NULL)
		{
			if(b==1)
			{	
				head=head->next;
				return head;
			}
			if(b!=1)
			{
				head=one;
				head=decline(head,a);
				head=one;
				return head;
			}
		}
	}
}


struct node * reverse(struct node *head)
{	
	struct node *one; 
	if(head==NULL)
	{
		return one;
	}
	else
	{
		one=reverse(head->next);
		printf("%d\n",head->no);
	}
	return head;
}


struct node * inverse(struct node *head)
{
	struct node *curr,*prev,*next;
	curr=head;
	prev=NULL;
	next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}


void main()
{	
	int a,b,c;
	struct node *head,*one;
	one=head;
	head= (struct node *)malloc(sizeof(struct node));
	create(head);
	while(1)
	{
		printf("\n\n\tCREATED LINKLIST\n\n");	
	 	display(head);
		printf("\n\nLIST OF OPERATIONS ");
		printf("\n\n1.INSERT");
		printf("\n\n2.DELETE ");
		printf("\n\n3.DISPLAY IN REVERSE ORDER ");
		printf("\n\n4.REVERT A LINKED-LIST ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:head=insert(head);
			break;
			case 2:head=delete(head);
			break;
			case 3: head=reverse(head);
			break;
			case 4:head=inverse(head);
				printf("\n\n\tINVERTED LINKED-LIST\n\n");
				display(head);
				head=inverse(head);
			break;
			default: printf("\n\n\tINVALID OPTION");
			break;
		}
		printf("\n\n\tCONTINUE ? (1/0)  ");
		scanf("%d",&c);
		if(c==0)
		{
			printf("\n\t\t\t\tTHANK-YOU!!!\n");
			break;
		}		
	}	
}

