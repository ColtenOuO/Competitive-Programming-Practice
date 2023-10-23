#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;

char a[1001][1001];
int ok[1001][1001];
pair<int,int> save[1001][1001];

int mv_x[4] = {-1,1,0,0};
int mv_y[4] = {0,0,-1,1};
char mv[4] = {'D','U','R','L'};

bool monster_vis[1001][1001];

struct Type{
	int x,y,t;
};
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int k=1;k<=m;k++) cin >> a[i][k];
	
	int st_x = 0 , st_y = 0;
	vector<pair<int,int>> monster;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			if( a[i][k] == 'A' ) st_x = i , st_y = k;
			else if( a[i][k] == 'M' ) monster.push_back({i,k});
			
			if( a[i][k] != '#' && a[i][k] != 'M' ) ok[i][k] = 0;
		}
	}
	
	queue<Type> q;
	for( auto i : monster )
	{
		q.push({i.first,i.second,0LL});
		ok[i.first][i.second] = -1;
	}
	q.push({st_x,st_y,1});
	
	ok[st_x][st_y] = 1;
	
	while( q.size() != 0 )
	{
		Type u = q.front();
		q.pop();
		
		//cout << u.x << " " << u.y << " " << u.t << "\n";
		
		for(int i=0;i<4;i++)
		{
			int x1 = mv_x[i] + u.x , y1 = mv_y[i] + u.y;
			if( a[x1][y1] == '#' || x1 <= 0 || y1 <= 0 || x1 > n || y1 > m ) continue;
			
			if( u.t == 1 )
			{
				if( ok[x1][y1] == 0 )
				{
					ok[x1][y1] = 1, q.push({x1,y1,1});
					save[x1][y1] = {u.x,u.y};
				}
			}
			else
			{
				if( ok[x1][y1] == 0 )
				{
					ok[x1][y1] = -1;
					q.push({x1,y1,0});
					monster_vis[x1][y1] = true;
				}
				else if( a[x1][y1] != '#' && monster_vis[x1][y1] == false )
				{
					monster_vis[x1][y1] = true;
					q.push({x1,y1,0});
				}
			}
		}
	}
	
	int gg1 = 0 , gg2 = 0;
	
	for(int i=1;i<=n;i++)
	{
		if( ok[1][i] == true ) gg1 = 1 , gg2 = i;
		if( ok[i][1] == true ) gg1 = i , gg2 = 1;
	}
	for(int i=1;i<=m;i++)
	{
		if( ok[i][m] == true ) gg1 = i , gg2 = m;
		if( ok[n][i] == true ) gg1 = n , gg2 = i;
	}
	
	if( ok[gg1][gg2] == 1 && st_x != 0 )
	{
		cout << "YES\n";
		string ans = "";
		
		int now_x = gg1 , now_y = gg2;
		while( now_x != st_x || now_y != st_y )
		{
			int s_x = now_x , s_y = now_y;
			for(int i=0;i<4;i++)
			{
				if( now_x + mv_x[i] == save[now_x][now_y].first )
				{
					if( now_y + mv_y[i] == save[now_x][now_y].second )
					{
						now_x = save[s_x][s_y].first;
						now_y = save[s_x][s_y].second;
						
						ans += mv[i];
						break;	
					}
				}
			}
		}
		
		cout << ans.size() << "\n";
		for(int i=(int)ans.size()-1;i>=0;i--) cout << ans[i];
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}
	
	return 0;
}
