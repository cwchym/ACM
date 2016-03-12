#include <stdio.h>

int list[16];

int main(int argc, char *argv[])
{
	while(scanf("%d",&list[0])==1)
	{
		if(list[0]==-1)
			break;

		int i;
		for(i=1;list[i-1]!=0;i++)
			scanf("%d",&list[i]);

		int sum=0;
		for(int j=0;j<i-1;j++)
			for(int k=j;k<i-1;k++)
			{
				if(list[j]==2*list[k]||list[k]==2*list[j])
					sum++;
			}

		printf("%d\n",sum);
	}

	return 0;
}
