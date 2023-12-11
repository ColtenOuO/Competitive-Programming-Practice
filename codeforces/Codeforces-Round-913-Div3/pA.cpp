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
        char a,b;
        cin >> a >> b;

        for(int i='a';i<='h';i++)
        {
            for(int j=1;j<=8;j++)
            {
                if( i == a && j == b - '0' ) continue;


                if( i == a ) cout << (char)i << j << "\n";
                else if( j == b - '0' ) cout << (char)i << j << "\n";
            }
        }
    }

    return 0;
}
