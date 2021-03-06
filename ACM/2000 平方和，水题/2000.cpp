#include <stdio.h>

const int Max=142;

int N[Max];

void GetDay(int &n,int &l,int day)
{
	for(int i=1;i<=Max;i++)
		N[i]=(i+1)*i/2;

	int left=1,right=Max-1;
	while(left<=right)
	{
		int mid=(left+right)>>1;
		if(N[mid]<=day&&day<N[mid+1])
		{
			n=mid;
			l=day-N[n];
			return;
		}

		if(N[mid+1]<=day) left=mid+1;
		else if(N[mid]>day) right=mid-1;
	}
}

int main(int argc, char *argv[])
{
	int day;
	for(int i=0;i<21;i++)
	{
		scanf("%d",&day);

		if(day==0)
			break;

		int n1,l1;
		GetDay(n1,l1,day);

		printf("%d %d\n",day,n1*(n1+1)*(2*n1+1)/6+l1*(n1+1));
	}
	
	return 0;
}
