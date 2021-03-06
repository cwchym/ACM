#include <cstdio>
#include <string>

using namespace std;

#define MAX 500
#define inf 65536

int dis[MAX][MAX]={0};
bool vis[MAX];
int maxDis[MAX];

int Prim(int n)
{
	memset(vis,false,sizeof(vis));

	int sum=0;
	int d;
	int node;

	for(int i=0;i<n;i++)
		maxDis[i]=dis[0][i];
	vis[0]=true;

	for(int i=1;i<n;i++)
	{
		d=inf;

		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&d>maxDis[j])
			{
				d=maxDis[j];
				node=j;
			}
		}

		if(sum<d)
			sum=d;
		vis[node]=true;

		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&dis[node][j]<maxDis[j])
				maxDis[j]=dis[node][j];
		}
	}

	return sum;
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d",&dis[i][j]);
			}

		int ans=Prim(n);

		printf("%d\n",ans);
	}
	
	return 0;
}
