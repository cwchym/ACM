#include <stdio.h>

#define MAX 1000001

int prime[MAX]={0};

void getPrime()
{
	int i,j;
	for(i=2;i<MAX/2;i++)
	{
		if(!prime[i])
		{
			for(j=i+i;j<MAX;j+=i)
				prime[j]=1;
		}
	}
}

int main(int argc, char *argv[])
{	
	getPrime();
	int x;
	while(scanf("%d",&x)==1)
	{
		if(x<=0)
			break;

		int i;
		bool flag=true;
		for(i=3;i<=x/2;i=i+2)
		{
			if(!prime[i]&&!prime[x-i])
			{
				flag=false;
				break;
			}
		}

		if(flag)
			printf("Goldbach's conjecture is wrong.");
		else
			printf("%d = %d + %d\n",x,i,x-i);
	}
	
	return 0;
}
