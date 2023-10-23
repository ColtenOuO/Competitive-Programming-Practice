#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;


int dp[505][505];

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,q;
	
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++) dp[i][k] = 1e18 , dp[i][i] = 0;
	}
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		dp[a][b] = min({dp[a][b],dp[b][a],c});
		dp[b][a] = min({dp[b][a],dp[a][b],c});
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		if( dp[x][y] == 1e18 ) cout << -1 << "\n";
		else cout << dp[x][y] << "\n";
	}
	
	return 0;
}
