#include <stdio.h>
#include <string>

using namespace std;

void convert(char * a)
{
	int i=0;
	while(a[i]!='\n')
	{
		if(a[i]>='A'&&a[i]<='Z')
			a[i]=(a[i]-'A'-5+26)%26+'A';
		i++;
	}
	a[i]='\0';
}

int main(int argc, char *argv[])
{
	for(int i=0;i<100;i++)
	{
		char s[20];
		char message[201];

		scanf("%s",s);
		getchar();

		if(!strcmp(s,"ENDOFINPUT"))
			break;

		char t;
		int j=0;
		while((t=getchar())!='\n')
			message[j++]=t;
		message[j]='\n';

		for(int k=0;k<4;k++)
			getchar();

		convert(message);
		printf("%s\n",message);

	}
	
	return 0;
}
