#include <iostream>
#include <algorithm>

using namespace std;

string s1,s2;
int dp[80][80][80][80];

int LCPS(int l1,int r1,int l2,int r2)
{
    if( r1 < l1 || r2 < l2 || l1 < 0 || l2 < 0 || r1 >= s1.size() || r2 >= s2.size() ) return 0;
    if( dp[l1][r1][l2][r2] != -1 ) return dp[l1][r1][l2][r2];
    if( l1 == r1 && l2 == r2 && s1[l1] == s1[r1] && s2[l2] == s2[r2] && s1[l1] == s2[l2] ) return 1;
    
    if( l1 < r1 && l2 < r2 && s1[l1] == s1[r1] && s2[l2] == s2[r2] && s1[l1] == s2[l2] )
    {
        dp[l1][r1][l2][r2] = LCPS(l1+1,r1-1,l2+1,r2-1) + 2;
    }
    else
    {
        int a = LCPS(l1+1,r1,l2,r2);
        int b = LCPS(l1,r1-1,l2,r2);
        int c = LCPS(l1,r1,l2+1,r2);
        int d = LCPS(l1,r1,l2,r2-1);

        dp[l1][r1][l2][r2] = max(max(a,b),max(c,d));
    }

    return dp[l1][r1][l2][r2];
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    cin >> s1 >> s2;

    for(int i=0;i<80;i++)
    {
        for(int j=0;j<80;j++)
        {
            for(int k=0;k<80;k++)
            {
                for(int t=0;t<80;t++) dp[i][j][k][t] = -1;
            }
        }
    }

    cout << LCPS(0,n-1,0,m-1) << "\n";

    return 0;
}