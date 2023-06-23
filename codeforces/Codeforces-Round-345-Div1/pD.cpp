#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
int bit[800005][3],arr[400005],pos[400005],val[400005];
vector<pair<int,int>> queries[400005];
int dp1[400005],dp2[400005],dp3[400005],dp4[400005];
vector<int> a,b;
int ans[400005],x[400005],y[400005],cnt[400005],r[400005];
 
void update(int id,int idx,int val)
{
	while( idx <= 8e5 ) bit[idx][id] = max(bit[idx][id],val) , idx += ( idx & -idx );
	return;
}
int query(int id,int idx)
{
	int mx = 0;
	while( idx > 0 ) mx = max(mx,bit[idx][id]) , idx -= ( idx & -idx );
	return mx;	
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int input;
		cin >> input , a.push_back(input) , b.push_back(input);
		arr[i] = input;
	}
	
	for(int i=0;i<m;i++)
	{
		cin >> pos[i] >> val[i];
		b.push_back(val[i]);
	}
	
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++) a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
	for(int i=0;i<m;i++) val[i] = lower_bound(b.begin(),b.end(),val[i]) - b.begin() + 1;
	
	for(int i=0;i<m;i++) queries[pos[i]].push_back(make_pair(val[i],i));
	
	int now_dp_mx = 1 , lis = 0;
	
	for(int i=0;i<n;i++)
	{
		int front_dp_mx = query(1,a[i]-1);
		dp1[i] = max(now_dp_mx,front_dp_mx+1);
		dp2[i] = front_dp_mx + 1;
		
		for( auto k : queries[i+1] )
		{
			ans[k.second] = query(1,k.first-1) + 1;
			x[k.second] = query(1,k.first-1) + 1;
		}
		
		now_dp_mx = max(now_dp_mx,front_dp_mx+1);
		update(1,a[i],dp2[i]);
		
		lis = max(lis,now_dp_mx);
	}
	
	//for(int i=0;i<n;i++) cout << a[i] << " ";
	//cout << "\n";
	//for(int i=0;i<n;i++) cout << abs((int)b.size()-a[i]) + 1 << " ";
	//cout << "\n";
	
	now_dp_mx = 1;
	for(int i=n-1;i>=0;i--)
	{
		int save = a[i];
		a[i] = abs((int)b.size()-a[i]) + 1;
		int back_dp_mx = query(2,a[i]-1);
		dp3[i] = max(now_dp_mx,back_dp_mx+1);
		dp4[i] = back_dp_mx + 1;
		
		if( dp2[i] + dp4[i] - 1 == lis ) cnt[dp4[i]]++;
		
	//	cout << i << " " << a[i] << " " << dp2[i] << " " << dp4[i] << " " << cnt[dp4[i]] << "\n";
		
		for( auto k : queries[i+1] )
		{
			int num = abs((int)b.size()-k.first) + 1;
			ans[k.second] = max(ans[k.second],query(2,num-1)+1);
			y[k.second] = query(2,num-1) + 1;
		}
		
		now_dp_mx = dp3[i];
		update(2,a[i],dp4[i]);
		
		a[i] = save;
	}
	
	//cout << "\n";
	
	for(int i=0;i<n;i++)
	{
		for( auto k : queries[i+1] )
		{
		//	cout << i << " " << dp2[i] << " " << dp4[i] << "\n";
			if( dp2[i] + dp4[i] - 1 == lis ) ans[k.second] = max(lis - 1,ans[k.second]);
			else ans[k.second] = max(lis,ans[k.second]);
			
			if( dp2[i] + dp4[i] - 1 == lis && i == 0 && k.first <= a[i] ) ans[k.second] = max(lis,ans[k.second]);
			if( dp2[i] + dp4[i] - 1 == lis && i == n - 1 && k.first >= a[i] ) ans[k.second] = max(lis,ans[k.second]);
			
			if( i != 0 ) ans[k.second] = max(ans[k.second],dp1[i-1]);
			if( i != n - 1 ) ans[k.second] = max(ans[k.second],dp3[i+1]);
			
			ans[k.second] = max(ans[k.second],x[k.second]+y[k.second]-1);
			//if( cnt[dp2[i]] == 1 ) ans[k.second] = max(ans[k.second],lis-1);
			//else ans[k.second] = max(ans[k.second],lis);
			
		//	cout << i << " " << cnt[dp4[i]] << "\n";
			
			if( cnt[dp4[i]] != 1 ) ans[k.second] = max(ans[k.second],lis);
			else ans[k.second] = max(ans[k.second],lis-1);
			
		//	cout << x[k.second] << " " << y[k.second] << "\n";
			
			ans[k.second] = max(ans[k.second],x[k.second]+y[k.second]-1);
		}
	}
	
	for(int i=0;i<m;i++) cout << ans[i] << "\n";
	
	return 0;
}