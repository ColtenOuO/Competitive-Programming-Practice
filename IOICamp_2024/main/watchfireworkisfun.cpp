#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>

#define int long long

using namespace std;

int dp[150001][2];

struct Type{
    int a,b,t;
};
bool cmp(Type &a,Type &b)
{
    return a.t < b.t;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,d;
    cin >> n >> m >> d;
    vector<Type> v(m+1);
    for(int i=1;i<=m;i++) cin >> v[i].a >> v[i].b >> v[i].t;
    sort(v.begin()+1,v.end(),cmp);

    for(int i=1;i<=n;i++) dp[i][0] = -1e15;
    for(int i=1;i<=n;i++)
    {
        dp[i][1] = v[1].b - abs(v[1].a-i);
    }
    
    for(int i=2;i<=m;i++)
    {
        int window_len = d * ( v[i].t - v[i-1].t );
        window_len = min(window_len,n);
        deque<int> dq;
        for(int j=1;j<=window_len;j++)
        {
            while( dq.size() != 0 && dp[dq.back()][(i+1)%2] <= dp[j][(i+1)%2] ) dq.pop_back();
            dq.push_back(j);
        }
        for(int j=window_len+1;j<=n;j++)
        {
            while( dq.size() != 0 && dp[dq.back()][(i+1)%2] <= dp[j][(i+1)%2] ) dq.pop_back();
            dq.push_back(j);
            while( dq.size() != 0 && abs( ( j - window_len ) - dq.front() ) > window_len ) dq.pop_front();
           // cout << dq.size() << " " << dp[dq.front()][(i+1)%2] << " " << ( v[i].b - abs( v[i].a - dq.front() ) ) << "\n";
            dp[j-window_len][i%2] = dp[dq.front()][(i+1)%2] + ( v[i].b - abs( v[i].a - dq.front() ) );
        }
        for(int j=n-window_len+1;j<=n;j++)
        {
            while( dq.size() != 0 && abs(j - dq.front()) > window_len ) dq.pop_front();
            dp[j][i%2] = dp[dq.front()][(i+1)%2] + ( v[i].b - abs( v[i].a - dq.front() ) );
        }

        for(int j=1;j<=n;j++) dp[j][(i+1)%2] = -1e15;
    }

    int ans = -1e18;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i][m%2]);

    cout << ans << "\n";

    return 0;
}