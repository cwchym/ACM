#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		double x=(sqrt(5.0)+1.0)/2.0;

		int k=b-a;

		if(k<0)
			k=-k;

		int tmp=(int)(k*x+k);
		int tmp2;

		if(a<b)
			tmp2=b;
		else
			tmp2=a;

		if(tmp==tmp2)
			printf("0\n");
		else
			printf("1\n");
	}
	
	return 0;
}
