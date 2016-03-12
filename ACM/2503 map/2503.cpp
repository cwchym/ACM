#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char English[11],foreign[11];
	map<string,string> f;

	char t;
	while(1)
	{
		t=getchar();
		if(t=='\n')
			break;

		int i;
		for(i=0;t!=' ';i++)
		{
			English[i]=t;
			t=getchar();
		}

		English[i]='\0';

		scanf("%s",&foreign);
		getchar();

		f.insert(map<string,string>::value_type(foreign,English));
	}

	char query[11];
	while(scanf("%s",&query)==1)
	{
		if(f.count(query))	
			printf("%s\n",f[query].c_str());
		else
			printf("eh\n");
	}


	return 0;
}
