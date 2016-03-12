#include <stdio.h>

int value[8]={128,64,32,16,8,4,2,1};

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);

	getchar();
	for(int i=0;i<n;i++)
	{
		int output[4]={0};
		for(int j=0;j<4;j++)
		{
			char c;
			for(int k=0;k<8;k++)
			{
				scanf("%c",&c);
				//printf("%d : %c\n",j*8+k,c);
				output[j]+=(c=='1')?value[k]:0;
			}
		}
		
		while(getchar()==' ');

		printf("%d.%d.%d.%d\n",output[0],output[1],output[2],output[3]);
		
	}
	
	return 0;
}
