#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n1,n;
	while(scanf("%d",&n1)!=EOF)
	{
		for(int k=0;k<n1;k++)
		{
			scanf("%d",&n);
			int a[110];
			memset(a,0,sizeof(a));

			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(j%i==0)a[j]=!a[j];
	
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i])ans++;
	
			printf("%d\n",ans);
		}
	}
	return 0;
}
