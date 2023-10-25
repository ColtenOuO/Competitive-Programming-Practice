#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
 
using namespace __gnu_pbds;
 
using namespace std;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
vector<int> e[200005];
 
int dsu[200005],ans[200005];
bitset<200005> visited;
 
bool ok = 0;
 
void init(int n)
{
	for(int i=1;i<=n;i++) dsu[i] = i;
}
int find(int idx)
{
	return dsu[idx] == idx ? idx : dsu[idx] = find(dsu[idx]);
}
void unite(int a,int b)
{
	a = find(a);
	b = find(b);
	dsu[a] = b;
}
void dfs(int idx,int last,int g,int index)
{
//	cout << idx << "\n";
	if( ok == 1 ) return;
	if( idx == g && last != g && ok == 0 )
	{
		cout << index << "\n";
		cout << g << " ";
		for(int i=1;i<index;i++) cout << ans[i] << " ";
		ok = 1;
		return;
	}
	
	for( auto i : e[idx] )
	{
		if( i != last && find(i) == find(g) )
		{
			if( visited[i] != 0 ) continue;
			visited[i] = 1;
			ans[index] = i;
			dfs(i,idx,g,index+1);
			visited[i] = 0;
		}
	}
	
	return; 
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	init(n);
	
	vector<int> x(m),y(m);
	
	for(int i=0;i<m;i++)
	{
		cin >> x[i] >> y[i];
		e[x[i]].push_back(y[i]);
		e[y[i]].push_back(x[i]);
	}
	
	for(int i=0;i<m;i++)
	{
		if( find(x[i]) != find(y[i]) ) unite(x[i],y[i]);
		else
		{
			dfs(x[i],x[i],x[i],1);
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE\n";
}