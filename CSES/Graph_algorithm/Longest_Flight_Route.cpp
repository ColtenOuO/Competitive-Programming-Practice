#include <bits/stdc++.h>
#define int long long
 
using namespace std;

vector<int> e[100005];
int in[100005],bk[100005],dis[100005];

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
	
	vector<int> a;
	for(int i=1;i<=n;i++) a.push_back(i);
	
	queue<int> q;
	for(int i=2;i<=n-1;i++) if( in[i] == 0 ) q.push(i);
	while( q.size() != 0 )
	{
		int v = q.front();
		q.pop();
		for( auto i : e[v] )
		{
			in[i]--;
			if( in[i] == 0 && i != 1 && i != n ) q.push(i);
		}	
	}
	
	q.push(1);
	dis[1] = 1;
	bk[1] = 0;
	while( q.size() != 0 )
	{
		int v = q.front();
		q.pop();
		
		for( auto i : e[v] )
		{
			in[i]--;
			if( dis[i] < dis[v] + 1 )
			{
				dis[i] = dis[v] + 1;
				bk[i] = v;
			}
			
			if( in[i] == 0 ) q.push(i);
		}
	}
	
	if( dis[n] == 0 ) cout << "IMPOSSIBLE\n";
	else
	{
		cout << dis[n] << "\n";
		vector<int> ans;
		int now = n;
		ans.push_back(n);
		while( bk[now] != 0 ) ans.push_back(bk[now]) , now = bk[now];
		for(int i=(int)ans.size()-1;i>=0;i--) cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
