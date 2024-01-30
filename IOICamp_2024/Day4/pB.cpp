#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define int long long

using namespace std;

vector<int> e[200001];
int bit[700001],flat_tree[700001],arr_index = 1;
int l[200001],r[200001],dep[200005];
int dp[700001][30],dp2[700001][30];
void update(int idx,int val)
{
    while( idx <= 7e5 ) bit[idx] += val, idx += ( idx & -idx );
    return;
}
int query(int idx)
{
    int total = 0;
    while( idx > 0 ) total += bit[idx], idx -= ( idx & -idx );
    return total;
}
void dfs(int idx,int depth)
{
    flat_tree[arr_index++] = idx, dep[idx] = depth;
    bool leaf = true;
    for( auto i : e[idx] )
    {
        leaf = false;
        dfs(i,depth+1), flat_tree[arr_index++] = idx;
    }

    if( leaf == true ) flat_tree[arr_index++] = idx;

    return;
}
void sparse_table()
{
    for(int j=1;j<30;j++)
    {
        for(int i=1;i+(1LL<<(j-1))<arr_index;i++)
        {
            if( dp[i][j-1] <= dp[i+(1LL<<(j-1))][j-1] ) dp2[i][j] = dp2[i][j-1];
            else dp2[i][j] = dp2[i+(1LL<<(j-1))][j-1];

            dp[i][j] = min(dp[i][j-1],dp[i+(1LL<<(j-1))][j-1]);
        }
    }

    return;
}
void init()
{
    for(int i=0;i<30;i++) for(int j=1;j<arr_index;j++) dp[j][i] = 1e9;
    for(int i=1;i<arr_index;i++) r[flat_tree[i]] = i;
    for(int i=arr_index-1;i>=1;i--) l[flat_tree[i]] = i;
    for(int i=1;i<arr_index;i++) dp[i][0] = dep[flat_tree[i]], dp2[i][0] = flat_tree[i];

    sparse_table();

    return;
}
int query_lca(int l,int r)
{
    int num = __lg( r - l + 1 );
    if( dp[l][num] <= dp[r-(1<<num)+1][num] ) return dp2[l][num];
    else return dp2[r-(1<<num)+1][num];
}

int bit2[700005];
void update2(int idx,int val)
{
    while( idx <= 7e5 ) bit2[idx] += val, idx += ( idx & -idx );
    return;
}
int query2(int idx)
{
    int total = 0;
    while( idx > 0 ) total += bit2[idx], idx -= ( idx & -idx );
    return total;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=2;i<=n;i++)
    {
        int num;
        cin >> num;
        e[num].push_back(i);
    }

    dfs(1,1);
    init();

    while(q--)
    {
        int opt;
        cin >> opt;
        if( opt == 1 )
        {
            int pos,val;
            cin >> pos >> val;
            update(l[pos],val);
            update2(l[pos],val);
            update2(r[pos],-val);
        }
        else if( opt == 3 )
        {
            int v;
            cin >> v;
         //   cout << l[v] << " " << r[v] << "\n";
            cout << query(r[v]) - query(l[v]-1) << "\n";
        }
        else
        {
            int u,v;
            cin >> u >> v;
            int x = r[u], y = r[v];
            if( x > y ) swap(x,y);

            int lca = query_lca(x,y);
       //     cout << lca << "\n";
            int ans1 = query2(l[u]) - query2(l[lca]);
            int ans2 = query2(l[v]) - query2(l[lca]);

            cout << ans1 + ans2 + ( query2(l[lca]) - query2(l[lca]-1) ) << "\n";
        }
    }
}