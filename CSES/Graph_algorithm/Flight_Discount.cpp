#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
vector <pair<int,int>> a[200005];
 
int dis[200005];
 
bitset <200005> visited;
 
signed main(void)
{
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	
	int n,m;
	
	cin >> n >> m;
	
	while(m--)
	{
		int u,v,w;
		
		cin >> u >> v >> w;
		
		a[u].push_back({v,w});
		
		a[u].push_back({v+n,w/2});
		
		a[u+n].push_back({v+n,w});
	}
	
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	fill(dis,dis+200005,1e18);
	
	dis[1] = 0;
	
	pq.push({0,1});
	
	while( pq.size() != 0 )
	{
		int point = pq.top().second;
		
		int money = pq.top().first;
		
		if( money > dis[point] )
		{
			pq.pop();
			
			continue;
		}
		
		pq.pop();
		
		visited[point] = 1;
		
		for( auto i : a[point] )
		{
			if( visited[i.first] == 0 )
			{
				if( money + i.second < dis[i.first] )
				{
					dis[i.first] = money + i.second;
					
					pq.push({dis[i.first],i.first});	
				}		
			}
		}
	}
	
	cout << dis[n+n] << "\n";
}