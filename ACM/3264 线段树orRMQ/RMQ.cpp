#include <stdio.h>
#include <math.h>

#define INT __int64

const int MAX=50000;
//const int lg=(int)(log(MAX)/log(2))+1;

INT max[MAX+1][16];
INT min[MAX+1][16];

INT Max_ans(INT a,INT b)
{return (a>b)?a:b;}

INT Min_ans(INT a,INT b)
{return (a<b)?a:b;}

void dp(INT n)
{
	for(INT i=1;i<=n;i++)
	{
		scanf("%I64d",&max[i][0]);
		min[i][0]=max[i][0];
	}

	for(INT j=1;(1<<j)<n;j++)
		for(INT i=1;i<=n;i++)
		if(i+(1<<j)-1<=n)
		{
			max[i][j]=Max_ans(max[i][j-1],max[i+(1<<(j-1))][j-1]);
			min[i][j]=Min_ans(min[i][j-1],min[i+(1<<(j-1))][j-1]);
			//printf("%I64d %I64d %I64d\n",i,j,min[i][j]);
		}
}

void query(INT l,INT r,INT &high,INT &low)
{
	INT k=(int)(log(double(r-l+1))/log(double(2)));
	high=Max_ans(max[l][k],max[r-(1<<k)+1][k]);
	low=Min_ans(min[l][k],min[r-(1<<k)+1][k]);
}

int main(int argc, char *argv[])
{
	INT a,b;
	while(scanf("%I64d %I64d",&a,&b)==2)
	{
		dp(a);
		printf("Scanf over\n");
		INT h,l;
		INT ans;
		for(INT i=0;i<b;i++)
		{
			INT c,d;
			scanf("%I64d %I64d",&c,&d);
			query(c,d,h,l);
			ans=h-l;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
