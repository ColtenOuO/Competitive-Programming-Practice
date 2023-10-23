#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int dp[2501];
vector<pair<int,int>> e[2501],e2[2501];
bool vis1[2501],vis2[2501];

void dfs1(int idx)
{
	for( auto i : e[idx] )
	{
		if( vis1[i.first] == 0 ) vis1[i.first] = 1 , dfs1(i.first);
	}
	
	return;
}
void dfs2(int idx)
{
	for( auto i : e2[idx] )
	{
		if( vis2[i.first] == 0 ) vis2[i.first] = 1 , dfs2(i.first);
	}
	
	return;
}

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		dp[i] = -1e18;
	}
	
	dp[1] = 0;
	
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		
		e[x].push_back({y,z});
		e2[y].push_back({x,z});
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for( auto j : e[k] )
			{
				dp[j.first] = max(dp[j.first],j.second+dp[k]);
			}
		}
	}
	
	vis1[1] = vis2[n] = 1;
	
	dfs1(1) , dfs2(n);
	
	bool ok = 1;
	for(int k=1;k<=n;k++)
	{
		for( auto j : e[k] )
		{
			if( dp[j.first] < j.second + dp[k] )
			{
				if( vis1[k] == 1 && vis2[k] == 1 ) ok = 0;
			}
			
			dp[j.first] = max(dp[j.first],j.second+dp[k]);
		}
	}	
	
//	cout << dp[1] << "\n";
	
	if( ok == 0 ) cout << -1 << "\n";
	else cout << dp[n] << "\n";
	
	return 0;
}