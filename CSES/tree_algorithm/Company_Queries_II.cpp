#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int dp[200005][21],dep[200005];
 
vector <int> a[200005];
 
void dfs(int point)
{
	for( auto i : a[point] )
	{
		dep[i] = dep[point] + 1;
		
		dfs(i);
	}
	
	return;
} 
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,q;
	
	cin >> n >> q;
	
	for(int i=2;i<=n;i++)
	{
		int input;
		
		cin >> input;
		
		dp[i][0] = input;
		
		a[input].emplace_back(i);
	}
	
	dep[1] = 1;
	
	dfs(1);
	
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
		
		cin >> x >> y;
		
		if( dep[y] > dep[x] ) swap(x,y);
 
		for(int i=20;i>=0;i--)
		{
			if( dep[dp[x][i]] >= dep[y] ) x = dp[x][i];
		}
		
		if( x == y )
		{	
			cout << x << "\n";
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
			
			cout << dp[x][0] << "\n";
		}
	}
