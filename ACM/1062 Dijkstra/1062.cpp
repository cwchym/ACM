#include <stdio.h>
#include <string>

using namespace std;

#define Nmax 101
#define inf 0x7ffffff

int e[Nmax][Nmax];
bool visit[Nmax];
int path[Nmax];
int level[Nmax];

int dijkstra(int n,int m)
{
	memset(visit,false,sizeof(visit));

	int dis;
	int node;

	for(int i=1;i<=n;i++)
		path[i]=e[0][i];

	for(int i=1;i<=n;i++)
	{
		dis=inf;
		for(int j=1;j<=n;j++)
		{
			if(!visit[j]&&
				level[j]-level[0]<=m&&level[j]>=level[0]&&
				dis>path[j])
			{
				dis=path[j];
				node=j;
				
			}
		}

		visit[node]=true;

		for(int j=1;j<=n;j++)
		{
			if(!visit[j]&&e[node][j]>0&&level[j]-level[0]<=m&&level[j]>=level[0]&&
				path[j]>path[node]+e[node][j])
			{
				path[j]=path[node]+e[node][j];
			}
		}
		
		//level[0]=level[node];
	}

	return path[1];

}

int main(int argc, char *argv[])
{
	int n,m;
	scanf("%d %d",&m,&n);

	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			e[i][j]=0;

	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d %d %d",&e[0][i],&level[i],&x);

		for(int j=0;j<x;j++)
		{
			int tmp1,tmp2;
			scanf("%d %d",&tmp1,&tmp2);

			e[tmp1][i]=tmp2;
		}
	}

	int sum=inf;
	
	for(int i=1;i<=n;i++)
	{
		level[0]=level[i];

		int tmp=dijkstra(n,m);

		if(sum>tmp)
			sum=tmp;
	}

	printf("%d\n",sum);

	return 0;
}
