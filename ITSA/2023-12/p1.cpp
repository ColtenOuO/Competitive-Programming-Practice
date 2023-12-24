#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        int s,m,k,d;
        cin >> s >> k >> m >> d;
        int ans = s;
        for(int i=1;i<=d;i++)
        {
            if( i <= m ) ans += k;
            else ans += ( k + 5 );
        }

        cout << ans << "\n";
    }
}