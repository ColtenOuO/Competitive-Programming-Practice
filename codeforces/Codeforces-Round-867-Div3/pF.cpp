#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> e[200005];
int ans = -1e9,n,k,c;
multiset<int> dp[200005];
map<pair<int,int>,int> mp;

void dfs(int idx,int last)
{
	int ok = 0;
	for( auto i : e[idx] )
	{
		if( i == last ) continue;
		dfs(i,idx);
		ok++;
		if( dp[i].size() != 0 ) dp[idx].insert( *(dp[i]).rbegin() + k ) , mp[{idx,i}] = *(dp[i]).rbegin() + k;
	}
	
	if( ok == 0 ) dp[idx].insert(0);
	
	return;
}
void dfs2(int idx,int last,int cost)
{
	int num = -1;
	if( dp[idx].size() != 0 ) num = *(dp[idx]).rbegin();
	if( num != -1 ) ans = max(ans,num-cost);
	
	//cout << idx << " " << num << "\n";
	
	for( auto i : e[idx] )
	{
		if( i == last ) continue;
		
		int mp_save = mp[{idx,i}];
		dp[idx].erase( dp[idx].find(mp[ {idx,i} ])  );
		int save = -1;
		
		if( dp[idx].size() != 0 )
		{
			save = *(dp[idx]).rbegin();
			dp[i].insert(save+k);	
			mp[{ i , idx}] = save + k;
		}
		
		dfs2(i,idx,cost+c);
		
		if( dp[idx].size() != 0 )
		{
			mp.erase({i,idx});
			dp[i].erase( dp[i].find(save+k) );
		}
		
		dp[idx].insert( mp_save );
	}
	
	return;
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n >> k >> c;
		for(int i=1;i<=n;i++) e[i].clear() , dp[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			cin >> x >> y;
			e[x].emplace_back(y) , e[y].emplace_back(x);
		}
		ans = -1e9;
		dfs(1,0);
		dfs2(1,0,0);
		
		cout << ans << "\n"; 
	}
}