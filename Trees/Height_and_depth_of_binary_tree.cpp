#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<int> depth(N,0);
vector<int>height(N,0);

void dfs(int v, int par)
{	
	for(auto child: g[v])
	{
		//dpeth
		if(child==par)continue;
		depth[child]=depth[v]+1; 
		dfs(child,v);
		height[v]=max(height[v],1+height[child]);
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
		cout<<depth[i]<<" "<<height[i]<<endl;
	}
}
