#include <iostream>

#define int long long

using namespace std;

int dp[61][61];

void build()
{
    for(int i=0;i<=60;i++) dp[i][0] = 1;
    for(int i=1;i<=60;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b,k;
    cin >> a >> b >> k;

    string ans = "";

    build();

    while( a != 0 && b != 0 )
    {
        if( dp[a+b-1][b] >= k ) ans += "a" , a--;
        else
        {
            k -= dp[a+b-1][b];
            ans += "b" , b--;
        }
    }

    while( a != 0 ) ans += "a" , a--;
    while( b != 0 ) ans += "b" , b--;

    cout << ans << "\n";

    return 0;
}
