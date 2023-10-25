#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
vector<pair<int,int>> e[2501];
int dp[2501],vis[2501],f = 0;
stack<int> s;
vector<int> ans;
int b[2501];
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		
		e[x].push_back({y,z});
	}
	
	for(int i=1;i<=n;i++) dp[i] = 1e18;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for( auto k : e[j] )
			{
				if( dp[k.first] > dp[j] + k.second )
				{
					b[k.first] = j; 
				}
				dp[k.first] = min(dp[k.first],dp[j]+k.second);
			}
		}
	}
	
	bool ok = 1;
	int pos = -1;
	
	for(int i=1;i<=n;i++)
	{
		for( auto j : e[i] )
		{
			if( dp[j.first] > dp[i] + j.second )
			{
				int now = i;
				for(int k=0;k<n;k++) now = b[now];
				
				i = now;
				
				ans.push_back(i);
				while( b[now] != i )
				{
					ans.push_back(b[now]);
					now = b[now];
				}
				ans.push_back(i);
				ok = 0;
				break;
			}
		}
		
		if( ok == 0 ) break;
	}
	
	if( ok == 1 ) cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(int i=(int)ans.size()-1;i>=0;i--) cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
