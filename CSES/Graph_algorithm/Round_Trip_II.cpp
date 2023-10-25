#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long // find by order , order of key
 
#define f first
 
#define s second
 
using namespace __gnu_pbds;
 
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
vector<int> e[100001];
bool visited[100001];
stack<int> q;
 
bool ok = 0;
 
bool check[100001];
 
void dfs(int idx)
{
	if( ok == 1 ) return;
	
	for( auto i : e[idx] )
	{
		if( ok == 1 ) return;	
		if( visited[i] == 1 )
		{	
			vector<int> ans;
			
			ok = 1;
			while( q.size() != 0 && q.top() != i ) ans.push_back(q.top()) , q.pop();
				
			cout << ans.size() + 2 << "\n";	
			cout << i << " ";
			for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
			cout << i << "\n";
			return;
		}
		else if( check[i] == 0 )
		{
			check[i] = 1;
			visited[i] = 1;
			q.push(i);
			dfs(i);
			q.pop();
			visited[i] = 0;
		}
		
	}
}
signed main(void)
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
	}
	
	for(int i=1;i<=n;i++)
	{
		if( check[i] == 1 || ok == 1 ) continue;
		while( q.size() != 0 ) q.pop();
		
		check[i] = 1;
		q.push(i);
		visited[i] = 1;
		dfs(i);
		visited[i] = 0;
	}
	
	if( ok == 0 ) cout << "IMPOSSIBLE" << "\n";
	
	return 0;
}