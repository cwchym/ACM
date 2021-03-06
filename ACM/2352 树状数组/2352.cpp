#include <stdio.h>
#include <string.h>

const int Max=32100;

int D[Max];
int s[Max];

void insert(int x,int n){
	D[x]+=1;
	while(x<=Max)
	{
		x+=x&(-x);
		D[x]+=1;
	}
}

int query(int r){
	int sum=0;
	while(r>0){
		sum+=D[r];
		r-=r&(-r);
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n,a,b;
	while(scanf("%d",&n)==1)
	{
		memset(D,0,sizeof(D));
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&a,&b);
			s[query(a+1)]++;
			insert(a+1,n);
		}

		for(int i=0;i<n;i++)
		{
			printf("%d\n",s[i]);
		}
	}
	
	return 0;
}
