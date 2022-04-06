#include <bits/stdc++.h>
using namespace std;
#define int long long 
int vis[8][8];
int level[8][8];
int INF=1e9+10;

int xcoor(string s)
{
	return s[0]-'a';
}
int ycoor(string s)
{
	return s[1]-'1';
}
bool is_valid(int x, int y)
{
	return x<8 && y<8 &&x>=0 &&y>=0;
}
vector<pair<int,int>>moves=
{
	{2,1},{2,-1},
	{-2,1},{2,-1},
	{-1,-2},{1,-2},
	{-1,2},{1,2}

};

int bfs(string s, string d)
{
	int x_s=xcoor(s);
	int y_s=ycoor(s);
	int x_d=xcoor(d);
	int y_d=ycoor(d);
	queue<pair<int,int>>q;
	q.push({x_s,y_s});
	vis[x_s][y_s]=1;
	level[x_s][y_s]=0;
	while(!q.empty())
	{
		pair<int,int>curr=q.front();
		int x=curr.first;
		int y=curr.second;
		q.pop();
		for(auto child: moves)
		{
			int c_x=x+child.first;
			int c_y=y+child.second;
			if(!is_valid(c_x,c_y)) continue;
			if(!vis[c_x][c_y])
			{
				q.push({c_x,c_y});
				level[c_x][c_y]=level[x][y]+1;
				vis[c_x][c_y]=1;
				
			}	
		}
		if(level[x_d][y_d]!=INF)break;


	}
	return level[x_d][y_d];

}
void reset()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			vis[i][j]=0;
			level[i][j]=INF;
		}
	}
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		reset();
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
		
	}
	
}
