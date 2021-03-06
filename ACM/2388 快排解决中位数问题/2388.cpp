#include <stdio.h>

const int MAX=10000;

__int64 cow[MAX];

void quick_sort(int a,int b)
{
	if(a>b)
		return;
	
	int i=a,j=b;
	__int64 tmp=cow[i];
	while(i<j)
	{
		while(i<j&&cow[j]>tmp)j--;
		if(i<j)
			cow[i++]=cow[j];

		while(i<j&&cow[i]<tmp)i++;
		if(i<j)
			cow[j--]=cow[i];
	}

	cow[i]=tmp;
	quick_sort(a,i-1);
	quick_sort(i+1,b);
}


int main(int argc, char *argv[])
{
	int N;
	while(scanf("%d",&N)==1)
	{
		for(int i=0;i<N;i++)
			scanf("%I64d",&cow[i]);

		quick_sort(0, N-1);
		printf("%I64d\n",cow[N/2]);
	}
	return 0;
}
