#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

vector<int> e[2501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ans = 1e9;
    
    for(int i=1;i<=n;i++)
    {
        vector<int>vis(n+1,0);
        vis[i] = 1;
        queue<pair<int,int> > q;
        q.push(make_pair(i,i));
        while( q.size() != 0 )
        {
            int idx = q.front().first , last = q.front().second;
            q.pop();
            for( auto k : e[idx] )
            {
                if( k == last ) continue;
              //  bool debug = ( vis[k] == 0 );
                if( vis[k] == 0 ) q.push(make_pair(k,idx)) , vis[k] = vis[idx] + 1;
                else if( vis[idx] >= vis[k] ) ans = min(ans,vis[idx]+vis[k]-1);
               // cout << debug << "\n";
                //if(debug == 0 &&  vis[idx] >= vis[k] ) cout << idx << " " << k << " " << vis[idx] << " " << vis[k] << " i = " << i << "\n";
            }
        }
    }

    if( ans == 1e9 ) ans = -1;
    cout << ans << "\n";

    return 0;
}
