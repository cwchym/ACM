#include <stdio.h>

#define MAX 1000010

int _max[MAX<<2];
int _min[MAX<<2];

void PushUp(int rt)
{
	_max[rt]=(_max[rt<<1]>_max[rt<<1|1])?_max[rt<<1]:_max[rt<<1|1];
	_min[rt]=(_min[rt<<1]<_min[rt<<1|1])?_min[rt<<1]:_min[rt<<1|1];
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&_max[rt]);
		_min[rt]=_max[rt];
		return;
	}

	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	PushUp(rt);
}

int query_min(int l,int r,int rt,int ll,int rr)
{
	if(l>=ll&&rr>=r)
	{
		return _min[rt];
	}
	
	int mid=(l+r)>>1;
	int tmp1=0x7fffffff,tmp2=0x7fffffff;
	if(ll<=mid) tmp1=query_min(l,mid,rt<<1,ll,rr);
	if(rr>mid) tmp2=query_min(mid+1,r,rt<<1|1,ll,rr);

	return (tmp1<=tmp2)?tmp1:tmp2;
}

int query_max(int l,int r,int rt,int ll,int rr)
{
	if(l>=ll&&rr>=r)
	{
		return _max[rt];
	}
	
	int mid=(l+r)>>1;
	int tmp1=-0x7fffffff,tmp2=-0x7fffffff;
	if(ll<=mid) tmp1=query_max(l,mid,rt<<1,ll,rr);
	if(rr>mid) tmp2=query_max(mid+1,r,rt<<1|1,ll,rr);

	return (tmp1>tmp2)?tmp1:tmp2;
}

int main(int argc, char *argv[])
{
	int n,k;
	while(scanf("%d %d",&n,&k)==2)
	{
		build(1,n,1);

		for(int i=1;i<=n-k+1;i++)
			printf("%d ", query_min(1,n,1,i,i+k-1));
		printf("\n");

		for(int i=1;i<=n-k+1;i++)
			printf("%d ", query_max(1,n,1,i,i+k-1));
		printf("\n");
	}
	
	return 0;
}
