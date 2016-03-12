#include <stdio.h>
#include <string>

using namespace std;

#define T 32
#define Lmax 100010
#define Omax 100010

long int col[T]={0x00000001,0x00000002,0x00000004,0x00000008,
				 0x00000010,0x00000020,0x00000040,0x00000080,
				 0x00000100,0x00000200,0x00000400,0x00000800,
				 0x00001000,0x00002000,0x00004000,0x00008000,
				 0x00010000,0x00020000,0x00040000,0x00080000,
				 0x00100000,0x00200000,0x00400000,0x00800000,
				 0x01000000,0x02000000,0x04000000,0x08000000,
				 0x10000000,0x20000000,0x40000000,0x80000000};

long int V;

struct Node{
	long int visit;

	int cValue;

	Node(){
		visit=1;
		cValue=-1;
	}
}N[Lmax<<2];

void PushUp(int rt,int t)
{
	N[rt].visit=(N[rt<<1].visit)|(N[rt<<1|1].visit);
}

void PushDown(int rt,int t)
{
	if(N[rt].cValue!=-1)
	{
		N[rt<<1].cValue=N[rt].cValue;
		N[rt<<1|1].cValue=N[rt].cValue;

		N[rt<<1].visit=col[N[rt].cValue-1];
		N[rt<<1|1].visit=col[N[rt].cValue-1];

		N[rt].cValue=-1;
	}
}

void Query(int l,int r,int ll,int rr,int rt,int t)
{
	if(l<=ll&&rr<=r)
	{
		V=V|(N[rt].visit);
		//printf("sss %d %d\n",rt,N[rt].visit);

		/*for(int i=0;i<=t;i++)
				printf("%d ",V[i]);
			printf("\n");*/

		return;
	}

	int mid=(ll+rr)>>1;
	PushDown(rt,t);
	if(mid>=l) Query(l,r,ll,mid,rt<<1,t);
	if(mid<r) Query(l,r,mid+1,rr,rt<<1|1,t);
}

void UpDate(int l,int r,int ll,int rr,int cValue,int rt,int t)
{
	if(l<=ll&&rr<=r)
	{
		N[rt].visit=col[cValue-1];
		N[rt].cValue=cValue;

		//printf("update : %d %d\n",rt,N[rt].visit);

		return;
	}

	int mid=(ll+rr)>>1;
	PushDown(rt,t);
	if(mid>=l) UpDate(l,r,ll,mid,cValue,rt<<1,t);
	if(mid<r) UpDate(l,r,mid+1,rr,cValue,rt<<1|1,t);
	PushUp(rt,t);
}

int main(int argc, char *argv[])
{
	int l,t,o;
	scanf("%d %d %d",&l,&t,&o);

	getchar();
	for(int i=0;i<o;i++)
	{
		char tmpc;
		scanf("%c",&tmpc);

		if(tmpc=='C')
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(a<b)
				UpDate(a,b,1,l,c,1,t);
			else
				UpDate(b,a,1,l,c,1,t);
		}
		else
		{
			V=0;
			int a,b;
			scanf("%d %d",&a,&b);
			if(a<b)
				Query(a,b,1,l,1,t);
			else
				Query(b,a,1,l,1,t);
			int ans=0;
			for(int j=0;j<t;j++)
			{
				//printf("%d %d\n",2|1,col[j]);
				if((V&col[j])!=0)
					ans++;
			}
			printf("%d\n",ans);
		}
		getchar();
	}
	
	return 0;
}
