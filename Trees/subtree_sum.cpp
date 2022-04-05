#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<int>subtree(N,0);

void dfs(int v, int par)
{
	subtree[v]+=v;
	for(auto child: g[v])
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
	for(int i=1;i<=n;i++)
	{
		cout<<subtree[i]<<endl;
	}
}