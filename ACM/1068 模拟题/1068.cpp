#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);

	int Ps[21];

	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);

		for(int j=0;j<p;j++)
		{
			scanf("%d",&Ps[j]);
		}

		for(int j=p;j>0;j--)
			Ps[j]-=Ps[j-1];

		for(int j=0;j<p;j++)
		{
			for(int k=j;k>=0;k--)
			{
				if(Ps[k]>0)
				{
					Ps[k]--;
					printf("%d ",j-k+1);
					break;
				}
			}
		}
		printf("\n");

	}
	
	return 0;
}
