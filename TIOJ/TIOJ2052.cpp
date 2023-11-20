#include <iostream>
#include <map>
#define int long long

using namespace std;

int dp[2000][2000];

void build(int mod)
{
    for(int i=0;i<2000;i++) dp[i][0] = 1;

    for(int i=0;i<2000;i++)
    {
        for(int j=1;j<=i;j++) dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j] ) % mod;
    }

    return;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d;
    string s;
    cin >> d >> s;

    build(d);

//    cout << dp[2][1] << " " << dp[1][1] << "\n";

    int ans = 0;
    map<char,int> mp;

    for(int i=0;i<s.size();i++) mp[s[i]]++;

    for(int i=0;i<s.size();i++)
    {
        for( auto j : mp )
        {
            if( j.first == s[i] )
            {
                mp[s[i]]--;
                break;
            }

            int total = 1 , last = (int)s.size() - i - 1;

            mp[j.first]--;
            for( auto k : mp )
            {
                total *= dp[last][k.second] , total %= d;
                last -= k.second;
            }
            mp[j.first]++;

            ans += total , ans %= d;
        }
    }

    cout << ans << "\n";

    return 0;
}
