#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int no,age;
char name[30];
char bg[5];
struct node *prev,*next;
};

struct node *create(struct node * head)
{
	char a[5];
	head->prev=NULL;
	printf("\n\nENTER THE ROLL_NUMBER  ");
	scanf("%d",&head->no);
	printf("\n\nENTER THE NAME  ");
	scanf("%s",head->name);
	printf("\n\nENTER THE AGE  ");
	scanf("%d",&head->age);
	printf("\n\nENTER BLOOD-GROUP  ");
	scanf("%s",head->bg);
	head->next=NULL;
	while(1)
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\nENTER THE ROLL_NUMBER  ");
		scanf("%d",&temp->no);
		printf("\n\nENTER THE NAME  ");
		scanf("%s",temp->name);
		printf("\n\nENTER THE AGE  ");
		scanf("%d",&temp->age);
		printf("\n\nENTER BLOOD-GROUP  ");
		scanf("%s",temp->bg);
		temp->prev=head;
		temp->next=NULL;
		head->next=temp;
		head=head->next;
		printf("\n\nCONTINUE ? (yes/no)   ");
		scanf("%s",a);
		if(strcmp(a,"no")==0)
		{
			head->next=NULL;
			break;
		}	
	}
	return head;
}	

void display(struct node *head)                      //DISPLAY THE LINKED LIST
{
	while(1)
	{
		if(head->next==NULL)
		{
			printf("\tROLL_NO - %d\n",head->no);
			printf("\n\tNAME - %s\n",head->name);
			printf("\n\tAGE - %d yrs\n",head->age);
			printf("\n\tBLOOD-GROUP - %s\n",head->bg);
			printf("\n***********************************\n\n");
			break;
		}
		else
		{
			printf("\n\tROLL_NO - %d\n",head->no);
			printf("\n\tNAME - %s\n",head->name);
			printf("\n\tAGE - %d yrs\n",head->age);
			printf("\n\tBLOOD-GROUP - %s\n",head->bg);
			printf("\n***********************************\n\n");
			head=head->next;
		}
	}
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
				printf("\n\nENTER THE NUMBER  ");
				scanf("%d",&temp->no);
				printf("\n\nENTER THE NAME  ");
				scanf("%s",temp->name);
				printf("\n\nENTER THE AGE  ");
				scanf("%d",&temp->age);
				printf("\n\nENTER BLOOD-GROUP  ");
				scanf("%s",temp->bg);
				temp->next=head->next;
				temp->prev=head;
				head->next=temp;
				head->next->prev=temp;
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
	struct node *one=head;
	while(1)
	{
		if(head->no==n)
		{
			struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node));
			printf("\n\nENTER THE NUMBER  ");
			scanf("%d",&temp->no);
			printf("\n\nENTER THE NAME  ");
			scanf("%s",temp->name);
			printf("\n\nENTER THE AGE  ");
			scanf("%d",&temp->age);
			printf("\n\nENTER BLOOD-GROUP  ");
			scanf("%s",temp->bg);
			temp->next=head;
			temp->prev=head->prev;
			head->prev->next=temp;
			head->prev=temp;	
			break;
		}
		else
			
			head=head->next;
	}
	head=one;
	return head;
}

struct node *first(struct node * head)
{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n\nENTER THE NUMBER  ");
		scanf("%d",&temp->no);
		printf("\n\nENTER THE NAME  ");
		scanf("%s",temp->name);
		printf("\n\nENTER THE AGE  ");
		scanf("%d",&temp->age);
		printf("\n\nENTER BLOOD-GROUP  ");
		scanf("%s",temp->bg);
		temp->next=head;
		head=temp;
		temp->prev=NULL;
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
		if(head->no==a)
		{	
			head->next->prev=head->prev;
			head->prev->next=head->next;	
			return head;
			//break;
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
				head->prev=NULL;
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
	while(head->next!=NULL)
	{
		head=head->next;
	}
	while(1)
	{
		if(head->prev==NULL)
		{
			printf("\tROLL_NO - %d\n",head->no);
			printf("\n\tNAME - %s\n",head->name);
			printf("\n\tAGE - %d yrs\n",head->age);
			printf("\n\tBLOOD-GROUP - %s\n",head->bg);
			printf("\n***********************************\n\n");
			break;
		}
		else
		{
			printf("\n\tROLL_NO - %d\n",head->no);
			printf("\n\tNAME - %s\n",head->name);
			printf("\n\tAGE - %d yrs\n",head->age);
			printf("\n\tBLOOD-GROUP - %s\n",head->bg);
			printf("\n***********************************\n\n");
			head=head->prev;
		}
	}
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


struct node * modify(struct node *head) //modification of data
{
	struct node *one=head;
	int a,b,c=0;
	printf("\n\tENTER THE ROLL NO WHOSE DETAILS ARE TO BE MODIFIED");
	scanf("%d",&a);
	while(1)
	{
		if(head->no==a)
		{
			c++;
			printf("\n\n\tWHICH DETAILS ARE TO BE MODIFIED");
			printf("\n\n\t1.NAME");
			printf("\n\n\t2.ROLL_NO");
			printf("\n\n\t3.AGE");
			printf("\n\n\t4.BLOOD_GROUP");
			printf("\n\n\t\tENTER YOUR CHOICE  ");
			scanf("%d",&b);
			switch(b)
			{
				case 1:printf("\n\nENTER NEW NAME  "); 
				scanf("%s",head->name);
				break;
				case 2:printf("\n\nENTER NEW ROLL_NO  "); 
				scanf("%d",&head->no);
				break;
				case 3:printf("\n\nENTER NEW AGE  "); 
				scanf("%d",&head->age);
				break;
				case 4:printf("\n\nENTER NEW BLOOD_GROUP  ");  
				scanf("%s",head->bg);
				break;
			}
			break;
		}
		else
			head=head->next;
		if(head==NULL&c==0)
		{
			printf("\n\tDATA NOT FOUND");
			break;
		}
	}
	return one;
}



void main()
{	
	int a,b;
	char c[5];
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
		printf("\n\n5.MODIFY ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&a);
		printf("\n");
		switch(a)
		{
			case 1:head=insert(head);
			break;
			case 2:head=delete(head);
			break;
			
			case 3:reverse(head);
			break;
			
			case 4:head=inverse(head);
				printf("\n\n\tINVERTED LINKED-LIST\n\n");
				display(head);
				head=inverse(head);
			break;
			case 5:head=modify(head);
			break;
			default: printf("\n\tINVALID OPTION");
			break;
			
		}
		printf("\n\tCONTINUE ? (yes/no)  ");
		scanf("%s",c);
		if(strcmp(c,"no")==0)
		{					
			printf("\n\tTHANK-YOU!!\n\n");
			break;
		}	
	}
}

