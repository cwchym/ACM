#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 310


int dir[][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
int vis[MAX][MAX];

int BiBFS(int n,int a,int b,int c,int d)
{
	vis[a][b]=1;
	vis[c][d]=2;

	queue<pair<int,int> > forward;
	queue<pair<int,int> > backward;

	int forward_size=1;
	int backward_size=1;

	int forward_step=0;
	int backward_step=0;

	forward.push(make_pair(a,b));
	backward.push(make_pair(c,d));

	if(vis[a][b]==vis[c][d])
		return forward_step+backward_step;

	while(!forward.empty()||!backward.empty())
	{
		int tmp_size=0;
		while(forward_size--&&!forward.empty())
		{
			pair<int,int> tmp=forward.front();
			forward.pop();

			for(int i=0;i<8;i++)
			{
				int e=tmp.first+dir[i][0];
				int f=tmp.second+dir[i][1];

				if(vis[e][f]==2)
					return forward_step+backward_step+1;
				
				if(vis[e][f]==0&&e>=0&&e<n&&f>=0&&f<n)
				{
					vis[e][f]=1;
					forward.push(make_pair<int,int>(e,f));
					tmp_size++;
				}
			}
		}
		forward_size=tmp_size;
		forward_step++;

		tmp_size=0;
		while(backward_size--&&!backward.empty())
		{
			pair<int,int> tmp=backward.front();
			backward.pop();

			for(int i=0;i<8;i++)
			{
				int e=tmp.first+dir[i][0];
				int f=tmp.second+dir[i][1];

				if(vis[e][f]==1)
					return forward_step+backward_step+1;

				if(vis[e][f]==0&&e>=0&&e<n&&f>=0&&f<n)
				{
					vis[e][f]=2;
					backward.push(make_pair<int,int>(e,f));
					tmp_size++;
				}
			}
		}
		backward_size=tmp_size;
		backward_step++;
	}

	return forward_step+backward_step;
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
				vis[i][j]=0;

		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);

		int ans=BiBFS(n,a,b,c,d);

		printf("%d\n",ans);
	}
	
	return 0;
}
