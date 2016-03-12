#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char a[10],b[10],c[10];
	int n;
	int coin[12];//0表示平衡即真，1表示up，2表示down

	scanf("%d",&n);

	while(n--)
	{
		memset(coin,-1,sizeof(coin));
		for(int i=0;i<3;i++)
		{
			scanf("%s %s %s",&a,&b,&c);
			getchar();

			if(!strcmp(c,"even"))
			{
				int ii=0;
				while(a[ii]!='\0')
					coin[a[ii++]-'A']=0;

				while(--ii>=0)
					coin[b[ii]-'A']=0;
				
			}
			else if(!strcmp(c,"up"))
			{
				for(int j=0;j<12;j++)
				{
					bool appear=false;
					for(int k=0;a[k]!='\0';k++)
					{
						if(j==(a[k]-'A'))
						{
							if(coin[j]==-1)
								coin[j]=2;
							else if(coin[j]==1)
								coin[j]=0;
							appear=true;
							break;
						}
						else if(j==(b[k]-'A'))
						{
							if(coin[j]==-1)
								coin[j]=1;
							else if(coin[j]==2)
								coin[j]=0;

							appear=true;
							break;
						}
					}
					if(!appear)
						coin[j]=0;
				}
			}
			else if(!strcmp(c,"down"))
			{
				for(int j=0;j<12;j++)
				{
					bool appear=false;
					for(int k=0;a[k]!='\0';k++)
					{
						if(j==(a[k]-'A'))
						{
							if(coin[j]==-1)
								coin[j]=1;
							else if(coin[j]==2)
								coin[j]=0;

							appear=true;
							break;
						}
						else if(j==(b[k]-'A'))
						{
							if(coin[j]==-1)
								coin[j]=2;
							else if(coin[j]==1)
								coin[j]=0;
							appear=true;
							break;
						}
					}
					if(!appear)
						coin[j]=0;
				}
			}
		}

		for(int i=0;i<12;i++)
			if(coin[i]!=0)
			{
				if(coin[i]==1)
				{
					printf("%c is the counterfeit coin and it is light.\n",i+'A');
					break;
				}
				else
				{
					printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
					break;
				}
			}
	}
	
	return 0;
}
