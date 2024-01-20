#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int num;
        cin >> num;

        // 1234 % 10 = 4 , 1234 / 10 = 123 , 123 % 10 = 3 , 123 / 10 = 12 , 12 % 10 = 2 , 12 / 10 = 1 , 1 % 10 = 1, 1 / 10 = 0

        if( num == 0 )
        {
            cout << 0 << "\n";
            continue;
        }

        long long ans = 1;
        while( num != 0 )
        {
            ans *= ( num % 10 );
            num /= 10;
        }

        cout << ans << "\n";
    }

    return 0;
}
