#include <stdio.h>

int main(int argc, char *argv[])
{
	//FILE *ftr=fopen("test.txt","w");

	for(int i=1;i<10000;i++)
	{
		bool f=false;
		int tmp=i%10000;
		for(int x=tmp/1000;x>=tmp/1000-1&&x>=0;x--)
		{
			int tmp1=i%1000;
			for(int y=9;y>=0;y--)
			{
				int tmp2=i%100;
				for(int z=9;z>=0;z--)
				{
					int tmp3=(i-1001*x-101*y-11*z);

					if((tmp3%2==0)&&((tmp3/2)<10)&&tmp3>=0)
						f=true;
				}
			}
		}

		if(!f)
			printf("%d\n",i);
	}
	//fclose(ftr);

	return 0;
}
