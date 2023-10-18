#include <bits/stdc++.h>

#define int long long

using namespace std;

int dp[301][101][101],a[101][101];

void init()
{
	for(int i=0;i<=300;i++)
	{
		for(int k=0;k<=100;k++)
		{
			for(int j=0;j<=100;j++)
			{
				dp[i][k][j] = -1e9;
			}
		}
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
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	
	init();
	
	dp[1][1][1] = a[1][1];
	
	for(int i=2;i<=n+m-1;i++)
	{
		for(int p1=1;p1<=min(i,m);p1++)
		{
			for(int p2=1;p2<=min(i,p1);p2++)
			{
				int idx1 = i - p1 + 1 , idx2 = i - p2 + 1;
				//if( idx1 > n || idx2 > n ) continue;
				if( a[idx1][p1] == -1 || a[idx2][p2] == -1 ) continue;
					
				dp[i][p1][p2] = max(dp[i][p1][p2],dp[i-1][p1-1][p2]);
				dp[i][p1][p2] = max(dp[i][p1][p2],dp[i-1][p1-1][p2-1]);
				dp[i][p1][p2] = max(dp[i][p1][p2],dp[i-1][p1][p2-1]);
				dp[i][p1][p2] = max(dp[i][p1][p2],dp[i-1][p1][p2]);
				
				dp[i][p1][p2] += a[idx1][p1];
				if( p1 != p2 ) dp[i][p1][p2] += a[idx2][p2];
			}
		}
	}
	
	if( dp[n+m-1][m][m] < 0 ) dp[n+m-1][m][m] = 0;

	cout << dp[n+m-1][m][m] << "\n";
	
	return 0;
}