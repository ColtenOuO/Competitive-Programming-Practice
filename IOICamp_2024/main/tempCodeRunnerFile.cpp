#include <iostream>
#include <vector>
#include <stack>
#define int long long

using namespace std;

vector<pair<int,int> > e[200005];
int vis[200005],p[500005];
stack<pair<int,int> > s;
int ok = 1;
void dfs(int idx,int last)
{
   // cout << idx << "\n";
    if( ok == 0 ) return;
    for( auto i : e[idx] )
    {
        if( ok == 0 ) return;
        if( i.first == last ) continue;
        else
        {
            if( vis[i.first] == 0  )
            {
                s.push(make_pair(idx,i.second));
                vis[i.first] = 1;
                dfs(i.first,idx);
                s.pop();
            }
            else if( p[i.second] != 0 ) continue;
            else
            {
                vector<pair<int, int> > arr;
                while( s.size() != 0 )
                {
                    auto &[v, id] = s.top();
                    arr.push_back(s.top());
                    s.pop();

           //         cout << idx << " " << v << " " << id << " " << p[id] << " " << i.first << " " << i.second << "owo\n";

                    p[id]++;
                    if( p[id] == 2 ) ok = 0;

                    if( v == i.first || ok == 0 ) break; 
                }
                p[i.second] = 1;
                if( ok == 0 ) return;
                for( auto j : arr ) s.push(j);
            }
        }
    }

    if( ok == 0 ) return;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        e[x].push_back(make_pair(y,i));
        e[y].push_back(make_pair(x,i));
    }

    vis[1] = 1;
    dfs(1,1);

   // for(int i=1;i<=n;i++) cout << p[i] << " ";
    //cout << "\n";

    if( ok == 1 ) cout << "Yes\n";
    else cout << "No\n";
}