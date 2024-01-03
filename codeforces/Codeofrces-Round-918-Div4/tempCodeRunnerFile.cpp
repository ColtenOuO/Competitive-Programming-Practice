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
        map<char,int> mp;
        char a[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin >> a[i][j];
                if( mp.count(a[i][j]) == 0 ) mp[a[i][j]] = 0;
                mp[a[i][j]] += 1;
            }
        }

        for( auto i : mp ) if( i.second != 3 && i.first != '?' ) cout << i.first << "\n";
    }
}
