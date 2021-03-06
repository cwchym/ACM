#include <stdio.h>
#include <string.h>

const __int64 MAX=100000;

__int64 tree1[MAX];//delta[i]表示i--n的每个元素都有增量
__int64 tree2[MAX];//i*delta[i]
__int64 sum[MAX];

void update1(__int64 a,__int64 c,__int64 m)
{
	while(a<=m){
		tree1[a]+=c;
		a+=(a&(-a));
	}
}

void update2(__int64 a,__int64 c,__int64 m)
{
	while(a<=m){
		tree2[a]+=c;
		a+=(a&(-a));
	}
}


__int64 query(__int64 t[],__int64 a)
{
	__int64 sum=0;
	while(a>0){
		sum+=t[a];
		a-=(a&(-a));
	}
	return sum;
}

void AddToInterval(__int64 a1,__int64 b1,__int64 c1,__int64 m)
{
	update1(a1,c1,m);
	update1(b1+1,-c1,m);
	

	update2(a1,a1*c1,m);
	update2(b1+1,-(b1+1)*c1,m);
}



int main(int argc, char *argv[])
{
	__int64 a,b;
	scanf("%I64d %I64d",&a,&b);
	memset(tree1,0,sizeof(tree1));
	memset(tree2,0,sizeof(tree2));
	memset(sum,0,sizeof(sum));

	for(__int64 i=1;i<=a;i++)
	{
		__int64 tmp;
		scanf("%I64d",&tmp);
		sum[i]=sum[i-1]+tmp;
	}


	while(b--)
	{
		char c[2];
		scanf("%s",&c);
		__int64 d,e,f;
		if(c[0]=='Q')
		{
			scanf("%I64d %I64d",&d,&e);
			__int64 sum1=sum[e]+(e+1)*query(tree1,e)-query(tree2,e);
			__int64 sum2=sum[d-1]+(d)*query(tree1,d-1)-query(tree2,d-1);
			printf("%I64d\n",sum1-sum2);
		}
		else if(c[0]=='C')
		{
			scanf("%I64d %I64d %I64d",&d,&e,&f);
			AddToInterval(d,e,f,a);
		}
	}
	
	return 0;
}
