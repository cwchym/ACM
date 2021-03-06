#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;//ľ������
int InitLen;

bool dfs(bool *visit,int *stick,int num,int curlen,int s)
{
	if(num==n)
		return true;

	int sample=-1;
	for(int i=s;i<n;i++)
	{
		
		if(visit[i]||stick[i]==sample)
			continue;

		visit[i]=true;
		if(curlen-stick[i]>0)
		{
			if(dfs(visit,stick,num+1,curlen-stick[i],i))
				return true;
			else
				sample=stick[i];
		}
		else if(curlen-stick[i]==0)
		{
			if(dfs(visit,stick,num+1,InitLen,0))
				return true;
			else
				sample=stick[i];
		}
		visit[i] = false;

		if(curlen==InitLen)//��֦δ����
			break;
	}
	return false;
}

int cmp(const void * a,const void *b)
{
	return *(int *)b-*(int *)a;
}

bool *cin_visit;
int *cin_stick;

int main(int argc, char *argv[])
{
	scanf("%d",&n);
	do{
		int sum=0;
		cin_visit=new bool[n];
		cin_stick=new int[n];

		for(int i=0;i<n;i++)
		{
			scanf("%d",&cin_stick[i]);
			cin_visit[i]=false;
			sum+=cin_stick[i];
		}

		qsort(cin_stick,n,sizeof(cin_stick[0]),cmp);

		bool flag=false;

		for(InitLen=cin_stick[0];InitLen<=sum-InitLen;InitLen++)
		{
			//printf("big :%d\n",InitLen);
			if((sum%InitLen==0)&&dfs(cin_visit,cin_stick,0,InitLen,0))
			{
				printf("%d\n",InitLen);
				flag=true;
				break;
			}
		}

		if(!flag)
			printf("%d\n",sum);

		delete cin_visit;
		delete cin_stick;

		scanf("%d",&n);
	}while(n);
	return 0;
}
