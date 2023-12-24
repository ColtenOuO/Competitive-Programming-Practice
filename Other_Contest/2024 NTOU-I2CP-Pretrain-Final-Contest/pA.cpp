#include <iostream>

#define int long long
using namespace std;

signed main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        int x,y,n;
        cin >> x >> y >> n;

        int ll = 0 , rr = n;
        while( ll <= rr )
        {
            int mid = ( ll + rr ) / 2;
            if( mid * 8 / 3 >= n ) rr = mid - 1;
            else ll = mid + 1;
        }

        int ll2 = 0 , rr2 = n;
        while( ll2 <= rr2 )
        {
            int mid = ( ll2 + rr2 ) / 2;
            if( mid * 6 / 2 >= n ) rr2 = mid - 1;
            else ll2 = mid + 1;
        }

        cout << ll2 * x + ll * y << "\n";
    }
}