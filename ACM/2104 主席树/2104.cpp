#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 100010

int T[MAX*20];
int left[MAX*20],right[MAX*20],root[MAX],Null=0;
int m_count=0;

pair<int,int> A[MAX];
int B[MAX],Tn;

int Insert(int i,int l,int r,int v)
{
	int re=++m_count;//l[0]=r[0]=0,T[0]=0,root[0]=0;

	T[re]=T[i]+1;
	
	int mid=(l+r)>>1;
	if(l==r)
	{
		left[re]=0;
		right[re]=0;
	}
	else if(mid>=v)
	{
		left[re]=Insert(left[i],l,mid,v);
		right[re]=right[i];
	}
	else if(mid<v)
	{
		right[re]=Insert(right[i],mid+1,r,v);
		left[re]=left[i];
	}

	return re;
}

int query(int ll,int rr,int l,int r,int k)
{
	if(l==r)
		return l;
	

	int tmp1,tmp2;
	if(left[ll]==Null) tmp1=0;
	else tmp1=T[left[ll]];
	if(left[rr]==Null) tmp2=0;
	else tmp2=T[left[rr]];

	int mid=(l+r)>>1;
	int re=0;
	if(tmp2-tmp1>=k)
	{
		re=query(left[ll],left[rr],l,mid,k);
	}
	else
	{
		re=query(right[ll],right[rr],mid+1,r,k-(tmp2-tmp1));
	}
	return re;
}

int main(int argc, char *argv[])
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		A[i]=make_pair(tmp,i);
	}

	sort(A,A+n);
	B[A[0].second]=Tn=0;
	for(int i=1;i<n;i++)
	{
		if(A[i].first!=A[i-1].first)
			A[++Tn].first=A[i].first;
		B[A[i].second]=Tn;
	}

	T[0]=left[0]=right[0]=root[0]=0;
	for(int i=0;i<=Tn;i++)
		root[i+1]=Insert(root[i],0,Tn,B[i]);
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);

		int answer=query(root[a-1],root[b],0,Tn,c);

		printf("%d\n",A[answer].first);
	}


	return 0;
}
