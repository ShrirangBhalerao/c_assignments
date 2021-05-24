#include<stdio.h>



void get_array(int a[],int i)
{
	printf("\n\nEnter the elements of array  ");
	int j;
	for(j=0;j<i;j++)
	{
		scanf("%d",&a[j]);
	}
}

void print_array(int a[],int i)
{
	int j;
	printf("\n\nelements of array  ");
	for(j=0;j<i;j++)
	{
		printf("%d\t",a[j]);
	}	
}

int quick(int a[],int i)
{
	int j=1,k=i-1,s=0,n,m,h;
	int p=a[0];
	while(1)
	{
		while(p>a[j])
		{
			j++;
		}
		while(p<a[k])
		{
			k--;
		}
		n=a[j];
		a[j]=a[k];
		a[k]=n;
		print_array(a,i);
		j++;
		k--;
		if(j>=k)
		{
			n=a[j];
			a[j]=a[k];
			a[k]=n;
			printf("\n\n%d\n\n",a[j]);
			print_array(a,i);
			break;
		}	
	}
	
	m=a[j];
	a[j]=a[0];
	a[0]=m;
	print_array(a,i);
	return j;	
}




void main()
{
int i,j,k,h,o;
printf("Enter the size of array  ");
scanf("%d",&i);
int a[i];
get_array(a,i);
print_array(a,i);
h=quick(a,i);




}















