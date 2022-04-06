#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e7;
vector<int>g[N];
vector<bool>vis(N,false);
vector<int>level(N);
void bfs(int v)
{
	queue<int> q;
	q.push(v);
	vis[v]=true;
	while(q.empty()==false)
	{
		int curr=q.front();
		q.pop();
		cout<<curr<<" ";
		for(auto child: g[curr])
		{
			if(!vis[child])
			{
				q.push(child);
				vis[child]=true;
				level[child]=level[curr]+1;
			}
		}
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
	//dfs(1,0);
	bfs(1);
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" : "<<level[i]<<endl;
	}

	
}