#include <iostream>
#include <numeric>
using namespace std;

#define int long long

using namespace std;

int gcd(int x,int y)
{
    while( y != 0 )
    {
        int num = x % y;
        x = y;
        y = num;
    }

    return x;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp(1000001,0),ans(1000001,0);
    for(int i=1;i<=1000000;i++)
    {
        for(int j=1;i*j<=1000000;j++)
        {
            dp[i*j]++;
        }
    }

    for(int i=2;i<=1000000;i++) dp[i] += dp[i-1];

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        cout << dp[n] + n << "\n";
    }
}