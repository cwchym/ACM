#include <stdio.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main(int argc, char *argv[])
{
	int a,b,c,d,e,f;
	while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6)
	{
		if((a+b+c+d+e+f)==0)
			break;

		int SumParcel=0;

		SumParcel+=f;

		SumParcel+=e;
		a=max(0,a-11*e);

		SumParcel+=d;
		
		if(d>b/5)
		{
			if(b%5==0)
			{
				a=max(0,a-20*(d-b/5));
				b=0;
			}
			else
			{
				a=max(0,(a-4*(5-b%5)));
				a=max(0,a-20*(d-b/5-1));
				b=0;
			}
		}
		else
		{
			b=b-d*5;
		}

		SumParcel+=(c)/4;
		c=c-c/4*4;
		if(c)
		{
			SumParcel+=1;
			if(c==1)
			{
				if(b>=5)
				{
					b-=5;
					a=max(0,a-7);
				}
				else
				{
					a=max(0,a-(27-4*b));
					b=0;
				}
			}
			else if(c==2)
			{
				if(b>=3)
				{
					b-=3;
					a=max(0,a-6);
				}else
				{
					a=max(0,a-(18-4*b));
					b=0;
				}
			}
			else if(c==3)
			{
				if(b>=1)
				{
					b-=1;
					a=max(0,a-5);
				}else
				{
					a=max(0,a-(9-4*b));
					b=0;
				}
			}
		}
		
		SumParcel+=b/9;
		b=b-b/9*9;
		if(b)
		{
			SumParcel+=1;
			a=max(0,a-(36-b*4));
		}

		SumParcel+=a/36;
		if(a-a/36*36)
			SumParcel+=1;

		printf("%d\n",SumParcel);
		
	}
	
	return 0;
}
