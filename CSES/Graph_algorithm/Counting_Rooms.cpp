#include <bits/stdc++.h>
 
#define int long long
 
#define Colten_AC ios_base::sync_with_stdio(false),cin.tie(0);
 
using namespace std;
 
char a[1005][1005];
 
int m_x[4] = {1,-1,0,0};
int m_y[4] = {0,0,1,-1};
 
int n,m,ans;
 
void bfs(int x,int y)
{
	queue <pair<int,int>> q;
	
	q.push({x,y});
	
	a[x][y] = '#';
	
	while(q.size() != 0)
	{
		int u1 = q.front().first , u2 = q.front().second;
		
		for(int i=0;i<4;i++)
		{
			if( a[u1+m_x[i]][u2+m_y[i]] == '.' )
			{
				q.push({u1+m_x[i],u2+m_y[i]});
				
				a[u1+m_x[i]][u2+m_y[i]] = '#';
			}
		}
		
		q.pop();
	}
	
	return;
}
signed main(void)
{
	Colten_AC;
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			cin >> a[i][k];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			if( a[i][k] == '.' )
			{
				bfs(i,k);
				
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}