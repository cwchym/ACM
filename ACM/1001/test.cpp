#include<iostream>  
#include<string>  
using namespace std;  
  
const int size=1000;  //����λ��  
  
void mult(char* A,char* B,char* ans)  
{  
    int i,j,k;  
  
    int fract;   //��С������  
    int dot=-1;  //С����λ��  
    for(k=0;A[k]!='\0';k++)  
        if(A[k]=='.')  
            dot=k;  
    int lena=k;  
    if(dot==-1)  
        fract=0;  
    else  
        fract=lena-dot-1;  
  
    dot=-1;  
    for(k=0;B[k]!='\0';k++)  
        if(B[k]=='.')  
            dot=k;  
    int lenb=k;  
    if(dot==-1)  
        fract+=0;  
    else  
        fract+=(lenb-dot-1);  //��С������  
  
    int a[size+1]={0};  
    int b[size+1]={0};  
    int pa=0,pb=0;  
  
    /*����*/  
  
    for(i=lena-1;i>=0;i--)  
    {  
        if(A[i]=='.')  
            continue;  
        a[pa++]=A[i]-'0';  
    }  
    for(j=lenb-1;j>=0;j--)  
    {  
        if(B[j]=='.')     //��ʱɾ��С����  
            continue;  
        b[pb++]=B[j]-'0';  
    }  
  
    int c[2*size+1]={0};  
    int lenc;  
    for(pb=0;pb<lenb;pb++)  
    {  
        int w=0;  //��λ����λ�Ľ�λ  
        for(pa=0;pa<=lena;pa++)  // = Ϊ�˴������Ľ�λ  
        {  
            int temp=a[pa]*b[pb]+w;  
            w=temp/10;  
            temp=(c[pa+pb]+=temp%10);  
            c[lenc=pa+pb]=temp%10;  
            w+=temp/10;  
        }  
    }  
  
    /*���򣬵õ�û��С�����ans*/  
  
    for(pa=0,pb=lenc;pb>=0;pb--)  
        ans[pa++]=c[pb]+'0';  
    ans[pa]='\0';  
    lena=pa;  
  
     /*����С����*/  
  
    bool flag=true; //����Ƿ���Ҫɾ��С��ĩβ��0  
    if(fract==0)   //С��λ��Ϊ0���������С����  
        flag=false;  
    else if(fract<lena) //С��λ��С��ans���ȣ���ans�ڲ�����С����  
    {  
        ans[lena+1]='\0';  
        for(i=0,pa=lena;pa>0;pa--,i++)  
        {  
            if(i==fract)  
            {  
                ans[pa]='.';  
                break;  
            }  
            else  
                ans[pa]=ans[pa-1];  
        }  
                  
    }  
    else //С��λ�����ڵ���ans���ȣ���ansǰ��ǡ��λ�ò���С����  
    {  
        char temp[size+1];  
        strcpy(temp,ans);  
        ans[0]='0';  
        ans[1]='.';  
        for(int i=0;i<fract-lena;i++)  //����0  
            ans[i+2]='0';  
        for(j=i,pa=0;pa<lena;pa++)  
            ans[j++]=temp[pa];  
        ans[j]='\0';  
    }  
  
    /*ɾ��ansС��ĩβ��0*/  
  
    if(flag)  
    {  
        lena=strlen(ans);  
        pa=lena-1;  
        while(ans[pa]=='0')  
            ans[pa--]='\0';  
        if(ans[pa]=='.')   //С��ȫΪ0  
            ans[pa--]='\0';  
    }  
  
    /*ɾ��ans������ͷ��0�������ٱ���1��0*/  
  
    pa=0;  
    while(ans[pa]=='0')  //Ѱ��ans��ͷ��һ����Ϊ0��λ��  
        pa++;  
  
    if(ans[pa]=='\0')  //û��С��  
    {  
        ans[0]='0';  
        ans[1]='\0';  
    }  
    else  //��С��  
    {  
        for(i=0;ans[pa]!='\0';i++,pa++)  
            ans[i]=ans[pa];  
        ans[i]='\0';  
    }  
    return;  
}  
  
char a[size+1];  
char ans[size*size+1];  
  
int main(void)  
{  
    int b;  
    while(cin>>a>>b)  
    {  
        memset(ans,'\0',sizeof(ans));  
        ans[0]='1';  
        ans[3]='\0';  
  
        for(int i=1;i<=b;i++)  
            mult(a,ans,ans);  
  
        cout<<ans<<endl;  
    }  
    return 0;  
}  