#include <iostream>
#include <queue>
#include<utility>
#define int long long

using namespace std;

int bit[200005];

void update(int idx,int val)
{
    while( idx <= 200000 ) bit[idx] += val , idx += ( idx & -idx );
}
int query(int idx)
{
    int total = 0;
    while( idx > 0 ) total += bit[idx] , idx -= ( idx & -idx );
    return total;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++) bit[i] = 0;
        queue<pair<int,int> > q;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            q.push(make_pair(x,y));
        }

        int c;
        cin >> c;

        vector<int> a(c);
        for(int i=0;i<c;i++) cin >> a[i] , update(a[i],1);
        int ans = -1;
        for(int i=c-1;i>=0;i--)
        {
            while( q.size() != 0 )
            {
                pair<int,int> u = q.front();
                q.pop();

                int num = query( u.second ) - query( u.first - 1 );
                if( ( u.second - u.first + 1 ) / 2 < num )
                {
                    ans = i + 1;
                    q.push(u);
                    break;
                }
            }

            update(a[i],-1);
        }

        cout << ans << "\n";
    }
}
