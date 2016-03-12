#include <cstdio>

using namespace std;

#define MAX 50010
#define sup -10000

int data[MAX];
long left[MAX],right[MAX],sum[MAX];

void GetRight(int n)
{
	long m=data[n-1],s=(data[n-1]>0)?data[n-1]:0;

	right[n-1]=data[n-1];
	
	for(int i=n-2;i>0;i--)
	{
		s+=data[i];
		if(s>m)
			m=s;
		if(s<0)
			s=0;
		right[i]=m;
	//	printf("right %d: %d\n",i,right[i]);
	}
}

void GetLeft(int n)
{
	long m=data[0],s=(data[0]>0)?data[0]:0;

	left[0]=data[0];
	
	for(int i=1;i<n-1;i++)
	{
		s+=data[i];
		if(s>m)
			m=s;
		if(s<0)
			s=0;
		left[i]=m;
	//	printf("left %d: %d\n",i,left[i]);
	}
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);

		GetRight(n);
		GetLeft(n);

		long ans=left[0]+right[1];
		for(int i=1;i<n-1;i++)
			ans=(ans>(left[i]+right[i+1]))?ans:(left[i]+right[i+1]);

		printf("%d\n",ans);
	}

	return 0;
}
