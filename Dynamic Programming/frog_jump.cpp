#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//vector<vector<string>> res;
int h[N];
int dp[N];
 
int func(int n)//n cost of nth rock
{	
	if(n==0)return 0 ;
	if(dp[n]!=-1) return dp[n];
	int cost =INT_MAX;
 
	cost=min(cost, func(n-1)+abs(h[n]-h[n-1]));
	if(n>1)
	cost=min(cost,func(n-2)+abs(h[n]-h[n-2]));
  return dp[n]=cost;
}
 
 
int main(){
  int n;
  cin >> n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
  {
  	cin>>h[i];
  }
  cout<<func(n-1);
}
