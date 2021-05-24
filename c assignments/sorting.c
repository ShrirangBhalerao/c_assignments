#include<stdio.h>
#include<string.h>


void bubble(char a[][20],int i)                       //BUBBLE SORT
{
	int x,y,z,xx,yy;
	char q[20];
	while(1)
	{
		printf("\n\tTYPE OF ARRANGING\n ");
		printf("\n1.ASCENDING ");
		printf("\n2.DESCENDING ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&x);
		printf("\n\tLIST BEFORE SORTING\n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		if(x==1)
		{
			for(y=0;y<i-1;y++)
			{
				for(z=0;z<(i-1-y);z++)
				{
					if(strcmp(a[z],a[z+1])>0)
					{
						strcpy(q,a[z]);
						strcpy(a[z],a[z+1]);
						strcpy(a[z+1],q);
					}
				}	
				printf("\nPASS NO- %d\t",y+1);
				for(xx=0;xx<i;xx++)
				{
					printf("%s  ",a[xx]);
				}
				printf("\n");
			}
		}
		else
		{
			for(y=0;y<i-1;y++)
			{
				for(z=0;z<(i-1-y);z++)
				{
					if(strcmp(a[z],a[z+1])<0)
					{
						strcpy(q,a[z]);
						strcpy(a[z],a[z+1]);
						strcpy(a[z+1],q);
					}
				}
				printf("\nPASS NO- %d\t",y+1);
				for(xx=0;xx<i;xx++)
				printf("%s  ",a[xx]);
				printf("\n");
			}
		}
		printf("\n\tLIST AFTER SORTING \n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		printf("\nCONTINUE (1/0) ");
		scanf("%d",&yy);
		if(yy==0)
			break;
	}
}


void insertion(char a[][20],int i)                               //INSERTION SORT
{
	int x,y,z,xx,yy;
	char q[20];
	while(1)
	{
		printf("\n\n\tTYPE OF ARRANGING\n ");
		printf("\n1.ASCENDING ");
		printf("\n2.DESCENDING\n ");
		printf("\n\tENTER YOUR CHOICE ");
		scanf("%d",&x);
		printf("\n\n\tLIST BEFORE SORTING\n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		if(x==1)
		{
			for(x=1;x<i;x++)
			{
				strcpy(q,a[x]);
				for(y=(x-1);y>=0&& strcmp(q,a[y])<0;y--)
				{
					strcpy(a[y+1],a[y]);
				}
				strcpy(a[y+1],q);
				printf("\nPASS NO- %d\t",x);
				for(xx=0;xx<i;xx++)
					printf("%s  ",a[xx]);
				printf("\n");
			}
		}
		else
		{
			for(x=1;x<i;x++)
			{
				strcpy(q,a[x]);
				for(y=(x-1);y>=0&& strcmp(q,a[y])>0;y--)
				{
					strcpy(a[y+1],a[y]);
				}
				strcpy(a[y+1],q);
				printf("\nPASS NO- %d\t",x);
				for(xx=0;xx<i;xx++)
					printf("%s  ",a[xx]);
				printf("\n");
			}	

		}
		printf("\n\tLIST AFTER SORTING\n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		printf("CONTINUE (1/0) ");
		scanf("%d",&yy);
		if(yy==0)
			break;
	}
}


void selection(char a[][20],int i)                                 //SELECTION SORT
{
	int x,y,z,xx,yy,zz;
	char q[20];
	while(1)
	{
		printf("\n\tTYPE OF ARRANGING\n ");
		printf("\n1.ASCENDING ");
		printf("\n2.DESCENDING ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&x);
		printf("\n\tLIST BEFORE SORTING\n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		if(x==1)
		{
			for(x=0;x<i-1;x++)
			{
				zz=x;
				for(y=x+1;y<i;y++)
				{
					if(strcmp(a[zz],a[y])>0)
					{
						zz=y;
					}
				}
				if(zz!=x)
				{
					strcpy(q,a[x]);
					strcpy(a[x],a[zz]);
					strcpy(a[zz],q);
				}
				printf("\nPASS NO- %d\t",x+1);
				for(xx=0;xx<i;xx++)
					printf("%s  ",a[xx]);
				printf("\n");
			}
		}
		else
		{	
			for(x=0;x<i-1;x++)
			{
				zz=x;
				for(y=x+1;y<i;y++)
				{
					if(strcmp(a[zz],a[y])<0)
					{
						zz=y;
					}
				}
				if(zz!=x)
				{
					strcpy(q,a[x]);
					strcpy(a[x],a[zz]);
					strcpy(a[zz],q);
				}
				printf("\nPASS NO- %d\t",x+1);
				for(xx=0;xx<i;xx++)
					printf("%s  ",a[xx]);
				printf("\n");
				}
		}
		printf("\n\tLIST AFTER SORTING\n");
		printf("************************************\n");
		for(xx=0;xx<i;xx++)
			printf("%s\n",a[xx]);
		printf("************************************\n");	
		printf("\nCONTINUE (1/0) ");
		scanf("%d",&yy);
		if(yy==0)
			break;
	}
}	


void binary(char a[][20],int i)                            //BINARY SEARCH
{
	int x;
	bubble(a,i);
	char v[20];
	while(1)
	{
		printf("\n\n\tENTER THE NAME TO BE SEARCHED ");
		scanf("%s",v);
		int l=0,u=(i-1),m=(l+u)/2,d=0;
	
		while(1)
		{
			if(strcmp(a[m],v)==0)
			{	
				d++;
				printf("************************************\n");
				printf("\n\tREQUIRED NAME - %s",a[m]);
				printf("\n\n\tPOSITION - %d",m+1);
				printf("\n\n\tNUMBER OF SEARCH - %d\n",d);
				printf("************************************\n");
				break;
			}	
			else
			{	
				if(strcmp(a[m],v)<0)
				{	
					d++;
					l=m+1;
					m=(l+u)/2;
				}
				else
				{	
					d++;
					u=m-1;
					m=(l+u)/2;
				}
			}
			if(u<l)
			{	
				d++;
				printf("\n\tNUMBER OF SEARCH - %d",d);
				printf("\n\tDATA NOT FOUND");
				break;
			}
		}
		printf("\n\tCONTINUE BINARY SEARCHING (1/0)  ");
		scanf("%d",&x);
		if(x==0)
			break;
	}	
}


int bsrecursion(char a[][20],char b[],int l,int u)      //binary search with recursion
{
	int m;
	if(l>u)
	{
		return -1;
	}	
	m=(l+u)/2;
	if(strcmp(a[m],b)==0)
	{
		return m;
	}
	if(strcmp(a[m],b)>0)
	{
		bsrecursion(a,b,l,m-1);
	}
	else
	{
		bsrecursion(a,b,m+1,u);
	}
}


void main()
{
	int i,j,k,l=0,f=0,t;
	printf("ENTER THE NUMBER OF WORDS ");
	scanf("%d",&i);
	int u=(i-1);
	char a[i][20],b[20],o[20];
	printf("\nENTER  WORDS  ");
	for(j=0;j<i;j++)
	scanf("%s",a[j]);
	while(1)
	{
		printf("\n\tTYPES OF SORTING\n ");
		printf("************************************");
		printf("\n1.BUBBLE SORT ");
		printf("\n2.SELECTION SORT ");
		printf("\n3.INSERTION SORT ");
		printf("\n4.BINARY SEARCH ");
		printf("\n5.BINARY SEARCH WITH RECURSION\n ");
		printf("************************************\n");
		printf("\n\tENTER YOUR CHOICE ");
		scanf("%d",&k);
		switch(k)
		{
			case 1:bubble(a,i);
			break;
			case 2:selection(a,i);
			break;
			case 3:insertion(a,i);
			break;
			case 4: binary(a,i);
			break;
			case 5:{
					printf("\nENTER NAME TO BE SEARCHED ");
					scanf("%s",o);
					bubble(a,i);	
					t=bsrecursion(a,o,l,u);
					if(t==(-1))
					{
						printf("\n\tDATA NOT FOUND");
					}
					else 
					{
						printf("***********************************\n");
						printf("\nNAME -%s",a[t]);
						printf("\nPOSITION - %d",t+1);
						printf("***********************************\n");
					}
													
				}
			break;
			default:printf("\n\tINVALID OPTION ");
			break;
		}
		printf("\n\n\tCONTINUE (1/0) ");
		scanf("%d",&f);
		if(f==0)
		break;
	}
	printf("\n\n\t\t\tTHANK-YOU!!!");
}
