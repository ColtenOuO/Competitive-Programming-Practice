#include <iostream>
#include <algorithm>

#define int long long

using namespace std;
int n;
int bit[500005][5];
 
void init()
{
    for(int i=0;i<=n;i++) for(int j=0;j<=4;j++) bit[i][j] = 1e18;  
}
void update(int idx1,int idx2,int val)
{
    while( idx1 <= n ) bit[idx1][idx2] = min(bit[idx1][idx2],val), idx1 += ( idx1 & -idx1 );
}
int query(int idx1,int idx2)
{
    int total = 1e18;
    while( idx1 > 0 ) bit[idx1][idx2] = min(bit[idx1][idx2],total), idx1 -= ( idx1 & -idx1 );
    return total;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m,k,t;
    cin >> n >> m >> k >> t;
    string st;
    cin >> st;
    vector<int>a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    BIT c[5];
    for(int i=0;i<=4;i++) c[i].init();

    for(int i=1;i<=n;i++)
    {
        if( i - m <= 0 ) c[1].update(i,b[i]);
        for(int j=1;j<=k;j++)
        {
            int num = c[j-1].query(i-m);
            if( num >= 1e18 ) continue;

            num += b[i];
            c[j].update(i,num);
        }
    }

    cout << c[k].query(n) << "\n";

    return 0;
}