#include <bits/stdc++.h>
#define int long long
 
using namespace std;

vector<pair<int,int>> e[100005];
int in[100005];

struct Type{
	int min_price,min_cnt,min_flight,max_flight;
};

Type dis[100005];

const int mod = 1e9 + 7;

void solve(int n)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0LL,1LL});
	dis[1] = { 0LL , 1LL , 0LL , 0LL };
	while( pq.size() != 0 )
	{
		auto [ w , v ] = pq.top();
		pq.pop();
		if( w > dis[v].min_price ) continue;
		for( auto i : e[v] )
		{
			if( dis[v].min_price + i.second < dis[i.first].min_price )
			{
				dis[i.first].min_price = dis[v].min_price + i.second;
				dis[i.first].min_cnt = dis[v].min_cnt;
				dis[i.first].min_flight = dis[v].min_flight + 1;
				dis[i.first].max_flight = dis[v].max_flight + 1;
				pq.push({dis[i.first].min_price,i.first});
			}
			else if( dis[v].min_price + i.second == dis[i.first].min_price )
			{
				dis[i.first].min_cnt += dis[v].min_cnt;
				dis[i.first].min_cnt %= mod;
				dis[i.first].min_flight = min(dis[i.first].min_flight,dis[v].min_flight + 1);
				dis[i.first].max_flight = max(dis[i.first].max_flight,dis[v].max_flight + 1);
			}
		}
	}
	
	return;
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		e[a].push_back({b,c});
		in[b]++;
	}
	
	for(int i=1;i<=n;i++) dis[i] = {(int)1e18,0LL,0LL,0LL};
	
	solve(n);
	
	cout << dis[n].min_price << " " << dis[n].min_cnt << " ";
	cout << dis[n].min_flight << " " << dis[n].max_flight << "\n";
	
	return 0;
}
