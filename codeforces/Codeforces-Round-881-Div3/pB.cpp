#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 0 , now = 0 , total = 0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			
			if( a[i] < 0 && now == 0 ) ans++ , now = 1;
			if( a[i] > 0 ) now = 0;
			
			if( a[i] < 0 ) a[i] *= -1;
			total += a[i];
		}
		
		cout << total << " " << ans << "\n";
	}
	
	return 0;
} 