#include <iostream>
#include <algorithm>
#include <vector>

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
        vector<int>a(n),cnt(100001,0),g(100001,0),s(100001,0);
        for(int i=0;i<n;i++) cin >> a[i] , cnt[a[i]]++;
        for(int i=99999;i>=0;i--) g[i] = g[i+1] + cnt[i+1];
        for(int i=1;i<=100000;i++) s[i] = s[i-1] + cnt[i-1];

        int ans = 0;

        for(int i=100000;i>=2;i--)
        {
            int total = 0;
            for(int j=1;i*j<=100000;j++)
            {
                // a < b < c
                total += s[i*j]
                // a = b < c
                // a < b = c
                // a = b = c
            }
        }
    }
}
