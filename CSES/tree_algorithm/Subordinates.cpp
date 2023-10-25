#include <bits/stdc++.h>
 
#define int long long
 
#define Colten_AC ios_base::sync_with_stdio(false),cin.tie(0);
 
using namespace std;
 
vector <int> a[200005];
 
int dp[200005];
 
void dfs(int index)
{
	dp[index] = 1;
	
	for( auto i : a[index] )
	{
		dfs(i);
		
		dp[index] += dp[i];
	}	
}
signed main(void)
{
	Colten_AC;
	
	int n;
	
	cin >> n;
	
	for(int i=2;i<=n;i++)
	{
		int input;
		
		cin >> input;
		
		a[input].emplace_back(i);
	}
	
	dfs(1);
	
	for(int i=1;i<=n;i++) cout << dp[i] - 1 << " ";
	
	cout << "\n";
	
	return 0;
}