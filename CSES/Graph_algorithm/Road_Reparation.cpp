#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
struct point{
	int a,b,val;
};
 
int visited[100001]; // 0 還沒走過、1 
 
vector<pair<int,int>> e[100001];
 
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
 
	vector<point> v;
	
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		
		e[x].push_back({y,w});
		e[y].push_back({x,w});
	}
	
	visited[1] = 1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int ans = 0 , ok = 1;
	
	for(int i=0;i<e[1].size();i++) pq.push(make_pair(e[1][i].second,e[1][i].first));
	
	while( pq.size() != 0 )
	{
		pair<int,int> u = pq.top();
		pq.pop();
		
		if( visited[u.second] == 1 ) continue;
		
		ans += u.first;
		visited[u.second] = 1;
		ok++;
		
		for(int i=0;i<e[u.second].size();i++)
		{
			if( visited[e[u.second][i].first] == 0 ) pq.push(make_pair(e[u.second][i].second,e[u.second][i].first));
		}
	}
	
	if( ok != n ) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}