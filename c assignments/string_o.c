#include<stdio.h>

int length(char s1[])              //length of string
{
	int i;
	for(i=0;s1[i]!='\0';i++)
	{	
	}	
	return i;                //length is returned to main function 
}


void palindrome(char s1[])            //palindrome of string
{
	int a,i,j,flag=0;
	a=length(s1);
	for(i=0,j=(a-1);i<=j;i++,j--)
	{ 
		flag=0;
		if(s1[i]==s1[j])
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


void comparison(char s1[])             //comparison of string
{
	int i,j,flag=0,k, a;
	char s2[20];
	a=length(s1);
	printf("\tENTER ANOTHER STRING  ");
	scanf("%s",s2);
	k=length(s2);
	if(k==a)
	{
		for(i=0;i<a;i++)
		{	
			if(s1[i]==s2[i])
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
		printf("\t\nSTRINGS ARE SAME");
		printf("\n");
	}	
	else
	{
		printf("\t\nSTRINGS ARE NOT SAME");
		printf("\n");
	}	
}


void reverse(char s1[])               //reverse of string
{
	int a,i,j,p,x=0;
	char k,s2[a];
	a=length(s1);
	for(p=0;p<a;p++)
	{
		s2[x]=s1[p];
		x++;
	}	
	for(i=0,j=a-1;i<=j;i++,j--)
	{
		k=s2[i];
		s2[i]=s2[j];
		s2[j]=k;
	}
	s2[x]='\0';
	printf("\tREVERSE OF STRING IS  %s",s2);
	printf("\n");
}


void copy(char s1[],char s2[])            //to copy a string
{
	int i,j=0,a;
	a=length(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		s2[j]=s1[i];
		j++;
	}
	s2[j]='\0';
	printf("\tORIGINAL STRING IS - %s ",s1);
	printf("\n");
	printf("\t%s",s2);
	printf("\t\n");
	printf("\tSTRING IS COPIED ");
	printf("\n");
}


void substring(char s1[])           //to find substring
{
	int a,j,b,c=0,i;
	char s2[5];
	i=length(s1);
	printf("ENTER THE SUBSTRING WHICH YOU WANT TO CHECK ");
	scanf("%s",s2);
	j=length(s2);
	do
	{	
		if(i<j)
		{
			printf("\tINVALID SUB-STRING,ENTER AGAIN  ");
			scanf("%s",s2);
			j=length(s2);
		}
	}while(i<j);
	a=0,b=0;
	while(s1[a]!='\0')
	{
		while(s1[a]==s2[b] && s1[a]!='\0')
		{
			a++;
			b++;
		}
		if(b==j)
		{
			b=0;
			c++;
		}
		if(s1[a]!=s2[b] )
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
	printf("\n\tENTERED SUBSTRING %s FOUND %d TIMES",s2,c);
	printf("\n");
}


int main()         //main function
{
	int i,ch,p,q;
	char s1[20],s2[20];
	printf("\tENTER THE STRING ");
	scanf("%s",s1);
	do
	{
		printf("\n\tENTERED STRING IS %s",s1);
		printf("\n");
		printf("\n\n\tLIST OF OPERATIONS\n");
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
			case 1:
				{	q=length(s1);
					printf("\n\tLENGTH OF STRING IS %d\n",q);
				}
			break;
			case 2:palindrome(s1);
			break;
			case 3:comparison(s1);
			break;
			case 4:copy(s1,s2);
			break;
			case 5:reverse(s1);
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
	printf("\t\t\tTHANK-YOU!!");
	printf("\n");
	return 0;
}

