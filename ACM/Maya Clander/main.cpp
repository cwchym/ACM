#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "string.h"

using namespace std;



int main(int argc, char *argv[])
{
    char H[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", 
    "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    char T[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", 
    "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    
    int day,year;
    char month[10];
    
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    
    for(int i=0;i<n;i++)
    {
            int j=0;
            scanf("%d. %s %d\n",&day,month,&year);
            for(;j<19;j++)
                    if(!strcmp(month,H[j])) break; 
            int sum=year*365+day+j*20;
            printf("%d %s %d\n",sum%13+1,T[sum%20],sum/260);            
    }
//    system("pause");
    return 0;
}
