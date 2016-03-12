#include <cstdio>
#include <algorithm>
using namespace std;

int v[50001];
int left[50001];
int right[50001];
    
void solve()
{
    int casessize;
    scanf("%d",&casessize);
    while(casessize--){
        int size;

        scanf("%d",&size);

        for(int i=0;i<size;++i)
           scanf("%d",&v[i]);
 
    // 此时left[i] 为包含i最大子段和
    left[0] = v[0];
   
    for(int i=1;i<size;++i){
        if(left[i-1]<0)
           left[i] = v[i];
        else
            left[i] = left[i-1]+v[i];
    }

    // 此时left[i] 为i左边最大子段和
    for(int i=1;i<size;++i)
       left[i] = max(left[i],left[i-1]);

    right[size-1] = v[size-1];
    for(int j=size-2;j>=0;j--){
        if(right[j+1]<0)
            right[j] = v[j];
        else
            right[j] = right[j+1]+v[j];
    }

    for(int i=size-2;i>=0;i--)
        right[i] = max(right[i+1],right[i]);

    int res = INT_MIN;
    for(int i=1;i<size;++i){
        res = max(res,left[i-1]+right[i]);
    }
        printf("%d\n",res);
    }
}

int main()
{
    solve();
    return 0;
}