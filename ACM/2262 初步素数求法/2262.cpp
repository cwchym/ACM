#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//a*b%n
int Multi_Mod(int a,int b,int n)
{
	int re=0,tmp=a%n;
	while(b>0)
	{
		if(b%2==1)
			re+=tmp;
		if(re>n)
			re-=n;

		b/=2;
		tmp=tmp<<1;
		if(tmp>n)
			tmp-=n;
	}
	return re;
}

//a^b%n
int my_power(int a,int b,int n)
{
	int re=1,tmp=a%n;
	while(b>0)
	{
		if(b%2==1)
			re=Multi_Mod(re,tmp,n);

		b=b/2;
		tmp=Multi_Mod(tmp,tmp,n);
	}

	return re;
}

bool witness(int a,int m,int j,int n)
{
	int x,y;
	x=my_power(a,m,n);
	while(j--)
	{
		y=Multi_Mod(x,x,n);
		if(y==1&&x!=1&&x!=n-1)
			return true;
		x=y;
	}

	return y!=1;
}

bool Is_prime(int x,int count)
{
	int m=x-1,j=0;
	for(;!(m&0x1);m>>=1)
		j+=1;
	srand((int)time(0));
	
	for(int i=0;i<count;i++)
	{
		int a=rand()%(x-1)+1;
		if(witness(a,m,j,x))
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int x;
	while(scanf("%d",&x)==1)
	{
		if(x<=0)
			break;

		int i;
		for(i=3;i<=x/2;i=i+2)
		{
			if(Is_prime(i,5))
			{
				if(Is_prime(x-i,5))
					break;
			}
		}

		printf("%d = %d + %d\n",x,i,x-i);
	}
	
	return 0;
}
