#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
const int MAX=5000;

int LCS(int n,char * c1,char *c2, int dp[][MAX])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				if(c1[i]==c2[j])
					dp[i%2][j]=1;
				else
				{
					if(j!=0)
					dp[i%2][j]=dp[i%2][j-1];
					else
					dp[i%2][j]=0;
				}
			}
			else if(j==0)
			{
				if(c1[i]==c2[j])
					dp[i%2][j]=1;
				else
					if(i!=0)
					dp[i%2][j]=dp[(i-1)%2][j];
					else
					dp[(i-1)%2][j]=0;
			}
			else
			{
				if(c1[i]==c2[j])
					dp[i%2][j]=dp[(i-1)%2][j-1]+1;//¹ö¶¯Êý×é
				else
					dp[i%2][j]=(dp[(i-1)%2][j]>dp[i%2][j-1])?dp[(i-1)%2][j]:dp[i%2][j-1];
			}		
		}
	return dp[(n-1)%2][n-1];
}

int d[2][MAX];

int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)==1)
	{
		char * s1=new char[n];
		char * s2=new char[n];

		for(int i=0,j=n-1;i<n;i++,j--)
		{
			cin>>s1[i];

			s2[j]=s1[i];
		}

		int ans=LCS(n,s1,s2,d);

		printf("%d\n",n-ans);
	}

	return 0;
}
