#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define PI 3.141592653

int main()
{
	int num;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		float a,b;
		scanf("%f %f",&a,&b);

		int year;
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,(int)(1+(float)PI*(a*a+b*b)/(float)100.0));
	}
	printf("END OF OUTPUT.");

	return 0;
}