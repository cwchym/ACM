#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define NMAX 20010

int parent[NMAX];
int rank[NMAX];
bool vis[NMAX];
vector<int> edge[NMAX];
vector<pair<int,int> > query;
map<int,int> ans;

int Find(int x)
{
	while(x!=parent[x])x=parent[x];
	return x;
}

void Tarjan(int u)
{
	vis[u]=true;
	int i=0;
	for(vector<pair<int,int> >::iterator v_itr=query.begin();
	    v_itr!=query.end();v_itr++,i++)
		{
			//printf("query first %d, second %d,u: %d\n",v_itr->first,v_itr->second,u);
			if(v_itr->first==u)
			{
				if(vis[v_itr->second])
				{
					//printf("ans : %d\n",Find(v_itr->second));
					ans.insert(make_pair<int,int>(i,Find(v_itr->second)));
				}
			}

			if(v_itr->second==u)
			{
				if(vis[v_itr->first])
				{
					//printf("ans : %d\n",Find(v_itr->first));
					ans.insert(make_pair<int,int>(i,Find(v_itr->first)));
				}
			}
		}

	for(vector<int>::iterator v_itr2=edge[u].begin();
	    v_itr2!=edge[u].end();v_itr2++)
		{
			if(!vis[*v_itr2])
			{
				Tarjan(*v_itr2);
				parent[*v_itr2]=u;
			}
		}
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		memset(rank,0,sizeof(rank));
		memset(vis,false,sizeof(vis));

		int n;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);

			parent[i]=i;
			edge[a].push_back(b);
			rank[b]++;
		}
		parent[n]=n;

		int c,d;
		scanf("%d %d",&c,&d);

		query.push_back(make_pair(c,d));
		//printf("query: %d %d\n",query[0].first,query[0].second);


		for(int i=1;i<=n;i++)
		{
			if(rank[i]==0)
			{
				//printf("root : %d\n",i);
				Tarjan(i);
			}
		}

		printf("%d\n",ans[k]);
	}
	
	return 0;
}
