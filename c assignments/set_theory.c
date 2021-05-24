#include<stdio.h>

void accept(int a[],int b)       //acceptance of elements of set
{
	int i,j;
	printf("\n\tENTER THE ELEMENTS OF SET  ");
	printf("\n\tPRESS ENTER KEY AFTER EACH ENTRY  ");
	scanf("%d",&a[0]);
	for(i=1;i<b;i++)
	{
		scanf("%d",&a[i]);
		for(j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
				printf("\tENTER ANOTHER NUMBER");
				i--;
				break;
			}
		
		}
	}
}


int  unon(int a[],int b[],int i,int j,int c[])             //union of sets
{
	int w,k=0,m,n,flag,d;
	for(w=0;w<i; w++)
	{
		c[k]=a[w];
		k++;
	}
	for(n=0;n<j;n++)
	{
		flag=0;
		for(m=0;m<i;m++)
		{
			if(a[m]==b[n])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			c[k]=b[n];
			k++;
			
		}
	}
	printf("{");
	for(d=0;d<k;d++)
	{
		printf("\t%d",c[d]);
	}
	printf("	}");
	printf("\n");
	printf("\n\tNUMBER OF ELEMENTS= %d",k);
	printf("\n");
	return k;
}


int intersection(int a[],int b[],int x,int y,int c[])     //intersection of sets
{
	int i,j,m=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(a[i]==b[j])
			{
				c[m]=b[j];
				m++;
				break;
			}
		}
	}
	printf("\n\tINTERSECTION OF TWO SETS ");
	printf("{");
	for(i=0;i<m;i++)
	{
		printf("\t%d",c[i]);
	}
	printf("	}");
	printf("\n");
	printf("\n\tNUMBER OF ELEMENTS= %d",m);
	printf("\n");
	return m;
}
int difference(int a[],int b[],int t,int z,int c[])        //difference  between two arrays sets
{           
	int i,j,y,x=0;
	for(i=0;i<t;i++)
	{
		y=0;
		for(j=0;j<z;j++)
		{
			if(a[i]==b[j])
			{
				y=1;
				break;
			}
		}
		if(y==0)
		{
			c[x]=a[i];
			x++;
		}
	}
	printf("\n\tDIFFERENCE OF TWO SETS  ");
	printf("{");
	for(j=0;j<x;j++)
	{
		printf("\t%d ",c[j]);
	}
	printf("	}");
	printf("\n");
	printf("\n\tNUMBER OF ELEMENTS = %d",x);
	printf("\n");
	return x;
}


void main()
{
	int i,j,k,ch,p,q,r,s,a,x;
	int n;
	printf("\n\tENTER THE SIZE OF SET  ");
	scanf("%d",&i);
	if(i<=0)
	{
 		printf("\n\tINVALID SIZE,ENTER AGAIN  ");
		scanf("%d",&i);
	}
	int array1[i],array3[20],array4[20],array5[10],array6[10],array7[10];
	accept(array1,i);
	printf("\n\tENTER THE SIZE OF SET  ");
	scanf("%d",&j);
	if(j<=0)
	{
		printf("\n\tINVALID SIZE,ENTER AGAIN  ");
		scanf("%d",&j);
	}
	int array2[j];
	accept(array2,j);
	do
	{
		printf("\n\n\tTHE SET A IS- ");
		printf("{");
		for(x=0;x<i;x++)
		{
			printf("\t%d" ,array1[x]);
		}
		printf("	}");
		printf("\n");
		printf("\n\n\tTHE SET B IS- ");
		printf("{");
		for(x=0;x<j;x++)
		{
			printf("\t%d" ,array2[x]);
		}
		printf("	}");
		printf("\n");
		printf("\n\tLIST OF OPERATIONS");
		printf("\n\t1.UNION ");
		printf("\n\t2.INTERSECTION ");
		printf("\n\t3.A-B ");
		printf("\n\t4.B-A ");
		printf("\n\t5.SYMMETRIC DIFFERENCE ");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:r=unon(array1,array2,i,j,array3);
			break;
			case 2:s=intersection(array1,array2,i,j,array4);
			break;
			case 3:p=difference(array1,array2,i,j,array5);
			break;
			case 4:q=difference(array2,array1,j,i,array6);
			break;
			case 5:unon(array5,array6,p,q,array7);
			break;
			default:printf("\nINVALID OPTION\n");
			break;
		}
		printf("\nWOULD YOU LIKE TO PERFORM ANY OTHER OPERATIONS (1/0) ");
		scanf("%d",&n);
		printf("\n");
	}while(n==1);
	printf("\t\t\tTHANK-YOU!!");
	printf("\n");
	
}

