#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
vector<int> e[200005];
 
int scc[200005];
int up[200005],dep[200005],id = 0;
bool in_stack[200005];
stack<int> s;
 
int scc_cnt = 0;
 
void dfs(int idx)
{
	up[idx] = dep[idx] = ++id;
	s.push(idx);
	in_stack[idx] = true;
	
	for( auto i : e[idx] )
	{
		if( dep[i] != 0 && in_stack[i] == false ) continue;
		
		if( dep[i] == 0 ) dfs(i);
		up[idx] = min(up[i],up[idx]);
	}
	
	if( up[idx] == dep[idx] )
	{
		int v;
		scc_cnt++;
		do
		{
			v = s.top();
			s.pop();
			in_stack[v] = false;
			
			scc[v] = scc_cnt;
				
		}while( v != idx );
		
		in_stack[idx] = false;
		scc[idx] = scc_cnt;
	}
	
	return;
}
void Tarjan_SCC(int n)
{
	for(int i=1;i<=n;i++) if( dep[i] == 0 ) dfs(i);
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
		cin >> x >> y , e[x].push_back(y);
	}
	
	Tarjan_SCC(n);
	
	cout << scc_cnt << "\n";
	for(int i=1;i<=n;i++) cout << scc[i] << " ";
	cout << "\n";
}
