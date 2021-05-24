#include<stdio.h>


void accept(int j,int a[][j],int i)        //acceptance of elements of matrix
{
	int k,l;

	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			scanf("%d",&a[k][l]);
		}
	}	
}


void add(int j,int n,int a[][j],int b[][n],int i,int m)
{
        if(m!=i||n!=j)
	{
		printf("\t\nINVALID SIZE ,ADDITION NOT POSSIBLE\n ");      
	}  
	else
	{
	int c[i][j], p,q;
	for(p=0;p<i;p++)
	{
		for(q=0;q<j;q++)
		{
			c[p][q]=a[p][q]+b[p][q];
		}
	}
	printf("\nADDITION OF 2 MATRIX\n\n");
	display(j,c,i);
	}
}

void mul(int j, int n,int a[][j], int  b[][j],int i,int m)
{
	int c[i][j],p,q,r;
   	if(m!=j)
	{
		printf("\t\nINVALID SIZE ,MULTIPLICATION NOT POSSIBLE\n");      
	}
	else
	{
	for(p=0;p<i;p++)
	{
		for(q=0;q<j;q++)
		{
			c[p][q]=0;
			for(r=0;r<i;r++)
			{
				c[p][q]=c[p][q]+(a[p][r]*b[r][q]);
			}
		}
	}
	printf("\n\tMULTIPLICATION OF 2 MATRIX\n");
	
	display(j,c,i);
}
}


void transpose(int j,int a[][j],int i)
{
	if(i!=j)
	{
		printf("\n\n\tTRANSPOSE NOT POSSIBLE ");
		
	}
	else
	{
		int b[i][j],x,y;
		for(x=0;x<i;x++)
		{
			for(y=0;y<j;y++)
			{
				b[x][y]=a[y][x];
			}
		}
		display(y,b,i);
	}
}


void saddlept(int j,int a[][j],int i )
{
	int p,q,r,s,k,t;
	for(p=0;p<i;p++)
	{
		r=a[p][0];
		for(q=0;q<j;q++)
		{
			if(r>=a[p][q])
			{
				r=a[p][q];
				s=q;
			}
		}
		t=a[0][s];
		for(k=0;k<i;k++)
		{
			if(t<=a[k][s])
			{	
				t=a[k][s];
			}
		}
		if(r==t)
		{
			printf("\n\tSADDLE POINT OF MATRIX  IS %d ",t);
			printf("\n\tPOSITION OF MATRIX IS a[%d][%d]",p,q);
			break;
			printf("\n");
		}	
	}
	if(r!=t)	
	{
		printf("\tSADDLE POINT ABSENT ");
	}
}


void display(int j,int a[][j],int i)
{
	int e,f;
	for(e=0;e<i;e++)
	{
		for(f=0;f<j;f++)
		{
			printf("%d\t",a[e][f]);
		}
		printf("\n");
	}
}


void main()
{
	int i,j,k,l,ch,h,m,n;
	printf("\n\tENTER THE DIMENSIONS OF MATRIX 1 - ");
	scanf("%d%d",&i,&j);
	int a[i][j];
	printf("\n\n\tENTER THE DIMENSIONS OF MATRIX 2 - ");
	scanf("%d%d",&m,&n);
	int b[m][n];
	printf("\n\n\tENTER THE ELEMENTS OF MATRIX 1 - ");
	accept(j,a,i);
	printf("\n\n\tENTER THE ELEMENTS OF MATRIX 2 - ");
	accept(n,b,m);
	do
	{
		printf("\nMATRICES 1 -: \n\n");
		display(j,a,i);
		printf("\n");
		printf("\nMATRICES 2 -: \n\n");
		display(n,b,m);
		printf("\n");
		printf("\nLIST OF OPERATIONS");
		printf("\n");
		printf("\n1.ADDITION");
		printf("\n2.MULTIPLICATION");
		printf("\n3.TRANSPOSE");
		printf("\n4.SADDLE POINT");
		printf("\n\n\tENTER YOUR CHOICE ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: add(j,n,a,b,i,m);
			break;
			case 2: mul(j,n, a, b,i,m);
			break;
			case 3:{
					printf("\nTRANSPOSE OF MATRIX 1 ");
					printf("\n");
				 	transpose(j,a,i);
					printf("\tTRANSPOSE OF MATRIX 2 ");
					printf("\n");
 					transpose(n,b,m);
				}
			break;
			case 4: {
					
					saddlept(j,a,i);
					
					saddlept(n,b,m);
				}
					
			break;
			default: printf("\n\tINVALID OPTION");
			break;
		}
	printf("\nWOULD YOU LIKE TO PERFORM ANY OTHER OPERATION ");
	scanf("%d",&h);
	printf("\n");
	}while(h==1);
	printf("\t\t\tTHANK-YOU");
	printf("\n");		
}


