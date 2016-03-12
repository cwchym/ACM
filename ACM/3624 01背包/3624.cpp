#include <stdio.h>
#include <string>

using namespace std;

#define N 3410
#define M 13000

int d[N];
int w[N];
int f[M];

int m_max(int a,int b)
{
	return (a>b)?a:b;
}

int m_min(int a,int b)
{
	return (a<b)?a:b;
}

void bag(int n,int V)
{
	memset(f,0,sizeof(f));

	for(int i=0;i<n;i++)
	{
		int sum=0;
		int bound=w[i];

		for(int k=V;k>=bound;k--)
			f[k]=max(f[k],f[k-w[i]]+d[i]);
	}
}

int main(int argc, char *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&w[i],&d[i]);
	}
	
	bag(n,m);

	printf("%d\n",f[m]);

	return 0;
}
