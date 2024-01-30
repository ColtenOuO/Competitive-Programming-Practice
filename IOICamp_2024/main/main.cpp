#include <iostream>
using namespace std;

#define int long long

struct BIT{
    int bit[500005];
    BIT(int n)
    {
        for(int i=1;i<=n;i++) bit[i] = 0;
    }
    void update(int idx,int val)
    {
        while( idx <= 5e5 ) bit[idx] += val, idx += ( idx & -idx );
    }
    int query(int idx)
    {
        int total = 0;
        while( idx > 0 ) total += bit[idx], idx -= ( idx & -idx );
        return total;
    }
};
int a[500005];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    BIT bit1(n),bit2(n);
    for(int i=1;i<=n;i++) cin >> a[i], bit1.update(i,a[i]), bit2.update(i,a[i]*a[i]);

    int q;
    cin >> q;
    while(q--)
    {
        int opt,l,r;
        cin >> opt >> l >> r;
        if( opt == 1 )
        {
            bit1.update(l,-a[l]), bit1.update(l,r);
            bit2.update(l,-(a[l]*a[l])), bit2.update(l,r*r);
            a[l] = r;
        }
        else
        {
            int num1 = ( bit1.query(r) - bit1.query(l-1) );
            num1 *= num1;
            int num2 = bit2.query(r) - bit2.query(l-1);

            cout << ( num1 - num2 ) / 2 << "\n";
        }
    }

    return 0;
}