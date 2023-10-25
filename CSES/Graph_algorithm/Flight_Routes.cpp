#include <bits/stdc++.h>
#define int long long
 
using namespace std;

vector<int> dis[100005];
vector<pair<int,int>> e[100005];

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		e[a].push_back(make_pair(b,c));
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	while( pq.size() != 0 )
	{
		pair<int,int> v = pq.top();
		pq.pop();
		
		if( dis[v.second].size() == k ) continue;
		dis[v.second].push_back(v.first);
		
		for( auto i : e[v.second] )
		{
			pq.push({i.second+v.first,i.first});
		}
	}
	
	for( auto i : dis[n] ) cout << i << " ";
	
	return 0;
}
