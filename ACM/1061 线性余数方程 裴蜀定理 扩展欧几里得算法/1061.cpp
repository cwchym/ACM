#include <stdio.h>
#include <math.h>

#define INT __int64 

INT Extend_Euclid(INT a,INT b,INT &x2,INT &y2)//(b>a)
{
	INT c=b%a;
	INT y1=-(b/a);
	if(c==0)
	{
		x2=0;
		y2=1;
		return a;
	}

	INT x=0,y=0;
	INT gcd=Extend_Euclid(c,a,x,y);

	x2=y;
	y2=x+y1*y;
	return gcd;
}

int main(int argc, char *argv[])
{
/*	INT a,b;
	scanf("%I64d %I64d",&a,&b);
	INT x,y;
	INT g=Extend_Euclid(a,b,x,y);
	printf("x:%I64d,y:%I64d,gcd:%I64d",x,y,g);
*/
	
	INT a,b,c,d,e;
	while(scanf("%I64d %I64d %I64d %I64d %I64d",&a,&b,&c,&d,&e)==5)
	{
		INT a1=d-c;
		INT b1=e;
		INT c1=a-b;
		INT x=0,y=0;

		if(a1<0)
		{
			a1=-a1;
			c1=-c1;
		}

		while(c1<=0)c1+=e;

		INT gcd=Extend_Euclid(a1,b1,x,y);

		if(c1%gcd!=0)printf("Impossible\n");
		else
		{
			//printf("%I64d %I64d %I64d %I64d\n",a1,b1,c1,gcd);
			INT ans=y*(c1/gcd)%(b1/gcd);
			while(ans<0)ans+=b1/gcd;
			printf("%I64d\n",ans);
		}
	}

	


	return 0;
}
