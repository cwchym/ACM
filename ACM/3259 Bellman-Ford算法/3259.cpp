#include <stdio.h>

#define NMAX 1010
#define EMAX 6010

#define inf 10001

struct edge
{
	int u,v;
	int length;
};

edge e[EMAX];

bool Bellman_Ford(int n_num,int e_num)
{
	int d[NMAX];

	for(int i=1;i<=n_num;i++)
		d[i]=(i==1)?0:inf;
	for(int i=0;i<n_num-1;i++)
	{
		bool f=false;
		for(int j=0;j<e_num;j++)
		{
			if(d[e[j].v]>d[e[j].u]+e[j].length)
			{
				d[e[j].v]=d[e[j].u]+e[j].length;
				f=true;
			}
		}

		if(f)
			break;
	}

	for(int i=0;i<e_num;i++)
		if(d[e[i].v]>d[e[i].u]+e[i].length)
			return true;

	return false;
}

int main(int argc, char *argv[])
{
	int f;
	scanf("%d",&f);
	while(f--)
	{
		int N,M,W;

		scanf("%d %d %d",&N,&M,&W);

		int all_e=0;
		for(int i=0;i<M;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);

			e[all_e].u=e[all_e+1].v=u;  
            e[all_e].v=e[all_e+1].u=v;  
            e[all_e++].length=w;  
            e[all_e++].length=w; 
		}

		for(int i=0;i<W;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);

			e[all_e].u=u;  
            e[all_e].v=v;  
            e[all_e++].length=-w;
		}

		if(Bellman_Ford(N,all_e))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
