#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=109;
int wt[200];
int c[200];
int dp[310][100000];
int func(int i, int w)
{
   // cout<<i<<" -> "<<c[i]<<" * ";
    if(i<0)return 0;
    if(w==0)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    
    int sum=func(i-1, w);
    if(w-wt[i]>=0)
    sum=max(sum, func(i-1, w-wt[i])+c[i]);
    return dp[i][w]=sum;
}

int32_t main()
{
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>c[i];
    }
    cout<<func(n-1, w);
    return 0LL;
}
