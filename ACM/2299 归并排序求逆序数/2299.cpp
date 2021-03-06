#include <stdio.h>

#define INT __int64

const INT max=500000;

INT d[max];

INT ultraSort(INT data[],INT l,INT r)
{
	INT len=r-l+1;
	INT mid=(l+r)>>1;
	
	if(len==1)
		return 0;

	INT sum=ultraSort(data,l,mid);
	sum+=ultraSort(data,mid+1,r);

	INT *left=new INT[mid-l+1];
	INT *right=new INT[r-mid];

	for(INT i=0;i<mid-l+1;i++)
		left[i]=data[l+i];

	for(INT i=0;i<r-mid;i++)
		right[i]=data[mid+1+i];

	INT i=0,j=0;
	while(i<mid-l+1&&j<r-mid)
	{
		if(left[i]<=right[j])
		{
			sum+=j;
			data[l+i+j]=left[i++];
			//printf("sum : %I64d\n",sum);
		}
		else
			data[l+i+j]=right[j++];
	}

	if(i!=mid-l+1)
	{
		for(;i<mid-l+1;i++)
		{
			data[l+i+j]=left[i];
			sum+=j;
		}
	}
	else
		for(;j<r-mid;j++)
			data[l+i+j]=right[j];

	delete []left;
	delete []right;

	return sum;
}

int main(int argc, char *argv[])
{
	
	INT n;
	while(1)
	{
		scanf("%I64d",&n);

		if(n==0)
			break;

		for(INT i=0;i<n;i++)
			scanf("%I64d",&d[i]);

		INT sum=ultraSort(d,0,n-1);

		printf("%I64d\n",sum);
	}

	return 0;
}
