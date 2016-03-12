#include <stdio.h>

const __int64 MAX=100000;

typedef struct{
	__int64 sum;
	__int64 l;
	__int64 r;
	__int64  addMark;
}Node;

Node N[MAX*10];

void pushUp(__int64 rt)
{
	N[rt].sum=N[rt<<1].sum + N[rt<<1|1].sum;
}

void pushDown(__int64 rt)
{
	if(N[rt].addMark!=0)
	{
		N[rt<<1].addMark += N[rt].addMark;
		N[rt<<1|1].addMark += N[rt].addMark;
		N[rt<<1].sum += N[rt].addMark*(N[rt<<1].r-N[rt<<1].l+1);
		N[rt<<1|1].sum += N[rt].addMark*(N[rt<<1|1].r-N[rt<<1|1].l+1);
		N[rt].addMark=0;
	}
}

void build(__int64 a,__int64 l,__int64 r)
{
	N[a].addMark=0;
	N[a].l=l;
	N[a].r=r;
	if(l==r)
	{
		scanf("%I64d",&(N[a].sum));
		return;
	}

	__int64 mid=(l+r)/2;
	build(a<<1,l,mid);
	build(a<<1|1,mid+1,r);
	pushUp(a);
}


void update(__int64 uL,__int64 uR,__int64 c,__int64 rt)
{
	if(N[rt].l>=uL&&uR>=N[rt].r)
	{
		N[rt].addMark+=c;
		N[rt].sum+=(__int64)c*(N[rt].r-N[rt].l+1);
		return;
	}

	pushDown(rt);
	__int64 mid=(N[rt].l+N[rt].r)>>1;
	if(uL<=mid)update(uL,uR,c,rt<<1);
	if(uR>mid)update(uL,uR,c,rt<<1|1);
	pushUp(rt);
}

__int64 query(__int64 rt,__int64 l,__int64 r)
{
	if(N[rt].l>r||N[rt].r<l)
	{
		//printf("None\n");
		return 0;
	}

	if(N[rt].l>=l&&N[rt].r<=r)
	{
		
		return N[rt].sum;
	}//printf("N[%d].l is %d,N[].r is %d\n",rt,N[rt].l,N[rt].r);

	pushDown(rt);
	__int64 mid=(N[rt].l+N[rt].r)>>1;
	__int64 t1=0,t2=0;
	if(l<=mid) 
	{
		//printf("left\n");
		t1=query(rt<<1,l,r);
	}
	if(mid<r)
	{
		//printf("right\n");
		t2=query(rt<<1|1,l,r);
	}

	return (t1+t2);
}

int main(int argc, char *argv[])
{
	__int64 a,b;
	scanf("%I64d %I64d",&a,&b);
	build(1,1,a);
	while(b--)
	{
		char c[2];
		scanf("%s",&c);
		__int64 d,e,f;
		if(c[0]=='Q')
		{
			scanf("%I64d %I64d",&d,&e);
			printf("%I64d\n",query(1,d,e));
		}
		else if(c[0]=='C')
		{
			
			scanf("%I64d%I64d%I64d\n",&d,&e,&f);
			update(d,e,f,1);
		}
	}
	
	return 0;
}
