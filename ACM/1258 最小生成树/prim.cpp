#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int Max=500;

bool used[Max];
__int64 lowest[Max];
__int64 link[Max][Max];
int f[Max];

typedef struct{
	int l;
	int r;
	__int64 length;
}Edge;

Edge* e[Max*Max];

int cmp(const void *a,const void *b)
{
	if(((*(Edge **)a)->length)>((*(Edge **)b)->length))
		return 1;
	else if(((*(Edge **)a)->length)<((*(Edge **)b)->length))
		return -1;
	else
		return 0;
}

__int64 kurskal(int n,int a)
{
	qsort(e,a,sizeof(e[0]),cmp);
	for(int i=0;i<n;i++)
		f[i]=i;

	int x=1;
	int k=0;
	__int64 sum=0;
	while(x<n)
	{
		int l=e[k]->l;
		int r=e[k]->r;
		if(f[l]!=f[r])
		{
			sum+=e[k]->length;
			for(int j=0;j<n;j++)
			{
				if(f[j]==f[r])
					f[j]=f[l];
			}
			x++;
		}
		k++;
	}
	return sum;
}

__int64 prim(int n)
{
	memset(used,false,sizeof(used));

	for(int i=0;i<n;i++)
		lowest[i]=100001;

	__int64 sum=0;
	int k=0;
	int l=0;
	while(l<n)
	{
		__int64 tmp_max=100001;
		int lowest_num=0;
		for(int j=0;j<n;j++)
		{

			if(!used[j])
			{
				if(lowest[j]>link[k][j])
					lowest[j]=link[k][j];
				if(lowest[j]<tmp_max)
				{
					tmp_max=lowest[j];
					lowest_num=j;
				}
			}
		
		}
		sum+=tmp_max;	
		k=lowest_num;
		used[k]=true;
		l++;
	}

	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)==1)
	{

		int a=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%I64d",&link[i][j]);
				if(i<j&&link[i][j]!=0)
				{
					e[a]=new Edge;
					e[a]->l=i;
					e[a]->r=j;
					e[a++]->length=link[i][j];
				}
			}
		
		//__int64 sum=kurskal(n,a);
		//for(int i=0;i<a;i++)
		//	printf("%I64d\n",e[i]->length);
		__int64 sum=prim(n);
		printf("%I64d\n",sum);
		for(int i=0;i<a;i++)
			delete e[i];
		
		

	}
	
	return 0;
}
