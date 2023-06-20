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
		
		int ans = 0;
		while( n != 1 )
		{
			ans += n;
			n /= 2;
		}
		
		cout << ans + 1 << "\n";
	}
	
	return 0;
} 