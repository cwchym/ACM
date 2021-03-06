#include <stdio.h>
#include <string>

using namespace std;

#define MAX 50010

int point[MAX];
int path[MAX];//相对于父节点的关系值1表示吃父节点，2表示被父节点吃,0表示同类

int find(int p)
{
	int tmp=p;
	while(p!=point[p])
	{
		p=point[p];
		path[tmp]+=path[p];
	}
	point[tmp]=p;
	path[tmp]=path[tmp]%3;

	return p;
}

int Quick_Uion(int n,int x,int y)
{
	int tmp1=find(x);
	int tmp2=find(y);

	if(tmp1==tmp2)
	{
		//printf("fake : %d\n",tmp1);
		return (path[x]-path[y]+3)%3;
	}
	else
	{
		point[tmp1]=tmp2;
		path[tmp1]=(path[y]-path[x]+n+3)%3;
		return -1;
	}
}

int main(int argc, char *argv[])
{
	int n,k;
	scanf("%d %d",&n,&k);
		int fake=0;

		for(int i=0;i<=n;i++)
		{
			point[i]=i;
			path[i]=0;
		}

		for(int i=0;i<k;i++)
		{
			int t,x,y;
			scanf("%d %d %d",&t,&x,&y);

			if(x>n||y>n||((t==2)&&x==y))
				fake++;
			else
			{
				int flag=Quick_Uion(t-1,x,y);
				if(flag!=-1&&flag!=t-1)
					fake++;
			}
		}

		printf("%d\n",fake);
	
	return 0;
}
