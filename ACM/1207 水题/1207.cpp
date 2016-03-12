#include <stdio.h>

int fun(int n)
{
	int sum=1;
	while(n!=1)
	{
		if(n%2!=0)
			n=3*n+1;
		else
			n=(n>>1);
		sum++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int a,b;

	while(scanf("%d %d",&a,&b)==2)
	{
		int n=(a>b)?(a-b):(b-a);
		int small=(a>b)?b:a;

		int max=0;
		for(int i=0;i<=n;i++)
		{
			int ans=fun(i+small);
			if(max<ans)
				max=ans;
		}
		printf("%d %d %d\n",a,b,max);
	}
	
	return 0;
}
