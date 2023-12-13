#include <bits/stdc++.h>
#define int long long
 
using namespace std;

int dp[501][501];

int solve(int n,int m)
{
	if( n == m )
	{
		return 0;
	}
	
	if( dp[n][m] != 1e18 ) return dp[n][m];
	
	for(int i=1;i<=n;i++)
	{
		if( n - i != 0 ) dp[n][m] = min( dp[n][m] , solve(i,m) + solve(n-i,m) + 1 );
	}
	for(int i=1;i<=m;i++)
	{
		if( m - i != 0 ) dp[n][m] = min( dp[n][m] , solve(n,i) + solve(n,m-i) + 1 );
	}
	
	return dp[n][m];
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int k=1;k<=m;k++) dp[i][k] = 1e18;
	cout << solve(n,m) << "\n";
	
	return 0;
}
