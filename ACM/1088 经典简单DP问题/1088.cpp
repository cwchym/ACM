#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int MAX=100;

int Simple_dp(int l,int r,int a1,int b1,int m[][MAX],int p[][MAX])
{
	if(m[l][r]!=-1)
		return m[l][r];
	else
	{
		//printf("%d\n",p[l][r]);
		int max=1;
		if(l-1>=0&&p[l][r]>p[l-1][r])
			max=1+Simple_dp(l-1,r,a1,b1,m,p);
		if(l+1<a1&&p[l][r]>p[l+1][r]&&max<1+Simple_dp(l+1,r,a1,b1,m,p))
			max=1+Simple_dp(l+1,r,a1,b1,m,p);
		if(r-1>=0&&p[l][r]>p[l][r-1]&&max<1+Simple_dp(l,r-1,a1,b1,m,p))
			max=1+Simple_dp(l,r-1,a1,b1,m,p);
		if(r+1<b1&&p[l][r]>p[l][r+1]&&max<1+Simple_dp(l,r+1,a1,b1,m,p))
			max=1+Simple_dp(l,r+1,a1,b1,m,p);

		m[l][r]=max;
		return m[l][r];
	}
}

int max[MAX][MAX];
int point[MAX][MAX];

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		memset(max,-1,sizeof(max));
		memset(point,-1,sizeof(point));
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				scanf("%d",&point[i][j]);


		int ans=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
			{
				if(ans<Simple_dp(i,j,a,b,max,point))
					ans=Simple_dp(i,j,a,b,max,point);
			}

		printf("%d\n",ans);
	}
	return 1;
}