#include <iostream>
#include <iomanip>
#include <sstream>
#define int long long

using namespace std;

int dp[(1<<12)],p[(1<<12)],w[(1<<12)],r[(1<<12)];
int ans[(1<<12)];

void solve()
{
    vector<int> a;
    for(int i=0;i<4;i++) a.push_back(i);
    do
    {
        int now = 0,total = 0;
        for(int i=0;i<4;i++)
        {
            if( now < r[a[i]]) now = r[a[i]] + p[a[i]], total += now * w[a[i]];
            else now += p[a[i]], total += now * w[a[i]];
            cout << a[i] << " ";
        }
        cout << "\n";
        cout << total << "\n";
    }while(next_permutation(a.begin(),a.end()));
}
signed main()
{
    int n;
    cin >> n;
    for(int i=0;i<(1<<n);i++) dp[i] = 1e18,ans[i] = 1e18;
    for(int i=0;i<n;i++) cin >> p[i] >> r[i] >> w[i];
    solve();
    dp[0] = 0;
    ans[0] = 0;

    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if( ( ( 1 << j ) & i ) != 0 )
            {
                int idx = ( i ^ ( 1 << j ) );
                int num = dp[idx],add = 0;
                if( num < r[j] ) add = r[j] - num;

                int finish = add + num + p[j];
                finish *= w[j];

                dp[i] = min(dp[i],add+num+p[j]);
                ans[i] = min(ans[i],ans[idx]+finish);
            }
        }

        cout << dp[i] << "\n";
    }

    cout << ans[(1<<n)-1] << "\n";

    return 0;
}
