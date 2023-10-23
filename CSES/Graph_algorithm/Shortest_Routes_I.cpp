#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;

vector<pair<int,int>> e[200005];
int dis[200005];

void init(int n)
{
	for(int i=1;i<=n;i++) dis[i] = 1e18;
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		e[x].push_back({y,z});
	//	e[y].push_back({x,z});
	}
	
	init(n);
	dis[1] = 0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0LL,1LL});
	
	while( pq.size() != 0 )
	{
		pair<int,int> u = pq.top();
		pq.pop();
		
		if( dis[u.second] < u.first ) continue;
		
		for( auto i : e[u.second] )
		{
			int val = u.first + i.second;
			if( val < dis[i.first] )
			{
				dis[i.first] = val;
				pq.push({val,i.first});
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout << dis[i] << " ";
	
	return 0;
}
