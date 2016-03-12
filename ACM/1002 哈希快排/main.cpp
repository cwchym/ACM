#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <memory>
#include <iomanip>

using namespace std;

int change(char a){
    switch(a){
           case '1':return 1;
           case '2':;case 'A':;case 'B':;case 'C':return 2;
           case '3':;case 'D':;case 'E':;case 'F':return 3;
           case '4':;case 'G':;case 'H':;case 'I':return 4;
           case '5':;case 'J':;case 'K':;case 'L':return 5;
           case '6':;case 'M':;case 'N':;case 'O':return 6;
           case '7':;case 'P':;case 'R':;case 'S':return 7;
           case '8':;case 'T':;case 'U':;case 'V':return 8;
           case '9':;case 'W':;case 'X':;case 'Y':return 9;
           default: return 0;
           } 
}

void quick_sort(int s[],int l,int r)//øÏ≈≈ 
{
    int i=l,j=r,x=s[l];
    if(i<j)
    {
           while(i<j)
           {
                     while(i<j&&s[j]>=x)
                                        j--;
                     if(i<j)
                            s[i++]=s[j];
                     
                     while(i<j&&s[i]<=x)
                                        i++;
                     if(i<j)
                            s[j--]=s[i];                
           }
           s[i]=x;
           quick_sort(s,l,i-1);
           quick_sort(s,i+1,r);
    }
}

int hash[10000000];
bool vist[10000000];
int sort_num[100000];

int main(int argc, char *argv[])
{
    int num;
    int sort_p=0;
    bool flag=false;
    
    memset(hash,0,sizeof(hash));
    memset(vist,false,sizeof(vist));
    
    scanf("%d\n",&num);
    
    for(int j=num;j>0;j--)
    {
                     int x=0;
                     
                     char s[200];
                     scanf("%s",&s);
                     for(int i=0;s[i]!='\0';i++)
                     {
                             if(s[i]=='-'||s[i]=='Q'||s[i]=='Z')
                             continue;
                             else
                             {
                                x=x*10+change(s[i]); 
                             }        
                     }
                     
                     hash[x]++;
                     
                     if(!vist[x]&& hash[x]>1)
                     {
                                  flag=true;
                                  sort_num[sort_p++]=x;           
                                  vist[x]=true;
                     }
					 
    }
    
    if(!flag)
                 printf("No duplicates.\n");
    else
    {
        quick_sort(sort_num,0,sort_p-1);
        
        for(int i=0;i<sort_p;i++)
        {
                cout<<setfill('0')<<setw(3)<<sort_num[i]/10000;  
                cout<<'-';  
                cout<<setfill('0')<<setw(4)<<sort_num[i]%10000; 
                cout<<' '<<hash[sort_num[i]]<<endl;
        }
    }             
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
