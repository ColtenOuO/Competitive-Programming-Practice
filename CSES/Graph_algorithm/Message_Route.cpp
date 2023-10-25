#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
 
using namespace __gnu_pbds;
 
using namespace std;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
int visited[200005],times[200005];
 
vector<int> e[200005];
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	queue<int> q;
	q.push(1);
	visited[1] = -1;
	times[1] = 1;
	
	while( q.size() != 0 )
	{
		int u = q.front();
		q.pop();
		
		for( auto i : e[u] )
		{
			if( times[i] == 0 )
			{
				times[i] = times[u] + 1;
				visited[i] = u;
				q.push(i);
			}
		}
	}
	
	if( times[n] == 0 ) cout << "IMPOSSIBLE\n";
	else
	{
		cout << times[n] << "\n";
		int now = n;
		vector<int> ans;
		while( now != -1 )
		{
			ans.push_back(now);
			now = visited[now];
		}
		
		for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
	}
}