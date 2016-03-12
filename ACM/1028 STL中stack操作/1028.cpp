#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	stack<string> backward;
	stack<string> forward;

	char o[10],url[70];

	memcpy(url,"http://www.acm.org/",30);

	while(scanf("%s",&o)==1)
	{
		if(!strcmp(o,"QUIT")) break;
		else if(!strcmp(o,"VISIT"))
		{	
			backward.push(url);
			scanf("%s",&url);
			while(!forward.empty())
				forward.pop();
			printf("%s\n",url);
		}
		else if(!strcmp(o,"BACK"))
		{
			if(backward.empty())
				printf("Ignored\n");
			else
			{
				forward.push(url);
				memcpy(url,backward.top().c_str(),70);
				backward.pop();
				printf("%s\n",url);
			}
		}
		else if(!strcmp(o,"FORWARD"))
		{
			if(forward.empty())
				printf("Ignored\n");
			else
			{
				backward.push(url);
				memcpy(url,forward.top().c_str(),70);
				forward.pop();
				printf("%s\n",url);
			}
		}
	}
	
	return 0;
}
