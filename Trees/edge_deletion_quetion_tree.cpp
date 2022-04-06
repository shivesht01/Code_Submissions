#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<int>subtree(N,0);

void dfs(int v, int par)
{
	subtree[v]+=v;
	for(auto child:g[v])
	{
		if(child==par)continue;
		dfs(child,v);
		subtree[v]+=subtree[child];
	}
}
int32_t main()
{
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1,0);
	int z=subtree[1];
	pair<int,int>p(1,-1);
	for(int i=2;i<=n;i++)
	{
		int x=subtree[i]*(z-subtree[i]);
		p.first=max(p.first,subtree[i]*(z-subtree[i]));
		if(x==p.first)p.second=i;
	}
	cout<<p.first<<" "<<p.second;
	
}