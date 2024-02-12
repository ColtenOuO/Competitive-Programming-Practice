#include <iostream>
#define int long long

using namespace std;

signed main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int x1,x2,y1,y2,y3,x3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        if( x1 == x2 && y1 == y2 ) cout << "YES\n";
        else if( x1 == x3 && y1 == y3 ) cout << "YES\n";
        else if( x2 == x3 && y2 == y3 ) cout << "YES\n";
        else if( ( y2 - y1 ) * ( x3 - x1 ) == ( x2 - x1 ) * ( y3 - y1 )  ) cout << "NO\n";
        else cout << "YES\n";
    }
}