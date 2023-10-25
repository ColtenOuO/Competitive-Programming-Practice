#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int dp[200005][32];
 
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,q;
	
	cin >> n >> q;
	
	for(int i=1;i<=n;i++)
	{
		int input;
		
		cin >> input;
		
		dp[i][0] = input; // i 走 2^0
	}
	
	for(int i=1;i<=31;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
	
	while(q--)
	{
		int a,b;
		
		cin >> a >> b;
		
		vector <int> c;
		
		int point = a;
		
		for(int i=0;i<=31;i++)
		{
			if( ( b & ( 1 << i ) ) != 0 )
			{
				point = dp[point][i];
			}
		}
		
		cout << point << "\n";
	}
}