#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

#define int long long

using namespace std;

int dp[1001][201],u[1001][201],cnt[1001][201];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,c;
    cin >> n >> m >> a >> c;
    vector<int> d(n+1);
    for(int i=1;i<=n;i++) cin >> d[i];

    for(int i=0;i<=1000;i++) for(int j=0;j<=200;j++) dp[i][j] = 1e15;
    dp[0][0] = 0;

    int ans = 1e15;

    for(int i=1;i<=n;i++)
    {
        for(int j=d[i];j<=200;j++) // 第 i 天有 j 台腳踏車
        {
            for(int k=0;k<=200;k++) // 前一天還有 k 台
            {
                if( k > j ) break;

                int need = j - k;
                int cost = 0;

                if( need > m ) cost += ( need - m ) * c;

                if( dp[i][j-d[i]] > dp[i-1][k]+cost+k*a ) u[i][j-d[i]] = need,cnt[i][j-d[i]] = k;
                dp[i][j-d[i]] = min(dp[i][j-d[i]],dp[i-1][k]+cost+k*a);

                if( i == n ) ans = min(ans,dp[i-1][k]+cost+k*a);
            }
        }
    }

    cout << ans << "\n";

    int idx = 0;
    vector<int> v;
    for(int i=n;i>=1;i--)
    {
        v.push_back(u[i][idx]);
        idx = cnt[i][idx];
    }

    for(int i=(int)v.size()-1;i>=0;i--) cout << v[i] << " ";
    cout << "\n";

    return 0;
}