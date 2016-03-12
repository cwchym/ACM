#include <cstdio>

using namespace std;

#define MAX 100000

int GetAns(long a,long b,long c,long d)
{
	long tmp1=b-a,tmp2=d-c;

	if(tmp1==tmp2)
		return d+tmp1;
	else
		return d*((double)d/(double)c);
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d %d %d %d\n",a,b,c,d,GetAns(a,b,c,d));
	}
	
	return 0;
}
