#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>

#define int long long

using namespace std;
int n,bit[400005];
 
struct point{
	int f,s,idx;
};
void init(int n)
{
	for(int i=0;i<=n;i++) bit[i] = 0;
}
void update(int index,int val)
{
	while( index <= 4e5 )
	{
		bit[index] += val;
		
		index += ( index & -index );
	}
	
	return;
}
int query(int index)
{
	int total = 0;
	
	while( index > 0 )
	{
		total += bit[index];
		
		index -= ( index & -index );
	}
	
	return total;
}
 
bool cmp1(point &a,point &b)
{
	if( a.f == b.f ) return a.s > b.s;
	
	else return a.f < b.f;
}
bool cmp2(point &a,point &b)
{
	if( a.s == b.s ) return a.f > b.f;
	
	else return a.s < b.s;	
}
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if( a.first == b.first ) return a.second < b.second;
    else return a.first < b.first;
}
signed solve()
{	
	int n;
	cin >> n;
	
	vector <point> a(n);
	vector <int> b;
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i].f >> a[i].s;
		
		a[i].idx = i;
		
		b.emplace_back(a[i].f);
		b.emplace_back(a[i].s);
	}
	
	sort(b.begin(),b.end());
	
	b.resize( unique(b.begin(),b.end()) - b.begin() );
	
	for(int i=0;i<n;i++)
	{
		a[i].f = lower_bound(b.begin(),b.end(),a[i].f) - b.begin() + 1;
		a[i].s = lower_bound(b.begin(),b.end(),a[i].s) - b.begin() + 1;
	}
	
	sort(a.begin(),a.end(),cmp1);
	init(2*n);
	vector <int> ans1(n);
	
	for(int i=n-1;i>=0;i--)
	{
		int num = query(a[i].s);
		
		ans1[a[i].idx] = num;
		
		update(a[i].s,1);
	}

    int ans = 0;
	
	for(int i=0;i<n;i++) ans += ans1[i];
	cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
}