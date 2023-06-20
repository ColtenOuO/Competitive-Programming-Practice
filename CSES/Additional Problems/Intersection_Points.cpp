#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
vector<int> in[2000005],out[2000005];
vector<pair<int,int>> q[2000005];
 
int bit[2000005];
 
void update(int idx,int val)
{
	while( idx <= 2e6 + 1 )
	{
		bit[idx] += val;
		idx += ( idx & -idx );
	}
	
	return;
}
int query(int idx)
{
	int total = 0;
	while( idx > 0 )
	{
		total += bit[idx];
		idx -= ( idx & -idx );
	}
	
	return total;
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		x1 += 1e6 , x2 += 1e6 , y1 += 1e6 , y2 += 1e6;
		
		x1++;
		y1++;
		x2++;
		y2++;
		
		if( y1 == y2 ) in[x1].push_back(y1) , out[x2+1].push_back(y1);
		else q[x1].push_back({y1,y2});
	}
	
	int ans = 0;
	
	for(int i=1;i<=2000000 + 1;i++)
	{
		for( auto k : out[i] ) update(k,-1);
		for( auto k : in[i] ) update(k,1);
		
		for( auto k : q[i] )
		{
			ans += query(k.second) - query(k.first-1);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
} 