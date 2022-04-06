
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=109;
int wt[200];
int c[200];
int dp[1000][100000];
int func(int i, int value_left)
{
    if(value_left==0)return 0;
    if(i<0)return 1e15;
    if(dp[i][value_left]!=-1)return dp[i][value_left];
      int min_wt=func(i-1,value_left);
      if(value_left-c[i]>=0)
      min_wt=min(min_wt, func(i-1,value_left-c[i])+wt[i]);

    return dp[i][value_left]=min_wt;

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
    for(int z=1e5;z>=0;z--)
    {
        if(func(n-1, z)<=w)
        {cout<<z;
        break;}
    }
    //cout<<;
    return 0LL; }
