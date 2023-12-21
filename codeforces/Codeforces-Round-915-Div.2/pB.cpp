#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define int long long
using namespace std;

vector<int> e[100005];
vector<int> e2[100005];
void dfs(int idx,int last)
{
    for( auto i : e[idx] )
    {
        if( i == last ) continue;
        e2[idx].push_back(i);
        dfs(i,idx);
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
        for(int i=1;i<=n;i++) e[i].clear(),e2[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        dfs(1,-1);
        int ans = 1,total = 0;
        if( e2[1].size() > 2 ) total += ( e2[1].size() - 2 );
        for(int i=2;i<=n;i++) if( e2[i].size() > 1 ) total += ( e2[i].size() - 1 );
      //  cout << total << "\n";
        ans += total / 2 + total % 2;
        cout << ans << "\n"; 
    }
}