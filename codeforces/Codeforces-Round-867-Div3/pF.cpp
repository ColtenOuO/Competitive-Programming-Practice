#include <iostream>
#include <vector>
#define int long long

using namespace std;

vector<int> a[200005];
int dp[200005],ans = 1e9,sum = 0,cost;

void dfs1(int idx,int last)
{
    for( auto i : a[idx] )
    {
        if( i == last ) continue;
        dfs1(i,idx);

        dp[idx] += dp[i];
    }

    dp[idx]++;
    if( idx != 1 ) sum += dp[idx];
    //cout << idx << " " << dp[idx] << "\n";
}
void dfs2(int idx,int last,int c)
{
    for( auto i : a[idx] )
    {
        if( i == last ) continue;

        sum -= dp[i];
        dp[idx] -= dp[i];
        sum += dp[idx];
        
        ans = max(ans,sum-c);

        dfs2(i,idx,c+cost);

        sum -= dp[idx];
        dp[idx] += dp[i];
        sum += dp[i];
    }

    return;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--)
    {
        ans = 1e9 , sum = 0;
        int n,m;
        cin >> n >> m >> cost;
        for(int i=1;i<=n;i++) a[i].clear() , dp[i] = 0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        dfs1(1,0);
        ans = sum;
        cout << ans << "\n";
        dfs2(1,0,0);

        cout << ans << "\n";
    }
}
