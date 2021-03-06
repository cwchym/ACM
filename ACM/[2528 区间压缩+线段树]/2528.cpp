#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 10010
#define inf 10000000

int col[MAX<<4];
__int64 input[MAX<<3],L_input[MAX],R_input[MAX];

void pushDown(int rt)
{
	if(col[rt]!=-1)
	{
		col[rt<<1]=col[rt<<1|1]=col[rt];
	}
}

bool update(int L,int R,int l,int r,int rt,int c)
{
	//printf("Update:%d %d\n",l,r);
	if(L<=l&&R>=r&&col[rt]==-1)
	{
		col[rt]=c;
		return true;
	}
	else if(L<=l&&R>=r)
			return false;

	pushDown(rt);
	int mid=(l+r)>>1;
	bool tmp1=false,tmp2=false;
	if(mid>=L) tmp1=update(L,R,l,mid,rt<<1,c);
	if(mid<R) tmp2=update(L,R,mid+1,r,rt<<1|1,c);
	
	return tmp1||tmp2;
}

int Binary_search(__int64 x,int n)
{
	int l=1,r=n;
	while(l<=r)
	{
		//printf("BS : %d %d\n",l,r);
		int mid=(l+r)>>1;
		if(input[mid]==x) return mid;
		if(x>input[mid]) l=mid+1;
		else r=mid-1;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int a;
	scanf("%d",&a);
	while(a-->0)
	{
		memset(col,-1,sizeof(col));
		memset(input,inf,sizeof(input));
		input[0]=0;
		int n;
		int nn=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%I64d %I64d",&L_input[i],&R_input[i]);
			input[nn++] = L_input[i];
			input[nn++] = R_input[i];
		}
		input[nn]=inf;
		sort(input+1,input+nn);

		int m=1;
		for(int i=1;i<nn;i++)
			if(input[i]!=input[i+1])
				input[m++]=input[i];

		for(int i=m;i>1;i--)
			if(input[i]-input[i-1]>1) input[m++]=input[i]-1;

		sort(input+1,input+m);

		//for(int i=1;i<m;i++)
		//	printf("%d\n",input[i]);

		int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			int L=Binary_search(L_input[i],m);
			int R=Binary_search(R_input[i],m);

			//printf("L %d,R %d\n",L,R);
			if(update(L,R,1,m-1,1,1))
				ans++;
		}

		printf("%d\n",ans);
	}

	return 0;
}
