#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> e1[200005],e2[200005];
bool ok1[200005],ok2[200005];

void dfs1(int idx)
{
	for( auto i : e1[idx] )
	{
		if( ok1[i] == false ) ok1[i] = true , dfs1(i);
	}
	
	return;
}
void dfs2(int idx)
{
	for( auto i : e2[idx] )
	{
		if( ok2[i] == false ) ok2[i] = true , dfs2(i);
	}
}
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
		e1[x].push_back(y);
		e2[y].push_back(x);
	}
	
	ok1[1] = true , ok2[1] = true;
	dfs1(1) , dfs2(1);
	
	int pos = -1;
	
	for(int i=2;i<=n;i++)
	{
		if( ok1[i] == false || ok2[i] == false )
		{
			if( ok1[i] == false ) cout << "NO\n" << 1 << " " << i << "\n";
			else cout << "NO\n" << i << " " << 1 << "\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}