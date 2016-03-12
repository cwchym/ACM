#include <stdio.h>



int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==-1)
			break;

		int m[11];
		int h[11];

		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&m[i],&h[i]);
		}

		int sum=m[0]*h[0];
		for(int i=1;i<n;i++)
			sum+=m[i]*(h[i]-h[i-1]);

		printf("%d miles\n",sum);
	}
	
	return 0;
}
