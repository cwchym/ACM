#include <cstdio>
#include <cstring>

using namespace std;

#define Nmax 101
#define Mmax 101

bool vis[Nmax][Mmax];
char field[Nmax][Mmax];

int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void DFS(int r,int c,int n,int m)
{
	if(vis[r][c])
		return;

	vis[r][c]=true;
	for(int i=0;i<8;i++)
	{
		int tmp_r=r+dir[i][0];
		int tmp_c=c+dir[i][1];

		if(tmp_r>0&&tmp_r<=n&&tmp_c>0&&tmp_c<=m
			&&!vis[tmp_r][tmp_c]&&field[tmp_r][tmp_c]=='W')
			DFS(tmp_r,tmp_c,n,m);
	}
}

int main(int argc, char *argv[])
{
	memset(vis,false,sizeof(vis));

	int n,m;
	scanf("%d %d",&n,&m);
	getchar();

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%c",&field[i][j]);
		getchar();
	}


	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!vis[i][j]&&field[i][j]=='W')
			{
				DFS(i,j,n,m);
				//printf("printf : %d %d\n",i,j);
				sum++;
			}
		}

	printf("%d\n",sum);
	
	return 0;
}
