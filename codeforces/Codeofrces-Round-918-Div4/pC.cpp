#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>

#define int long long

using namespace std;

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
        vector<int> a(n);
        int total = 0;
        for(int i=0;i<n;i++) cin >> a[i], total += a[i];
        int u = sqrt(total);
        if( u * u == total ) cout << "YES\n";
        else cout << "NO\n";
    }
}