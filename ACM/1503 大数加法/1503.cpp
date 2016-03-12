#include <stdio.h>
#include <string>

using namespace std;

#define MAX 104

void m_plus(char *a,char *b)
{
	int add=0;
	for(int i=0;i<MAX;i++)
	{
		int tmp=add+(a[i]-'0')+(b[i]-'0');

		add=tmp/10;
		a[i]=tmp%10+'0';
	}

}

int main(int argc, char *argv[])
{
	char sum[MAX];
	char tmp[MAX];

	memset(sum,'0',sizeof(sum));
	memset(tmp,'0',sizeof(tmp));

	while(scanf("%s",&tmp)==1)
	{
		if(!strcmp(tmp,"0"))
			break;

		int length=strlen(tmp);

		char inverse[MAX];
		memset(inverse,'0',sizeof(inverse));

		for(int i=0;i<length;i++)
			inverse[i]=tmp[length-1-i];

		m_plus(sum,inverse);
	}

	int i=MAX-1;
	while(sum[i]=='0')
		i--;

	char tmp_sum[MAX];
	for(int j=0;j<=i;j++)
		tmp_sum[j]=sum[i-j];

	tmp_sum[i+1]='\0';

	printf("%s\n",tmp_sum);
	
	return 0;
}
