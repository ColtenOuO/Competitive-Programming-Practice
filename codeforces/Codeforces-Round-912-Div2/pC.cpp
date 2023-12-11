#include <iostream>
#include <algorithm>
#include <vector>

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
        vector<int>a(n);

        int total = 0;
        for(int i=0;i<n;i++) cin >> a[i] , total += a[i];

        int sum = 0, ans = total;
        for(int i=n-1;i>=1;i--)
        {
            sum += a[i];
            if( sum > 0 ) ans += sum;
        }

        cout << ans << "\n";
    }

    return 0;
}
