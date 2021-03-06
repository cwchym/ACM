#include <stdio.h>

#define INT __int64

const int MAX=50000;

typedef struct{
	INT max;
	INT min;
	INT l;
	INT r;
	INT addMark;
}Node;

Node N[MAX*4+10];//Min

void pushUp(INT rt)
{
	N[rt].max=(N[rt<<1].max>N[rt<<1|1].max)?N[rt<<1].max:N[rt<<1|1].max;
	N[rt].min=(N[rt<<1].min<N[rt<<1|1].min)?N[rt<<1].min:N[rt<<1|1].min;
}

void pushDown(INT rt)
{
	if(N[rt].addMark!=0)
	{
		N[rt<<1].addMark+=N[rt].addMark;
		N[rt<<1|1].addMark+=N[rt].addMark;

		N[rt<<1].max += N[rt].addMark*(N[rt].r-N[rt].l+1);
		N[rt<<1|1].max += N[rt].addMark*(N[rt].r-N[rt].l+1);

		N[rt<<1].min += N[rt].addMark*(N[rt].r-N[rt].l+1);
		N[rt<<1|1].min += N[rt].addMark*(N[rt].r-N[rt].l+1);
		

		N[rt].addMark=0;
	}
}

void build(INT rt,INT l,INT r)
{
	N[rt].l=l;
	N[rt].r=r;
	N[rt].addMark=0;

	if(l==r)
	{
		scanf("%d",&N[rt].max);
		N[rt].min=N[rt].max;
		return;
	}

	INT mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushUp(rt);
}

void upDate(INT rt,INT l,INT r,INT add)
{
	if(l>N[rt].r||r<N[rt].l)
		return;
	

	if(l<=N[rt].l&&r>=N[rt].r)
	{
		N[rt].addMark+=add;
		N[rt].max+=add*(N[rt].r-N[rt].l+1);
		N[rt].min+=add*(N[rt].r-N[rt].l+1);
		return;
	}

	pushDown(rt);

	INT mid_N=(N[rt].l+N[rt].r)>>1;
	if(mid_N>=l) upDate(rt<<1,l,r,add);
	if(mid_N<r) upDate(rt<<1|1,l,r,add);

	pushUp(rt);
}

void query(INT rt,INT l,INT r,INT &max,INT &min)
{
	if(l>N[rt].r||r<N[rt].l)
	{
		max=-1000000;
		min=1000000;
		return;
	}

	if(l<=N[rt].l&&r>=N[rt].r)
	{
		max=N[rt].max;
		min=N[rt].min;

		return;
	}

	pushDown(rt);

	INT mid=(N[rt].l+N[rt].r)>>1;
	INT tmp_max1=-1000000,tmp_max2=-1000000;
	INT tmp_min1=1000000,tmp_min2=1000000;
	if(mid>=l) query(rt<<1,l,r,tmp_max1,tmp_min1);
	if(mid<r) query(rt<<1|1,l,r,tmp_max2,tmp_min2);

	if(tmp_max1>tmp_max2)
		max=tmp_max1;
	else
		max=tmp_max2;

	if(tmp_min1<tmp_min2)
		min=tmp_min1;
	else
		min=tmp_min2;
}

int main(int argc, char *argv[])
{
	INT a,b;
	while(scanf("%I64d %I64d",&a,&b)==2)
	{
		build(1,1,a);
		INT max=-1000000,min=1000000;
		INT ans;
		for(INT i=0;i<b;i++)
		{
			INT c,d;
			scanf("%I64d %I64d",&c,&d);
			query(1,c,d,max,min);
			ans=max-min;
			printf("%I64d\n",ans);
		}
	}

	return 0;
}
