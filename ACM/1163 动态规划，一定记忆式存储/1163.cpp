#include <stdio.h>
#include <math.h>

int n;

int simple_dp(int **a,int **b,int s1,int s2)
{
	if(s1==n-1||b[s1][s2]!=-1)
		return b[s1][s2];

	int tmp1=simple_dp(a,b,s1+1,s2);
	int tmp2=simple_dp(a,b,s1+1,s2+1);

	int tmp=(tmp1>tmp2)?tmp1:tmp2;

	b[s1][s2] = a[s1][s2]+tmp;
	return b[s1][s2];
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
				b[i][j]=-1;
		}
	}

	int ans=simple_dp(v,b,0,0);

	printf("%d\n",ans);
	
	return 0;
}
