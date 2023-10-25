#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int in[100005],out[100005];
 
vector <int> a[100005];
 
bitset <100005> visited;
 
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
		
		a[x].push_back(y);
		
		out[x]++;
		
		in[y]++;
	}
	
	queue <int> q;
	
	vector <int> ans;
	
	for(int i=1;i<=n;i++)
	{
		if( in[i] == 0 ) q.push(i) , ans.push_back(i);
	}
	
	while( q.size() != 0 )
	{
		int u = q.front();
		
		q.pop();
		
		for( auto i : a[u] )
		{
			in[i]--;
			
			if( in[i] == 0 ) q.push(i) , ans.push_back(i);
		}
	}
	
	if( ans.size() != n ) cout << "IMPOSSIBLE\n";
	
	else for( auto i : ans ) cout << i << " ";
	
	return 0;
}
