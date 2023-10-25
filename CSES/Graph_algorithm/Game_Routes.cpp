#include <bits/stdc++.h>
#define int long long
 
using namespace std;

vector<int> e[100005];
int in[100005],dis[100005];

const int mod = 1e9 + 7;

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		e[a].push_back(b);
		in[b]++;
	}	

	queue<int> q;	
	
	for(int i=2;i<=n-1;i++)
	{
		if( in[i] == 0 ) q.push(i);
	}
	
	while( q.size() != 0 )
	{
		int v = q.front();
		q.pop();
		for( auto i : e[v] )
		{
			in[i]--;
			if( in[i] == 0 && i != n && i != 1 ) q.push(i);
		}
	}
	
	q.push(1);
	dis[1] = 1;
	while( q.size() != 0 )
	{
		int v = q.front();
		q.pop();
		
		for( auto i : e[v] )
		{
			in[i]--;
			dis[i] += dis[v];
			dis[i] %= mod;
			
			if( in[i] == 0 ) q.push(i);
		}
	}
	
	cout << dis[n] << "\n";
	
	return 0;
}
