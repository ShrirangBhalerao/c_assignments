#include<stdio.h>
#include<stdlib.h>
int length(char *s1)
{
	int i;
	for(i=0;*(s1+i)!='\0';i++)
	{	
	}	
	printf("\tLENGTH OF STRING IS %d ",i);
	printf("\n");
	return i;
}

void palindrome(char *s1,int *a)
{
	int i,j,flag=0;
	for(i=0,j=*(a-1);i<=j;i++,j--)
	{ 
		flag=0;
		if(*(s1+i)==*(s1+j))
		{
			flag=1;
		}
		else
		{
			break;
		}
	}
	if(flag==1)
	{
		printf("\tGIVEN STRING IS PALINDROME");
		printf("\n");
	}
	else
	{
		printf("\tGIVEN STRING IS NOT  PALINDROME");
		printf("\n");
	}
}
void comparison(char *s1,int *a)
{
	int i,j,flag=0,k;
	char *s2;
	s2=(char*)malloc(sizeof(char)*20);
	printf("\tENTER ANOTHER STRING  ");
	scanf("%s",s2);
	k=length(s2);
	if(k==*a)
	{
		for(i=0;i<=*a;i++)
		{	
			flag=0;
			if(*(s1+i)==*(s2+i))
			{
				flag=1;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	if(flag==1)
	{
		printf("\tSTRINGS ARE SAME");
		printf("\n");
	}	
	else
	{
		printf("\tSTRINGS ARE NOT SAME");
		printf("\n");
	}	
}

void reverse(char *s1,int *a)
{
	
	int i,j,k;
	char *s2,p;
	s2=(char*)malloc(sizeof(char)* *a);
	for(k=0;k<*a;k++)
	{
		*(s2+k)=*(s1+k);
	}
	for(i=0,j=*a-1;i<=j;i++,j--)
	{
		p=*(s2+i);
		*(s2+i)=*(s2+j);
		*(s2+j)=p;	
	}
	*(s2+k)='\0';
	printf("\tREVERSE OF STRING IS  %s",s2);
	printf("\n");
}

void copy(char *s1,char *s2)
{
	s2=s1;
	printf("\tTHE ORIGINAL STRING - %s ",s1);
	printf("\n");
	printf("\t%s",s2);
	printf("\n");
	printf("\tSTRING IS COPIED ");
	printf("\n");
}

void substring(char *s1)
{
	int a,j,b,c=0;
	char *s2;
	s2=(char*)malloc(sizeof(char)*5);
	printf("\nENTER THE SUBSTRING WHICH YOU WANT TO CHECK ");
	scanf("%s",s2);
	j=length(s2);
	a=0,b=0;
	while(*(s1+a)!='\0')
	{

		while(*(s1+a)==*(s2+b) && *(s1+a)!='\0')
		{
			a++;
			b++;
		}
		if(b==j)
		{
			b=0;
			c++;
		}
		if(*(s1+a)!=*(s2+b))
		{
			if( b==0)
			{
				a++;
			}
			else
			{
				b=0;
			}
		}
	}	
	printf("\n\tTHE ENTERED SUBSTRING IS FOUND %d TIMES ",c);
	printf("\n");
}
int main()
{
	int i,ch,p,q;
	char *s1,*s2;
	s1=(char*)malloc(sizeof(char)*20);
	s2=(char*)malloc(sizeof(char)*20);
	printf("\tENTER THE STRING ");
	scanf("%s",s1);
	do
	{
		printf("\n\tENTERED STRING IS %s",s1);
		printf("\n");
		printf("\nLIST OF OPERATIONS");
		printf("\n1. LENGTH OF STRING");
		printf("\n2. PALINDROME");
		printf("\n3.STRING COMPARISON");
		printf("\n4.COPY A STRING");
		printf("\n5.REVERSE A STRING");
		printf("\n6.FINDING OUT A SUBSTRING");
		printf("\n");
		printf("\nENTER YOUR CHOICE ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:q=length(s1);
			break;
			case 2:palindrome(s1,&q);
			break;
			case 3:comparison(s1,&q);
			break;
			case 4:copy(s1,s2);
			break;
			case 5:reverse(s1,&q);
			break;
			default:printf("\tINVALID OPTION\n");
			break;
			case 6:substring(s1);
			break;
		}
	printf("\n\tWOULD YOU LIKE TO PERFORM ANY OTHER OPERATION (1/0)  ");
	scanf("%d",&p);
	printf("\n");
	}while(p==1);
	printf("\t\t\t THANK-YOU!!");
	printf("\n");
	return 0;
}

