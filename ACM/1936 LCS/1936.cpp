#include <stdio.h>
#include <string>

using namespace std;

#define MAX 100010

int LCS(char *a,char *b)
{
	int len_a=strlen(a);
	int len_b=strlen(b);

	//printf("strlen: %d %d\n",len_a,len_b);

	int *i[2];

	i[0]=new int[len_a];
	i[1]=new int[len_a];

	for(int l=0;l<len_b;l++)
	{
		for(int k=0;k<len_a;k++)
		{
			if(l+k==0&&a[k]==b[l])
				i[l][k]=1;
			else if(l+k==0)
				i[l][k]=0;

			if(l==0&&k!=0&&a[k]==b[l])
				i[l][k]=1;
			else if(l==0&&k!=0)
				i[l][k]=i[l][k-1];

			if(l!=0&&k==0&&a[k]==b[l])
				i[l%2][k]=1;
			else if(l!=0&&k==0)
				i[l%2][k]=i[(l-1)%2][k];

			if(l!=0&&k!=0&&a[k]==b[l])
				i[l%2][k]=i[(l-1)%2][k-1]+1;
			else if(l!=0&&k!=0)
				i[l%2][k]=(i[(l-1)%2][k]>i[l%2][k-1])?i[(l-1)%2][k]:i[l%2][k-1];
		}
	}
	int sum=i[(len_b-1)%2][len_a-1];

	delete i[0];
	delete i[1];

	//printf("%d\n",sum);
	return sum;
}

char str1[MAX];
char str2[MAX];

int main(int argc, char *argv[])
{
	while(scanf("%s %s",str1,str2)==2)
	{
		//printf("%s %s\n",str1,str2);

		int sum=LCS(str2,str1);

		if(sum==strlen(str1))
			printf("Yes\n");
		else
			printf("No\n");
	}

	
	return 0;
}
