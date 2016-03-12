#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 20

char c[MAX][MAX];
bool Traveled[MAX][MAX];

int bfs(int x,int y,int m_count,int n,int m)
{
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));

	while(!q.empty())
	{
		pair<int,int> tmp=q.front();
		q.pop();

		if(tmp.first-1>=0&&c[tmp.first-1][tmp.second]=='.'&&!Traveled[tmp.first-1][tmp.second])
		{
			m_count++;
			Traveled[tmp.first-1][tmp.second]=true;
			q.push(make_pair(tmp.first-1,tmp.second));
		}
		if(tmp.second-1>=0&&c[tmp.first][tmp.second-1]=='.'&&!Traveled[tmp.first][tmp.second-1])
		{
			m_count++;
			Traveled[tmp.first][tmp.second-1]=true;
			q.push(make_pair(tmp.first,tmp.second-1));
		}
		if(tmp.first+1<n&&c[tmp.first+1][tmp.second]=='.'&&!Traveled[tmp.first+1][tmp.second])
		{
			m_count++;
			Traveled[tmp.first+1][tmp.second]=true;
			q.push(make_pair(tmp.first+1,tmp.second));
		}
		if(tmp.second+1<m&&c[tmp.first][tmp.second+1]=='.'&&!Traveled[tmp.first][tmp.second+1])
		{
			m_count++;
			Traveled[tmp.first][tmp.second+1]=true;
			q.push(make_pair(tmp.first,tmp.second+1));
		}
	}

	return m_count;
}

int main(int argc, char *argv[])
{
	int x,y,W,H;
	while(scanf("%d %d",&W,&H)==2)
	{
		if(W+H==0)
			break;

		getchar();
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				scanf("%c",&c[i][j]);
				Traveled[i][j]=false;
				if(c[i][j]=='@')
				{x=i;y=j;}
			}
			getchar();
		}

		int ans=bfs(x,y,1,H,W);

		printf("%d\n",ans);
	}
	
	return 0;
}
