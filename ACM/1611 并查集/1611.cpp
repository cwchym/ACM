#include <stdio.h>
#include <string.h>

#define MAX 30010

int P[MAX];
int num[MAX];

int find(int x)
{
	int tmp=x;
	while(P[tmp]!=tmp)
		tmp=P[tmp];

	P[x]=tmp;

	return tmp;
}

void Union(int x,int y)
{
	int tmp1=find(x);
	int tmp2=find(y);

	if(tmp1!=tmp2&&num[tmp1]>num[tmp2])
	{
		P[tmp2]=tmp1;
		num[tmp1]+=num[tmp2];
	}
	else if(tmp1!=tmp2)
	{
		P[tmp1]=tmp2;
		num[tmp2]+=num[tmp1];
	}
}

int main(int argc, char *argv[])
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0)
			break;

		for(int i=0;i<n;i++)
		{
			P[i]=i;
			num[i]=1;
		}

		//printf("num : %d\n",num[0]);

		for(int i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);

			int member1,member2;
			scanf("%d",&member1);
			for(int j=1;j<k;j++)
			{
				scanf("%d",&member2);

				Union(member1,member2);
			}
		}

		printf("%d\n",num[P[find(0)]]);
	}
	
	return 0;
}
