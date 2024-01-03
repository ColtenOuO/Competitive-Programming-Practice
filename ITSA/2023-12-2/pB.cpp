#include <iostream>
#define int long long
using namespace std;

signed main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int ok = 0,mx = 0;
        if( a >= 60 ) ok++;
        if( b >= 60 ) ok++;
        if( c >= 60 ) ok++;
        mx = max(max(a,b),c);
        if( a >= 60 && b >= 60 && c >= 60 ) cout << "P\n";
        else if( ok == 2 && a + b + c >= 220 ) cout << "P\n";
        else if( ( ok != 3 && mx >= 80 ) || ok == 2 ) cout << "M\n";
        else cout << "F\n";
    }
}