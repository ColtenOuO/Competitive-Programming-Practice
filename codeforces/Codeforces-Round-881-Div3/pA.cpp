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
		deque<int> dq;
		for(int i=0;i<n;i++)
		{
			int input;
			cin >> input;
			dq.push_back(input);
		}
		
		sort(dq.begin(),dq.end());
		
		int ans = 0;
		
		while( dq.size() > 1 )
		{
			ans += dq.back() - dq.front();
			dq.pop_front();
			dq.pop_back();
		}
		
		cout << ans << "\n";
	}
	
	return 0;
} 