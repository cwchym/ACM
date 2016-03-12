#include <stdio.h>
#include <string>

using namespace std;

#define MAX 8

char chess[MAX][MAX];
bool col[MAX];

int DFS(int s,int n,int k)
{
	if(k==0)
	{
		return 1;
	}

	int sum=0;
	for(int i=s;i<=n-k+1;i++)
		for(int j=1;j<=n;j++)
		{
			if(chess[i-1][j-1]=='#'&&!col[j-1])
			{
				//printf("xxx%d %d\n",i,j);
				col[j-1]=true;
				sum+=DFS(i+1,n,k-1);
				col[j-1]=false;
			}
		}

	//printf("sum : %d\n",sum);
	return sum;

}

int main(int argc, char *argv[])
{
	int n,k;
	while(scanf("%d %d",&n,&k)==2)
	{
		memset(col,false,sizeof(col));

		if(n==-1&&k==-1)
			break;

		getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				scanf("%c",&chess[i][j]);
			getchar();
		}

		//for(int i=0;i<n;i++)
		//	for(int j=0;j<n;j++)
		//	printf("%c",chess[i][j]);

		printf("%d\n",DFS(1,n,k));
	}
	
	return 0;
}
