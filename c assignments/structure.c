#include<stdio.h>

struct Bank                                     //STRUCTURE OF BANK
{
 	int acc_no;
	char name[30];
	struct b_date                      //NESTED STRUCTURE OF BIRTH DATE
	{
		int day;
		int month;
		int year;
	}b[100];
	char pan_no[10];
	int balance;
	int t_no;
};

int a=1000;

void getdata(struct Bank s[],int i )        //FUNCTION TO INPUT DATA FROM USER
{
	s[i].acc_no=a;
	printf("\nACC.NO.- %d",s[i].acc_no);
	printf("\n\nNAME- ");
	scanf("%s",s[i].name);
	printf("\nBIRTH DATE- ");
	scanf("%d",&s[i].b[i].day);
	scanf("%d",&s[i].b[i].month);
	scanf("%d",&s[i].b[i].year);
	while(s[i].b[i].day >31||s[i].b[i].month >12)
	{
		printf("\n\tINVALID BIRTH-DATE ,ENTER AGAIN");
		scanf("%d",&s[i].b[i].day);
		scanf("%d",&s[i].b[i].month);
		scanf("%d",&s[i].b[i].year);
	}	
	printf("\nPAN NO- ");
	scanf("%s",s[i].pan_no);
	while(s[i].pan_no[0]<65)
	{
		printf("\n\n\tINVALID PAN NUMBER,ENTER AGAIN");
		scanf("%s",s[i].pan_no);
	}
	printf("\nBALANCE- Rs. ");
	scanf("%d",&s[i].balance);
	a++;
	printf("\n************************************\n");
}

int search(struct Bank s[],int c)                 //FUNCTION TO SEARCH DATA FROM DATABASE
{
	int i,a,flag;
	printf("\n\tENTER ACCOUNT NUMBER ");
	scanf("%d",&a);
	for(i=0;i<c;i++)
	{	 
		flag=0;
		if(s[i].acc_no==a)
		{
			return i;
		}
		else
		{
			flag=1;
		}	
	}
	if(flag==1)
	{
		
		printf("\n\tDATA NOT FOUND");
		return (flag*1000);
	}

}


void display(struct Bank s[],int i)                     //FUNCTION TO DISPLAY  DATABASE
{
	printf("\n\n\tACC NO- %d",s[i].acc_no);
	printf("\n\n\tCUSTOMER'S NAME - %s",s[i].name);
	printf("\n\n\tBIRTH DATE -  %d-%d-%d",s[i].b[i].day,s[i].b[i].month,s[i].b[i].year);
	printf("\n\n\tPAN NO- %s",s[i].pan_no);
	printf("\n\n\tBALANCE- Rs. %d",s[i].balance);
	printf("\n\n\tTRANSACTION NO- %d",s[i].t_no);
}


void delete(struct Bank s[],int c)              //FUNCTION TO DELETE DATA FROM DATABASE
{
	int a,j;
	a=search(s,c);
	for(j=a;j<c-1;j++)
	{	
		s[j]=s[j+1];
		s[j].b[j]=s[j+1].b[j+1];
	}
}

