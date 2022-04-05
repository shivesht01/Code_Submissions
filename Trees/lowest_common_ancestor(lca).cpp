#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<int>parent(N,0);

void dfs(int v, int par)
{
	parent[v]=par;
	for(auto child:g[v])
	{
		if(child==par)continue;
		dfs(child,v);
	}
}
vector<int>path(int z)
{
	vector<int>ans;
	while(z!=0)
	{
		ans.push_back(z);
		z=parent[z];
	}
	reverse(ans.begin(),ans.end());
	return ans;
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
	int x,y;
	cin>>x>>y;
	dfs(1,0);
	vector<int>p_x=path(x);
	vector<int>p_y=path(y);
	int m=min(p_x.size(),p_y.size());
	int lca=-1;
	for(int i=0;i<m;i++)
	{
		if(p_x[i]==p_y[i])
			lca=p_x[i];
		else break;
	}
	cout<<lca;
	
}