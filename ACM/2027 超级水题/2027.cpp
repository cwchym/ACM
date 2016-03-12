#include <stdio.h>

int main(int argc, char *argv[])
{
	int a,b,n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>=b)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
		
	return 0;
}
