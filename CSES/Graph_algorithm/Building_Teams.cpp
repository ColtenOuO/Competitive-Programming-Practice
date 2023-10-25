#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
 
using namespace __gnu_pbds;
 
using namespace std;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
int c[200005];
 
vector<int> e[200005];
 
bool ok = 1;
 
void dfs(int idx,int color)
{
	c[idx] = color;
	for( auto i : e[idx] )
	{
		if( c[i] == 0 )
		{
			if( c[idx] == 1 ) dfs(i,2);
			else dfs(i,1);
		}
		else if( c[i] == c[idx] ) ok = 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	for(int i=1;i<=n;i++)
	{
		if( c[i] == 0 )
		{
			c[i] = 1;
			dfs(i,1);
		}
	}
	
	if( ok == 0 ) cout << "IMPOSSIBLE\n";
	else for(int i=1;i<=n;i++) cout << c[i] << " ";
}