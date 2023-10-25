#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
 
using namespace __gnu_pbds;
 
using namespace std;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
int dsu[200005];
 
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
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	init(n);
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		unite(x,y);
	}
	
	vector<int> last;
	for(int i=1;i<=n;i++) if( find(i) == i ) last.push_back(i);
	
	cout << last.size() - 1 << "\n";
	for(int i=1;i<last.size();i++)
	{
		cout << last[i-1] << " " << last[i] << "\n";
	}
}