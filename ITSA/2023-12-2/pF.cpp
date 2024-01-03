#include <iostream>
#define int long long
using namespace std;

int dp[40][11][11][11];

signed main()
{
    int x,y,z;
    cin >> x >> y >> z;
    if( x != 0 ) dp[1][1][0][0] = 1;
    if( y != 0 ) dp[1][0][1][0] = 1;
    dp[0][0][0][0] = 1;
    for(int i=2;i<=x+y+z;i++)
    {
        for(int a=0;a<=x;a++)
        {
            for(int b=0;b<=y;b++)
            {
                for(int c=0;c<=z;c++)
                {
                    if( a + b + c != i ) continue;
                    if( a != 0 ) dp[i][a][b][c] += dp[i-1][a-1][b][c];
                    if( b != 0 ) dp[i][a][b][c] += dp[i-1][a][b-1][c];
                    if( c != 0 ) dp[i][a][b][c] += dp[i-2][a-1][b][c-1] + dp[i-2][a][b-1][c-1];
                }
            }
        }
    }

    cout << dp[2][1][0][1] << "\n";

    // 2 1 1 -> 1 1 1, 1,0,1

    int ans = 0;

    for(int i=0;i<=x;i++)
    {
        for(int k=0;k<=y;k++)
        {
            for(int j=0;j<=z;j++)
            {
                if( i + k + j == x + y + z ) ans += dp[x+y+z][i][k][j];
                //cout << i << " " << k << " " << j << " " << dp[i+k+j][i][k][j] << "\n";
            }
        }
    }

    cout << ans << "\n";
}