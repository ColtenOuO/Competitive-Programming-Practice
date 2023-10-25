#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int dp[200005][21],dep[200005];
 
vector <int> a[200005];
 
void dfs(int last,int point)
{
	for( auto i : a[point] )
	{
		if( i == last ) continue;
		
		dep[i] = dep[point] + 1;
		
		dp[i][0] = point;
		
		dfs(point,i);
	}
	
	return;
} 
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,q;
	
	cin >> n >> q;
	
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		
		cin >> x >> y;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	dep[1] = 1;
	
	dfs(-1,1);
	
	for(int i=1;i<=20;i++)
	{
		for(int k=1;k<=n;k++)
		{
			dp[k][i] = dp[dp[k][i-1]][i-1];
		}
	}
	
	while(q--)
	{
		int x,y;
		
		int x_s,y_s;
		
		cin >> x >> y;
		
		x_s = x , y_s = y;
		
		if( dep[x] < dep[y] ) swap(x,y);
		
		for(int i=20;i>=0;i--)
		{
			if( dep[dp[x][i]] >= dep[y] ) x = dp[x][i];
		}
		
		if( x == y )
		{
			int lca = x;
			
			cout << abs( dep[lca] - dep[x_s] ) + abs( dep[lca] - dep[y_s] ) << "\n";  
		}
		else
		{
			for(int i=20;i>=0;i--)
			{
				if( dp[x][i] != dp[y][i] )
				{
					x = dp[x][i];
					y = dp[y][i];
				}
			}
			
			int lca = dp[x][0];
			
			cout << ( dep[x_s] - dep[lca] ) + ( dep[y_s] - dep[lca] ) << "\n";
		}
	}
	
	return 0;
}