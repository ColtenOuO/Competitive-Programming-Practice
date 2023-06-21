#include <bits/stdc++.h>

#define int long long

using namespace std;

int dp[601][601],e[601][601],ans[605][605];
vector<pair<int,int>> u[10005];

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int k=1;k<=n;k++) dp[i][k] = e[i][k] = 1e18 , dp[i][i] = 0;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		dp[x][y] = dp[y][x] = z;
		e[x][y] = e[y][x] = z;
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
	
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		u[a].push_back(make_pair(b,c));
		u[b].push_back(make_pair(a,c));
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int v=1;v<=n;v++)
		{		
			int mx = -1;
			for( auto t : u[v] )
			{
				mx = max(mx,t.second-dp[t.first][i]);
			}
			
			if( mx == -1 ) continue;
			for(int j=i+1;j<=n;j++)
			{
				if( e[i][j] + dp[j][v] <= mx ) ans[i][j] = 1;
			}
		}
	}
	
	int total = 0;
	for(int i=1;i<=n;i++)
	{
		for(int k=i+1;k<=n;k++) if( ans[i][k] == 1 ) total++;
	}
	
	cout << total << "\n";
	
	return 0;
} 