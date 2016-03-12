#include <stdio.h>
#include <stdlib.h>

int n;
int Len;

bool dfs(bool *v,int *s,int num,int curlen,int start)
{
	if(num==n)
		return true;

	int sample=-1;
	for(int i=start;i<n;i++)
	{
		if(v[i]||s[i]==sample)
			continue;

		v[i]=true;
		
		if(curlen-s[i]>0)
		{
			if(dfs(v,s,num+1,curlen-s[i],i))
				return true;
			else
				sample=s[i];
		}
		else if(curlen-s[i]==0)
		{
			if(dfs(v,s,num+1,Len,0))
				return true;
			else
				sample=s[i];
		}

		v[i]=false;

		if(curlen==Len)
			return false;
	}
	return false;
}

int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}

bool *visit;
int *stick;

int main(int argc, char *argv[])
{
	int a;
	scanf("%d", &a);

	while(a--)
	{
		int sum=0;
		scanf("%d",&n);
		
		visit = new bool[n];
		stick = new int[n];

		for(int i=0;i<n;i++)
		{
			scanf("%d",&stick[i]);
			sum+=stick[i];
			visit[i]=false;
		}

		qsort(stick,n,sizeof(stick[0]),cmp);

		if(sum%4==0&&n>=4)
		{
			
			Len=sum/4;printf("Square is OK: %d\n",Len);
			if(dfs(visit,stick,0,Len,0))
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n");;

		delete visit;
		delete stick;
	}
	
	return 0;
}
