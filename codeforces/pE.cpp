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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        map<int,int> mp;
        bool ok = 0;
        int total = 0;
        for(int i=0;i<n;i++)
        {
            if( i % 2 == 0 ) total += a[i];
            else total -= a[i];



            if( total == 0 )
            {
                ok = 1;
             //   cout << i << "\n";
                break;
            }
            if( mp.count(total) != 0 )
            {
                ok = 1;
              //  cout << total << "\n";
                break;
            }

          //  cout << total << "\n";
            mp[total] = i;
        }

        if( ok == 1 ) cout << "YES\n";
        else cout << "NO\n";
    }
}