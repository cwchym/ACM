#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int LCS(string &s1,string &s2)
{
	int size1=s1.size(),size2=s2.size();
	int* tmp[2];
	tmp[0]=new int[size1];
	tmp[1]=new int[size1];
	
	for(int i=0;i<size2;i++)
	{	
		for(int j=0;j<size1;j++)
		{
			if(i==0&&j==0&&s1[j]==s2[i])
				tmp[i][j]=1;
			else if(j==0&&i==0)
				tmp[i][j]=0;

			if(i==0&&j!=0)
			{
				if(s1[j]==s2[i])
					tmp[i][j]=1;
				else
					tmp[i][j]=tmp[i][j-1];
			}
			if(j==0&&i!=0)
			{
				if(s1[j]==s2[i])
					tmp[i%2][j]=1;
				else
					tmp[i%2][j]=tmp[(i-1)%2][j];
			}

			if(j!=0&&i!=0)
			{
				if(s1[j]==s2[i])
					tmp[i%2][j]=tmp[(i-1)%2][j-1]+1;
				else
					tmp[i%2][j]=(tmp[i%2][j-1]>tmp[(i-1)%2][j])?tmp[i%2][j-1]:tmp[(i-1)%2][j];
			}
		}
	}
	int sum=tmp[(size2-1)%2][(size1-1)];

	delete tmp[0];
	delete tmp[1];

	return sum;
}

int main(int argc, char *argv[])
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		int s=LCS(s1,s2);
		cout<<s<<endl;
	}
	
	return 0;
}
