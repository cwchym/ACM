#include <stdio.h>
#include <string>

using namespace std;

int D[1000];
int N[1000];
int a[1000];

int binarysearch(int x,int r)
{
	int l=1,mid;

	while(l<=r)
	{
		mid=(l+r)>>1;
		if(D[mid-1]<=x&&x<D[mid])return mid;
		if(x>D[mid])l=mid+1;
		else r=mid-1;
	}
	return -1;
}

int LIS(int n)
{
	int len=1;
	D[0]=0;
	D[1]=a[1];

	for(int i=2;i<=n;i++)
		D[i]=10001;

	N[1]=a[1];

	for(int i=2;i<=n;i++)
	{
		if(a[i]>D[len])
		{
			N[++len]=a[i];
			D[len]=a[i];
		}
		else
		{
			int tmp = binarysearch(a[i],n);
			if(tmp==len)
				N[tmp]=a[i];
			D[tmp]=a[i];
		}

	}

	return len;
}

int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);

		int ans=LIS(n);
		printf("%d\n",ans);
		//for(int j=1;j<=ans;j++)
			//printf("%d ",N[j]);
		//printf("\n");
	}
	return 0;
}
