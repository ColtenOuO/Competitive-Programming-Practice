#include <iostream>
#include <vector>

using namespace std;

vector<int> e[200001];
int dp[200001],u[200001],ans = 0;

void dfs(int idx,int last)
{
    for( auto i : e[idx] )
    {
        if( i == last ) continue;
        dfs(i,idx);

        if( u[i] == 0 && u[idx] == 0 )
        {
            ans++;
            u[i] = 1 , u[idx] = 1;
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1,0);

    cout << ans << "\n";

    return 0;
}
