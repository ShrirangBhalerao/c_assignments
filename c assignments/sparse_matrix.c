#include<stdio.h>

struct sparse
{
int row,column,value;
};

void getdata(int a[][3])
{
	int j,k;
	printf("Enter the matrix ");
	for(j=0;j<3;j++)
	{
		for(k=0;k<3;k++)
		{
			scanf("%d",&a[j][k]);
		}
	}
}

int matrix(int a[][3],struct sparse r[])
{
	int i,j,k=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]!=0)
			{
				r[k].row=i;
				r[k].column=j;
				r[k].value=a[i][j];
				k++;
			}
		}
	}
	return k;
}

void display(struct sparse r[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("\t%d\t%d\t%d",r[i].row,r[i].column,r[i].value);
		printf("\n");
	}
	printf("\n");
}

int add(struct sparse r[],struct sparse s[],struct sparse t[],int x,int y)
{
	int a=1,b=1,c=1;
	while(1)
	{
		if(r[a].row==s[b].row)
		{
			if(r[a].column==s[b].column)
			{
				t[c].row=r[a].row;
				t[c].column=r[a].column;
				t[c].value = r[a].value + s[b].value;
				c++,a++,b++;
				if(a==x&&b==y)
					break;
			}
			if(r[a].column<s[b].column)
			{
				t[c].row=r[a].row;
				t[c].column=r[a].column;
				t[c].value = r[a].value;
				c++,a++;
				if(a==x&&b==y)
					break;	
			}
			if(r[a].column>s[b].column)
			{
				t[c].row=s[b].row;
				t[c].column=s[b].column;
				t[c].value = s[b].value;
				c++,b++;
				if(a==x&&b==y)
					break;		
			}
		} 
		if(r[a].row<s[b].row)
		{
			t[c].row=r[a].row;
			t[c].column=r[a].column;
			t[c].value =r[a].value;
			c++,a++;
			if(a==x&&b==y)
					break;
		}
		if(r[a].row>s[b].row)
		{
			t[c].row=s[b].row;
			t[c].column=s[b].column;
			t[c].value = s[b].value;
			c++,b++;
			if(a==x&&b==y)
					break;
		}
		if(a==x)
		{
			for(;b<y;)
			{
				t[c].row=s[b].row;
				t[c].column=s[b].column;
				t[c].value = s[b].value;
				c++,b++;
			}
		
		}
		if(b==y)
		{	
			for(;a<x;)
			{
				t[c].row=r[a].row;
				t[c].column=r[a].column;
				t[c].value =r[a].value;
				c++,a++;
			}
		}
		break;				
	}
	return c;
}






int main()
{
	struct sparse r[20],s[20],t[20];
	int a[3][3],b[3][3],x,y,z;
	getdata(a);
	x=matrix(a,r);
	r[0].row=3;
	r[0].column=3;
	r[0].value=x-1;
	display(r,x);
	getdata(b);
	y=matrix(b,s);
	s[0].row=3;
	s[0].column=3;
	s[0].value=y-1;
	display(s,y);
	z=add(r,s,t,x,y);
	t[0].row=3;
	t[0].column=3;
	t[0].value=z-1;
	display(t,z);
}
















