#include <stdio.h>
#include <math.h>

typedef struct{
	int r;
	int g;
	int b;
}rgb;

int main(int argc, char *argv[])
{
	rgb t[16];
	for(int i=0;i<16;i++)
		scanf("%d %d %d",&(t[i].r),&(t[i].g),&(t[i].b));

	rgb q;
	while(scanf("%d %d %d",&(q.r),&(q.g),&(q.b))==3)
	{
		if(q.r==-1&&q.g==-1&&q.b==-1)
			break;
		int Min=255*255*3;
		int Min_Id=-1;
		for(int i=0;i<16;i++)
		{
			int tmp=(q.r-t[i].r)*(q.r-t[i].r)+(q.g-t[i].g)*(q.g-t[i].g)+(q.b-t[i].b)*(q.b-t[i].b);
			if(tmp<Min)
			{
				Min=tmp;
				Min_Id=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",q.r,q.g,q.b,t[Min_Id].r,t[Min_Id].g,t[Min_Id].b);
	}
	
	return 0;
}
