#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 1000

struct point
{
	int x,y;
};

point P[MAX];

bool GetRange(double &x1,double &x2,int x,int y,int d)
{
	if(y>d)
		return false;

	double tmp=sqrt((double)(d*d-y*y));
	x1=(double)x-tmp;
	x2=(double)x+tmp;

	return true;
}

int cmp(const void * a,const void * b)
{
	double _a=((point *)a)->x;
	double _b=((point *)b)->x;

	if(_a-_b<0) return -1;
	else if(_a==_b) return 0;
	else return 1;
}

int main(int argc, char *argv[])
{
	int n,d,l=0;
	while(scanf("%d%d",&n,&d)==2)
	{
		if(n==0 && d==0)
			break;

		l++;

		int ans_num=1;
		bool flag=false;

		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&P[i].x,&P[i].y);
		}

		qsort(P,n,sizeof(P[0]),cmp);

		double x1,x2;
		if(!GetRange(x1,x2,P[0].x,P[0].y,d))
			flag=true;
		double tmp=x2;
		for(int i=1;i<n;i++)
		{
			if(!GetRange(x1,x2,P[i].x,P[i].y,d))
				flag=true;

			if(x1>tmp)
			{
				tmp=x2;
				ans_num++;
			}
			else if(x2<tmp)
				tmp=x2;
		}

		if(flag)
			printf("Case %d: -1\n",l);
		else
			printf("Case %d: %d\n",l,ans_num);
	}

	return 0;
}
