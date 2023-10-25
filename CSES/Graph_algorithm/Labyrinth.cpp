#include <bits/stdc++.h>
 
#define int long long
 
#define Colten_AC ios_base::sync_with_stdio(false),cin.tie(0);
 
using namespace std;
 
char a[1005][1005];
 
int m_x[4] = {0,0,-1,1};
int m_y[4] = {1,-1,0,0};
 
char check[4] = {'R','L','U','D'}; 
 
int sp1[4] = {0,0,1,-1}; // reverse
int sp2[4] = {-1,1,0,0};
 
signed main(void)
{
	Colten_AC;
	
	int n,m;
	
	cin >> n >> m;
	
	int s1,s2;
	
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=m;k++)
		{
			cin >> a[i][k];
			
			if( a[i][k] == 'A' ) s1 = i,s2 = k;
		}
	}
	
	queue <pair<int,int>> q;
	
	q.push({s1,s2});
	
	while(q.size() != 0)
	{
		int u1 = q.front().first , u2 = q.front().second;
		
		for(int i=0;i<4;i++)
		{
			int u3 = u1 + m_x[i] , u4 = u2 + m_y[i];
			
			if( a[u3][u4] == '.' )
			{
				q.push({u3,u4});
				
				a[u3][u4] = check[i];
			}
			else if( a[u3][u4] == 'B' )
			{
				a[u3][u4] = check[i];
				
				string s = "";
				
				while( a[u3][u4] != 'A' )
				{	
					for(int k=0;k<4;k++)
					{
						if( check[k] == a[u3][u4] )
						{
							s += check[k];
							
							u3 += sp1[k] , u4 += sp2[k];
							
							break;
						}
					}
				}
				
				reverse(s.begin(),s.end());
				
				cout << "YES\n";
				
				cout << s.size() << "\n";
				
				cout << s << "\n";
				
				return 0;
			}
		}
		
		q.pop();
	}
	
	cout << "NO\n";
	
	return 0;
}
