#include <iostream>
#include <vector>
#include <set>

#define int long long

using namespace std;

int a[200005],b[200005],c[200005];

struct Function{
    int idx,k_val,f_val;
};

struct cmp{
    bool operator()(const Function &a,const Function &b)
    {
        return a.f_val > b.f_val;
    }
};
int f(int idx,int x)
{
    return a[idx] * x * x + b[idx] * x + c[idx];
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];

    set<Function,cmp> s1,s2;

    for(int i=1;i<n;i++)
    {
        s1.insert({i,0, f(i,0) - f(i,1)});
        s2.insert({i,0, f(i,0) - f(i,-1)});
    }

    s1.insert({0,k, f(0,k) - f(0,k+1)});
    s2.insert({0,k, f(0,k) - f(0,k-1)});

    int ans = f(0,k);

    while(1)
    {
        auto it1 = --s1.end();
        auto it2 = --s2.end();

        Function tmp1 = *it1 , tmp2 = *it2;

        if( it2 -> idx == it1 -> idx ) it2--;

        if( ( it1 -> f_val ) + ( it2 -> f_val ) > 0 )
        {
            ans -= ( it1 -> f_val ) + ( it2 -> f_val );

            s1.insert( { it1 -> idx , ( it1 -> k_val ) + 1 , f(it1->idx,(it1->k_val)+2) } );
            s2.insert( { it2 -> idx , ( it2 -> k_val ) - 1 , f(it2->idx,(it2->k_val)-2) } );
        }
        else break;

        s1.erase(tmp1) , s2.erase(tmp2);
    }

    cout << ans << "\n";

    return 0;
}
