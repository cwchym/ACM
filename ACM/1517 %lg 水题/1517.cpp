#include <stdio.h>

double cal(int n)
{
	double sum=1.0;
	for(;n>0;n--)
	{

		sum*=n;
	}
	return sum;
}

int main(int argc, char *argv[])
{

	printf("n e\n");
	printf("- -----------\n");
	
	double sum=0;
	for(int i=0;i<10;i++)
	{
		sum+=(1.0/(cal(i)));
		printf("%d %.10lg\n",i,sum);
	}
	
	return 0;
}
