#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#define int long long
using namespace std;
int dp[1500001][2];
struct Fireworks{
    int a,b,t;
};
bool cmp(Fireworks &a,Fireworks &b)
{
    return a.t < b.t;
}
void init(int n)
{
    for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = -1e18;
    return;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,d;
    cin >> n >> m >> d;
    vector<Fireworks> v(m+1);
    for(int i=1;i<=m;i++) cin >> v[i].a >> v[i].b >> v[i].t;
    sort(v.begin()+1,v.end(),cmp);
    init(n);
    for(int i=1;i<=n;i++) dp[i][1] = v[1].b - abs( v[1].a - i ); 
    for(int i=2;i<=m;i++)
    {
        int window_len = abs( v[i].t - v[i-1].t ) * d;
        window_len = min(window_len,n);
        deque<pair<int,int> > dq;
        for(int j=1;j<=window_len;j++)
        {
            while( dq.size() != 0 && dp[j][(i+1)%2]-abs(j-v[i].a) >= dq.back().first ) dq.pop_back();
            dq.push_back(make_pair(dp[j][(i+1)%2]-abs(j-v[i].a),j));
        }
        for(int j=1;j<=n;j++)
        {
            if( j + window_len <= n )
            {
                while( dq.size() != 0 && dp[j+window_len][(i+1)%2]-abs(j+window_len-v[i].a) >= dq.back().first ) dq.pop_back();
                dq.push_back(make_pair(dp[j+window_len][(i+1)%2]-abs(j+window_len-v[i].a),j+window_len));
            }
            dp[j][i%2] = max(dp[j][i%2],dq.front().first+v[i].b);
            if( dq.front().second <= j ) dq.pop_front();
        }
        dq.clear();
        for(int j=n;j>n-window_len;j--)
        {
            while( dq.size() != 0 && dp[j][(i+1)%2]-abs(j-v[i].a) >= dq.back().first ) dq.pop_back();
            dq.push_back(make_pair(dp[j][(i+1)%2]-abs(j-v[i].a),j));
        }
        for(int j=n;j>=1;j--)
        {
            if( j - window_len >= 1 )
            {
                while( dq.size() != 0 && dp[j-window_len][(i+1)%2]-abs(j-window_len-v[i].a) >= dq.back().first ) dq.pop_back();
                dq.push_back(make_pair(dp[j-window_len][(i+1)%2]-abs(j-window_len-v[i].a),j-window_len));
            }
            dp[j][i%2] = max(dp[j][i%2],dq.front().first+v[i].b);
            if( dq.front().second >= j ) dq.pop_front();
        }

        for(int j=0;j<=n;j++) dp[j][(i+1)%2] = -1e18;
    }
    
    int ans = -1e18;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i][m%2]);
    
    cout << ans << "\n";

    return 0;
}