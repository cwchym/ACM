#include <stdio.h>

#define inf 0xffffffe

const int max=100;

int map[max][max];
int dis[max][max];

void Floyd(int m[][max],int d[][max],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=m[i][j];

	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=(d[i][j]<(d[i][k]+d[k][j]))
				?d[i][j]:(d[i][k]+d[k][j]);
}


int main(int argc, char *argv[])
{
	while(1)
	{
		int n;
		scanf("%d",&n);

		if(n==0)
			break;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i!=j)
					map[i][j]=inf;
				else
					map[i][j]=0;
			}

		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			for(int j=0;j<a;j++)
			{
				int b,c;
				scanf("%d %d",&b,&c);
				map[i][b-1]=c;
			}
		}

		Floyd(map,dis,n);

		int tmp_min=inf;
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			int tmp_max=0;
			for(int j=0;j<n;j++)
			{
				if(dis[i][j]>tmp_max)
					tmp_max=dis[i][j];
			}
			if(tmp_max<tmp_min)
			{	
				tmp_min=tmp_max;
				ans=i;
			}
		}

		if(ans==-1)
			printf("disjoint\n");
		else
			printf("%d %d\n",ans+1,tmp_min);
	}
	return 0;
}
