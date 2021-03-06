#include <stdio.h>

#define MAX 50010

int student[MAX];
int num[MAX];

int Unit_num;

int find(int x)
{
	int re=x;
	while(student[re]!=re)
		re=student[re];
	student[x]=re;

	return re;
}

void Union(int x,int y)
{
	int tmp1=find(x);
	int tmp2=find(y);

	if(tmp1==tmp2);
	else
	{
		if(num[tmp1]>num[tmp2]) student[tmp1]=tmp2;
		else student[tmp2]=tmp1;

		Unit_num--;
	}
}

int main(int argc, char *argv[])
{
	int n,m;
	int count1=1;

	while(scanf("%d%d",&n,&m)==2)
	{
		if(n+m==0)
			break;

		for(int i=1;i<=n;i++)
		{
			student[i]=i;
			num[i]=1;
		}

		Unit_num=n;

		for(int j=0;j<m;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			
			Union(a,b);
		}

		printf("Case %d: %d\n",count1++,Unit_num);
	}
	
	return 0;
}