void modify(struct Bank s[],int m)        //FUNCTION TO MODIFY DATA FROM DATABASE
{
	int a, n,v;
	do
	{
	printf("\n\tLIST OF OPERATIONS\n");
	printf("\n1.ACCOUNT NUMBER");
	printf("\n2.PAN NUMBER");
	printf("\n3.BIRTH-DATE");
	printf("\n4.BALANCE");
	printf("\nWHAT WOULD U LIKE TO MODIFY ");
	scanf("%d",&a);
	switch(a)
	{
		case 1: {
				printf("\nENTER NEW ACCOUNT NUMBER");
				scanf("%d",&s[m].acc_no);
				printf("\n\tACCOUNT NUMBER UPDATED");
			}
				break;

		case 2:{
				printf("\nENTER NEW PAN NUMBER");
				scanf("%s",s[m].pan_no);
				printf("\n\tPAN NUMBER UPDATED");
			}
						break;
		case 3:{
				printf("\nENTER NEW BIRTH DATE NUMBER");
				scanf("%d%d%d",&s[m].b[m].day,&s[m].b[m].month,&s[m].b[m].year);
				printf("\n\tBIRTH-DATE UPDATED");
			}
				break;
		case 4:{
			int x,h,n;
		do
		{
			printf("\n\tCURRENT BALANCE- Rs. %d",s[m].balance);
			printf("\n\nWHAT WOULD U LIKE TO PERFORM");
			printf("\n\n1.WITHDRAW\n2.DEPOSIT");
			printf("\n\nENTER YOUR CHOICE ");
			scanf("%d",&x);
			switch(x)
			{
				case 1:
				{
					printf("\nENTER THE AMMOUNT TO BE WITHDRAWEN ");
					scanf("%d",&h);
					if(h>s[m].balance)
					{
						printf("\n\tINSUFICIANT BALANCE");
						break;
					}
					s[m].balance=s[m].balance-h;
					s[m].t_no++;
				}
				break;
				case 2:
				{
					printf("\nENTER THE AMMOUNT TO BE DEPOSITED ");
					scanf("%d",&h);
					s[m].balance=s[m].balance+h;
					s[m].t_no++;
				}
				break;
			}
			printf("\n\n WOULD U LIKE TO PERFORM  ANY OTHER TRANSACTION (1/0) ");
			scanf("%d",&n);
		}while(n==1);


	printf("\n\n WOULD U LIKE TO MODIFY (1/0) ");
	scanf("%d",&v);
		}
	}	
	}while(v==1);
}		

void table(struct Bank s[],int i)                //FUNCTION TO DISPLAY DATABASE IN TABULAR FORM
{
printf("\n%d\t\t\t",s[i].acc_no);
	printf("%s\t\t\t",s[i].name);
printf("%d-%d-%d\t\t\t",s[i].b[i].day,s[i].b[i].month,s[i].b[i].year);
	printf("%s\t\t\t",s[i].pan_no);
	printf("%d\t\t\t",s[i].balance);
	printf("%d\t\t\t",s[i].t_no);
	printf("\n");
}


int main()                                         //MAIN FUNCTION
{
	int c,i,a,ch,w,p,m;
	struct  Bank s[100];
	printf("\nENTER THE PRESENT NUMBER OF ACCOUNT HOLDERS IN BANK ");
	scanf("%d",&c);
	do
	{
		printf("\n\n\tLIST OF OPERATIONS\n ");
		printf("\n1.CREATE THE DATABASE  ");
		printf("\n2.ADD RECORD ");
		printf("\n3.SEARCH A RECORD ");
		printf("\n4.DELETE A RECORD ");
		printf("\n5.MODIFY A RECORD ");
		printf("\n6.DISPLAY THE DATABASE ");
		printf("\n7.DISPLAY DATABASE IN TABULAR FORM");
		printf("\n\n\tENTER YOUR CHOICE  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
					for(i=0;i<c;i++)
					getdata(s,i);
				}
			break;
			case 2:{
				getdata(s,c);
				c++;
				}
			break;
			case 3:{
				w=search(s,c);
				if(w!=1000)
					display(s,w);
				}
			break;
			case 4:{
					delete(s,c);
					c--;
					printf("\n\tACCOUNT HAS BEEN DELETED");
				}
			break;
			case 5: {
					  m=search(s,c);
					  modify(s,m);
					}
			break;
			case 6:{
				for(i=0;i<c;i++)
				display(s,i);
				}
				break;
			
			case 7:
			{
			printf("\n");
			printf("\n********************************************************************************************************************************************\n\n");
printf("ACC.NO\t\t\tNAME\t\t\tBIRTH-DATE\t\t\tPAN NO\t\t\tBALANCE\t\t\tTRANSACTION NO\n");
			for(i=0;i<c;i++)
			table(s,i);
			printf("\n********************************************************************************************************************************************\n\n");
			}
			break;
			}
			
			printf("\n\nWOULD YOU LIKE TO PERFORM ANY OTHER OPERATION (1/0) ");
			scanf("%d",&p);
			}while(p==1);
			return 0;
}
