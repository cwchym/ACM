#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

#define MAX 105

int edge[MAX][MAX];
bool visit[MAX];
int pre[MAX];

bool bfs(int n)
{
	memset(visit,false,sizeof(visit));
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	q.push(0);
	pre[0]=0;
	visit[0]=true;

	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();

		for(int i=1;i<=n;i++)
		{
			if(edge[tmp][i]>0&&!visit[i])
			{
				pre[i]=tmp;
				q.push(i);
				visit[i]=true;

				if(i==n)
				{
					return true;
				}
			}
		}
	}

	return false;
}

int EK(int n)
{
	int sum=0;

	while(bfs(n))
	{
		int tmp_min=0x7fffffff;

		for(int i=n;i!=0;i=pre[i])
		{
			if(edge[pre[i]][i]<tmp_min)
				tmp_min=edge[pre[i]][i];
		}

		for(int i=n;i!=0;i=pre[i])
		{
			edge[pre[i]][i]-=tmp_min;
			edge[i][pre[i]]+=tmp_min;
		}

		sum+=tmp_min;
	}

	return sum;
}

int main(int argc, char *argv[])
{
	int n,np,nc,m;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)==4)
	{
		memset(edge,0,sizeof(edge));

		for(int i=0;i<m;i++)
		{
			int x,y,z;
			while(getchar()!='(');
			scanf("%d,%d)%d",&x,&y,&z);

			//printf("\n (%d, %d)%d",x,y,z);

			if(x==y)
				continue;

			edge[x+1][y+1]+=z;
		}

		for(int i=0;i<np;i++)
		{
			int x,y;
			while(getchar()!='(');
			scanf("%d)%d",&x,&y);

			//printf("\n (%d)%d",x,y);

			edge[0][x+1]+=y;
		}

		for(int i=0;i<nc;i++)
		{
			int x,y;
			while(getchar()!='(');
			scanf("%d)%d",&x,&y);
			
			//printf("\n (%d)%d\n",x,y);

			edge[x+1][n+1]+=y;
		}

		/*for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=n+1;j++)
			printf("%d ",edge[i][j]);
			printf("\n");
		}*/

		printf("%d\n",EK(n+1));

	}
	
	return 0;
}
