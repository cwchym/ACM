#include <cstdio>
#include <cstring>

using namespace std;

#define Nmax 1010
#define inf 0x7fffffff

int min_d[Nmax][Nmax];
int dis[Nmax];
bool vis[Nmax];

void Dijkstra(int n)
{
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n;i++)
		dis[i]=inf;

	dis[n]=0;
	vis[n]=true;
	
	int m=inf,node=n;

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n;j++)
			if(!vis[j]&&min_d[node][j]!=inf&&dis[j]>dis[node]+min_d[node][j])
				dis[j]=dis[node]+min_d[node][j];

		m=inf;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&dis[j]<m)
			{
				m=dis[j];
				node=j;
			}
		}

		vis[node]=true;
	}
}

int m_min(int a,int b)
{
	return (a>b)?b:a;
}

void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				min_d[i][j]=m_min(min_d[i][j],min_d[i][k]+min_d[k][j]);
			}
}

int main(int argc, char *argv[])
{
	int t,n;
	
	scanf("%d %d",&t,&n);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			min_d[i][j]=inf;

	while(t--)
	{
		int a,b,c;

		scanf("%d %d %d",&a,&b,&c);

		min_d[a][b]=m_min(min_d[a][b],c);
		min_d[b][a]=m_min(min_d[b][a],c);
	}

	//floyd(n);
	Dijkstra(n);

	printf("%d\n",dis[1]);
		
	return 0;
}
