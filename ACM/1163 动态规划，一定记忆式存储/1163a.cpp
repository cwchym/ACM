#include <stdio.h>

int n;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main(int argc, char *argv[])
{
	scanf("%d",&n);

	int **v=new int *[n];
	int **b=new int *[n];
	for(int i=0;i<n;i++)
	{
		v[i]=new int[i+1];
		b[i]=new int[i+1];
		for(int j=0;j<=i;j++)
		{
			scanf("%d",&v[i][j]);
			if(i==n-1)
				b[i][j]=v[i][j];
			else
				b[i][j]=0;
		}
	}

	for(int i=n-2;i>=0;i--)
		for(int j=i;j>=0;j--)
			b[i][j]=v[i][j]+max(b[i+1][j],b[i+1][j+1]);

	printf("%d\n",b[0][0]);
	
	return 0;
}
