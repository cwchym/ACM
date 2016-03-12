#include<iostream>  
using namespace std;  
  
int dis[1001];      //Դ�㵽����Ȩֵ  
const int max_w=10001;      //����Զ  
  
class weight  
{  
public:  
    int s;  
    int e;  
    int t;  
}edge[5200];  
  
int N,M,W_h; //N (1��N��500)fields ������  
             //M (1��M��2500)paths ��Ȩ˫���  
             //W_h (1��W��200) wormholes �涴�����ݣ�����Ȩ�����  
int all_e;   //�߼�����������  
  
bool bellman(void)  
{  
    bool flag;  
  
    /*relax*/  
  
    for(int i=0;i<N-1;i++)  
    {  
        flag=false;  
        for(int j=0;j<all_e;j++)  
            if(dis[edge[j].e] > dis[edge[j].s] + edge[j].t)  
            {  
                dis[edge[j].e] = dis[edge[j].s] + edge[j].t;  
                flag=true;         //relax��·���и���  
            }  
        if(!flag)     
            break;  //ֻҪĳһ��relaxû�и��£�˵�����·���Ѿ�������ϣ����߲��ֵ㲻�ɴ��������relax  
    }  
  
    /*Search Negative Circle*/  
  
    for(int k=0;k<all_e;k++)  
        if( dis[edge[k].e] > dis[edge[k].s] + edge[k].t)  
            return true;  
  
    return false;  
}  
int main(void)  
{  
    int u,v,w;  
  
    int F;  
    cin>>F;  
    while(F--)  
    {  
        memset(dis,max_w,sizeof(dis));    //Դ�㵽����ĳ�ʼֵΪ�����Ĭ�ϲ���ͨ  
  
        cin>>N>>M>>W_h;  
  
        all_e=0;      //��ʼ��ָ��  
  
        /*read in Positive Paths*/  
  
        for(int i=1;i<=M;i++)  
        {  
            cin>>u>>v>>w;  
            edge[all_e].s=edge[all_e+1].e=u;  
            edge[all_e].e=edge[all_e+1].s=v;  
            edge[all_e++].t=w;  
            edge[all_e++].t=w;               //����paths��˫���ԣ���������Ȩֵ��ȣ�ע��ָ����ƶ�  
        }  
  
        /*read in Negative Wormholds*/  
  
        for(int j=1;j<=W_h;j++)  
        {  
            cin>>u>>v>>w;  
            edge[all_e].s=u;  
            edge[all_e].e=v;  
            edge[all_e++].t=-w;     //ע��ȨֵΪ��  
        }  
  
        /*Bellman-Ford Algorithm*/  
  
        if(bellman())  
            cout<<"YES"<<endl;  
        else  
            cout<<"NO"<<endl;  
    }  
    return 0;  
} 