#include <stdio.h>
#include <string.h>

const int size=1000;

void Inverse(char a[],int &decimal)
{
	int i=0,j=strlen(a)-1;
	while(i<j)
	{
		char tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
		i++;j--;
	}

	bool f=false;
	for(int l=0,m=0;l<strlen(a);l++)
	{
		if(a[l]=='.')
		{
			decimal=l;
			f=true;
		}
		else
		{
			a[m]=a[l];
			m++;
		}
	}
	if(f)
		a[strlen(a)-1]='\0';
}

void multi(char a[],char b[],char ans[])//ans=a*b
{
	int dot_a,dot_b;
	Inverse(a,dot_a);
	Inverse(b,dot_b);//颠倒各个数组的顺序，并求解小数位数
	//printf("a and b is :%s,%s,%d,%d\n",a,b,dot_a,dot_b);

	int decimal=dot_a+dot_b;//求解两个数相乘的小数位数
	int data=strlen(a)+strlen(b);

	char s[2*size+1];
	memset(s,'0',data);
	s[data]='\0';

	int mulFlag;
	int addFlag;

	for(int i=0;i<strlen(b);i++)
	{
		mulFlag=0;
		addFlag=0;
		for(int j=0;j<strlen(a);j++)
		{
			int tmp_mul1=(a[j]-'0')*(b[i]-'0')+mulFlag;
			mulFlag=tmp_mul1/10;
			tmp_mul1=tmp_mul1%10;
			int tmp_mul2=(s[i+j]-'0')+tmp_mul1+addFlag;
			s[i+j]=tmp_mul2%10+'0';
			addFlag=tmp_mul2/10;
		}
		s[i+strlen(a)]+=mulFlag+addFlag;
	}

	
	memcpy(ans,s,strlen(s)+1);
	
	//printf("The ans is: %s\n",ans);
	//倒顺序
	int ii=0;
	Inverse(ans,ii);
	//printf("The ans is: %s\n",ans);
	//printf("decimal is : %d\n",decimal);
	//插入小数点
	bool flag=true;
	if(decimal==0)
		flag=false;
	else
	{
		ans[strlen(ans)+1]='\0';  
        for(int i=0,pa=strlen(ans);pa>0;pa--,i++)  
        {  
            if(i==decimal)  
            {  
                ans[pa]='.';  
                break;  
            }  
            else  
                ans[pa]=ans[pa-1];  
        }  
	}

	

	//删除小数末尾的0
	int l=strlen(ans)-1;
	if(flag)
	{
		while(ans[l]=='0')
			ans[l--]='\0';
		if(ans[l]=='.')
			ans[l]='\0';
	}
	
	
	//删除小数点开头的0
	l=0;
	while(ans[l]=='0')l++;

	if(l==strlen(ans))
	{
		ans[0]='0';
		ans[1]='\0';
	}
	else
	{
		int i;
		for(i=0;ans[l]!='\0';i++,l++)
			ans[i]=ans[l];
		ans[i]='\0';
	}
	//printf("The ans is: %s\n",ans);
}


char an[size*size+1];
char tmp[size+1];

int main(int argc, char *argv[])
{
	char a[1000];
	int d;
	while(scanf("%s %d",&a,&d)==2)
	{
		memset(an,'\0',sizeof(an));
		an[0]='1';
		an[1]='.';
		an[2]='0';
		an[3]='\0';


		
		for(int i=0;i<d;i++)
		{
			memcpy(tmp,a,strlen(a));
		multi(tmp,an,an);
			//printf("succeed\n");
		
		}
		printf("%s\n",an);
		
	}
	return 0;
}
