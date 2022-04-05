#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<int>depth(N,0);

void dfs(int v, int par)
{
	for(auto child:g[v])
	{
		if(child==par)continue;
		depth[child]=1+depth[v];
		dfs(child,v);
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
	int max_depth_node=-1;
	int z=-1;
	for(int i=1;i<=n;i++)
	{
		if(depth[i]>z)
			{
				max_depth_node=i;
				z=depth[i];
			}
		depth[i]=0;
	}
	dfs(max_depth_node,0);
	z=-1;
	for(int i=1;i<=n;i++)
	{
	
		z=max(z,depth[i]);
	}
	cout<<z;
}