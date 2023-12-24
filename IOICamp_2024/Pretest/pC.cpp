#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<int> a(n),cnt(1000001,0),p(10000001,0);
    for(int i=0;i<n;i++) cin >> a[i] , cnt[a[i]]++;
    for(int i=1;i<=1000000;i++) p[i] = p[i-1] + cnt[i];

    int ans = 0;
    for(int i=k;i<=1000000;i++)
    {
        int total = 0;
        for(int j=1;i*j<=1000000;j++)
        {
            int r = min(1000000LL,i*(j+1)-1);
            total += (p[r] - p[i*j-1]) * j * i;
        }

        ans = max(ans,total);
    }

    cout << ans << "\n";

    return 0;
}