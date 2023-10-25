#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int dp[200005][21];
 
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
	}
	
	for(int i=1;i<=20;i++)
	{
		for(int k=1;k<=n;k++)
		{
			dp[k][i] = dp[dp[k][i-1]][i-1];
		}
	}
	
	while(q--)
	{
		int a,b;
		
		cin >> a >> b;
		
		int now = a;
		
		for(int i=0;i<=20;i++)
		{
			if( ( b & ( 1 << i ) ) != 0 ) now = dp[now][i];
		}
		
		if( now == 0 ) cout << -1 << "\n";
		
		else cout << now << "\n";
	}
