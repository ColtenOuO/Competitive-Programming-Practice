#include <iostream>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int n,k;
        cin >> n >> k;

        if( n == 2 )
        {
            cout << "YES\n";
            if( k == 1 ) cout << "1 0\n";
            else
            {
                cout << 1 << " " << k - 1 << "\n";
            }
        }
        else
        {
            int num = n / 2 + ( n % 2 != 0 );
            if( n % 2 != 0 ) num--;

            if( num > k ) cout << "NO\n";
            else
            {
                if( n % 2 == 1 && k - num == 0 )
                {
                    cout << "NO\n";
                    continue;
                }

                cout << "YES\n";
                for(int i=1;i<=n-1;i++) cout << i % 2 << " ";
                cout << k - num << "\n";
            }
        }
    }

    return 0;
}