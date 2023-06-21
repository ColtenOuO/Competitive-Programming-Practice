#include <iostream>
#include <vector>
#define int long long

using namespace std;

vector<int> e[200005];

int dp[200005];

void dfs(int idx,int last)
{
    int ok = 0;
    for( auto i : e[idx] )
    {
        if( i == last ) continue;
        dfs(i,idx);
        ok++;
        dp[idx] += dp[i];
    }

    if( ok == 0 ) dp[idx]++;

    return;
}
void solve(int m)
{
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        cout << dp[x] * dp[y] << "\n";
    }
}
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
        for(int i=1;i<=n;i++) e[i].clear() , dp[i] = 0;
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        int m;
        cin >> m;
        dfs(1,0);
        solve(m);
    }
}
