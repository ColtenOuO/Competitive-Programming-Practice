#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1),b(n+1,0),c(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        b[2] = 1;
        for(int i=2;i<=n-1;i++)
        {
            if( abs(a[i]-a[i-1]) > abs(a[i]-a[i+1]) ) b[i+1] = b[i] + 1;
            else b[i+1] = b[i] + abs(a[i]-a[i+1]);
        }

        c[n-1] = 1;
        for(int i=n-1;i>=2;i--)
        {
            if( abs(a[i]-a[i-1]) < abs(a[i]-a[i+1]) ) c[i-1] = c[i] + 1;
            else c[i-1] = c[i] + abs(a[i]-a[i-1]);
        }

        int q2;
        cin >> q2;
        while(q2--)
        {
            int x,y;
            cin >> x >> y;
            if( x < y ) cout << b[y] - b[x] << "\n";
            else cout << c[y] - c[x] << "\n";


        }

        //cout << c[1] << "\n";
    }

    return 0;
}

