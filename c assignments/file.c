#include<stdio.h>
#include<stdlib.h>
struct student
{
	int rollno;
	char name[20];
	float percentage;
}s1;

void getdata()
{
	int a;
	FILE *fp;
	fp=fopen("abc","wb");
	while(1)
	{
		printf("\nEnter rollno ");
		scanf("%d",&s1.rollno);
		printf("\nENTER NAME ");
		scanf("%s",s1.name);
		printf("\nEnter percentage ");
		scanf("%f",&s1.percentage);
		fwrite(&s1,sizeof(struct student ),1,fp);
		printf("Continue (1/0) ");
		scanf("%d",&a);
		if(a==0)
		break;
	}
	fclose(fp);
}

void display()
{
	FILE *fp;
	fp=fopen("abc","rb");
	while(fread(&s1,sizeof(struct student),1,fp)==1)
	//while(!feof(fp))
	{
		//fread(&s1,sizeof(struct student),1,fp);
		printf("\nROLL NO - %d",s1.rollno);
		printf("\nNAME - %s ",s1.name);
		printf("\nPERCENTAGE - %f",s1.percentage);
		printf("\n\n");
	}
	fclose(fp);
}


void add()
{
	int a;
	FILE *fp;
	fp=fopen("abc","ab");
	printf("\n\nEnter rollno ");
	scanf("%d",&s1.rollno);
	printf("\n\nENTER NAME ");
	scanf("%s",s1.name);
	printf("\n\nEnter percentage ");
	scanf("%f",&s1.percentage);
	fwrite(&s1,sizeof(struct student ),1,fp);
	fclose(fp);
}

void search()
{
	int q,r=0;
	FILE *fp;
	fp=fopen("abc","rb");
	printf("\nENTER ROLL NUMBER ");
	scanf("%d",&q);
	while(fread(&s1,sizeof(struct student),1,fp)==1)
	{
		if(s1.rollno==q)
		{
			r=1;
			printf("\nROLL NO - %d",s1.rollno);
			printf("\nNAME - %s ",s1.name);
			printf("\nPERCENTAGE - %f \n",s1.percentage);
			break;
		}
	}
	if(r==0)
	{
		printf("data not found");
	}
}

void delete()
{
	int q,flag=0;
	FILE *fp,*ft;

	fp=fopen("abc","rb");
	ft=fopen("xyz","wb");
	if(ft==NULL)
	{
		printf("file cannot be opened");
		exit(0);
	}
	else
	{
		printf("\nENTER ROLL NUMBER TO BE DELETED ");
		scanf("%d",&q);
		while(fread(&s1,sizeof(struct student),1,fp)==1)
		{
			if(s1.rollno==q)
			{
				flag=1;
				printf("\nRecord deleted!\n");
				continue;
			}
			else
			{
				fwrite(&s1,sizeof(struct student),1,ft);
			}
		}
		if(flag==0)
		printf("\ndata not found ");
		remove("abc");
		rename("xyz","abc");
		fclose(ft);
		fclose(fp);
	}
}

void modify()
{
	int q;
	FILE *fp,*ft;
	fp=fopen("abc","rb");
	ft=fopen("xyz","wb");
	printf("Enter the roll no to be modified  ");
	scanf("%d",&q);
	while(fread(&s1,sizeof(struct student),1,fp)==1)
	{
		if(s1.rollno==q)
		{
		}
		else
			fwrite(&s1,sizeof(struct student),1,ft);
	}
	fclose(fp);
	fclose(ft);
	int a;
	ft=fopen("xyz","ab");
	printf("\n\nEnter rollno ");
	scanf("%d",&s1.rollno);
	printf("\n\nENTER NAME ");
	scanf("%s",s1.name);
	printf("\n\nEnter percentage ");
	scanf("%f",&s1.percentage);
	fwrite(&s1,sizeof(struct student ),1,fp);
	fclose(ft);
	remove("abc");
	rename("xyz","abc");
}










int main()
{
	int n,m;
	FILE *fp;
	fp=fopen("abc","wb");
	if(fp==NULL)
	{
		printf("file cannot be opened ");
		exit(0);
	}
	getdata();
	do
	{
		printf("\nLIST OF OPERATIONS ");
		printf("\n1.ADD ");
		printf("\n2.DISPLAY ");
		printf("\n3.SEARCH ");
		printf("\n4.DELETE ");
		printf("\n5.MODIFY ");
		printf("\nENTER YOUR CHOICE ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:add();
			break;
			case 2:display();
			break;
			case 3: search();
			break;
			case 4: delete();
			break;
			case 5: modify();
		}
		printf("\nContinue (1/0) ");
		scanf("%d",&m);
	}while(m==1);
	fclose(fp);
}









