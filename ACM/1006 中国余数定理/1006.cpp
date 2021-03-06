#include <stdio.h>
#include <stdlib.h>

void Extend_Eucild(int a,int b,int &x,int &y)
{
	if(a%b==0)
	{
		x=0;
		y=1;
	}
	else
	{
		int t1=a/b;
		int t2=a%b;
		int tmp_x,tmp_y;
		Extend_Eucild(b,t2,tmp_x,tmp_y);
		x=tmp_y;
		y=(-t1)*tmp_y+tmp_x;
		
	}
}

int main(int argc, char *argv[])
{
	int n=1;
	do
	{
		int p,e,i,d;
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if(p==-1&&e==-1&&i==-1&&d==-1)
			break;
		else
		{
			int M=28*23*33;
			int M1=28*33;
			int M2=23*33;
			int M3=23*28;

			int t1,t2,t3;
			int tmp1,tmp2,tmp3;

			Extend_Eucild(M1,23,t1,tmp1);
			Extend_Eucild(M2,28,t2,tmp2);
			Extend_Eucild(M3,33,t3,tmp3);

			while(t1<0)
				t1+=23;
			while(t2<0)
				t2+=28;
			while(t3<0)
				t3+=33;


			int output=(p*t1*M1+e*t2*M2+i*t3*M3-d+M)%M;

			if(output==0)
				output=M;

			printf("Case %d: the next triple peak occurs in %d days.\n",n++,output);
		}
	}while(1);
	
	
	return 0;
}
