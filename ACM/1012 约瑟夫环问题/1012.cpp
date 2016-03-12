#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	long m[15];
	memset(m,-1,sizeof(m));
	int a;
	while(scanf("%d",&a)==1)
	{
		if(a==0)
			break;

		if(m[a]!=-1)
		{
			printf("%d\n",m[a]);
			continue;
		}

		int ans=a+1;
		int l=0;
		for(int i=1;i<=a;i++)
		{
			l=(l+ans-1)%(2*a-i+1);
			if(l<a)
			{
				i=0;
				if(ans%(a+1)==0)
					ans+=1;
				else if(ans%(a+1)==1)
					ans=ans-1+a+1;

				l=0;
			}
		}

		m[a]=ans;
		printf("%d\n",m[a]);
	}
	
	return 0;
}
