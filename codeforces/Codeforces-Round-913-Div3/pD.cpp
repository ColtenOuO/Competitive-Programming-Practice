#include <iostream>
#include <algorithm>
#include <vector>

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
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++) cin >> l[i] >> r[i];

        int ll = 0 , rr = 1e9;
        while( ll <= rr )
        {
            int mid = ( ll + rr ) / 2;
            int pos1 = 0 , pos2 = 0;
            int check = 1;
            for(int i=0;i<n;i++)
            {
                int ok = 0,new_pos1 = 1e9 , new_pos2 = 0;
                int r_left = pos1 - mid , r_right = pos2 + mid;

                if( r_left >= l[i] && r_left <= r[i] && r_right >= r[i] ) pos1 = r_left , pos2 = r[i] , ok = 1;
                if( r_left <= l[i] && r_right <= r[i] && r_right >= l[i] ) pos1 = l[i] , pos2 = r_right , ok = 1;
                if( r_left <= l[i] && r_right >= r[i] ) pos1 = l[i] , pos2 = r[i] , ok = 1;
                if( l[i] <= r_left && r[i] >= r_right ) pos1 = r_left , pos2 = r_right , ok = 1;
                if( ok == 0 )
                {
                    check = 0;
                    break;
                }
            }

            if( check == 0 ) ll = mid + 1;
            else rr = mid - 1;
        }

        cout << ll << "\n";
    }

    return 0;
}
