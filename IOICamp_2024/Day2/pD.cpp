#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <vector>
#define int long long

using namespace std;

int dp[1000005][3];
int u[1000005][3],num[1000005][3];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if( s == "0" )
    {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> b((int)s.size()+1,0);
    s = "$" + s;
    dp[1][(s[1]-'0')%3] = 1,u[1][(s[1]-'0')%3] = '+';
    dp[1][(-1LL*(s[1]-'0')+12)%3] = 1,u[1][(-1LL*(s[1]-'0')+12)%3] = '-';
    for(int i=2;i<s.size();i++)
    {
        for(int j=0;j<=2;j++)
        {
            int idx1 = ( j + ( s[i] - '0' ) ) % 3;
            int idx2 = ( j - ( s[i] - '0' ) + 12 ) % 3;

          //  cout << dp[i-1][j] << " " << i << " " << j << " " << idx1 << " " << idx2 << "\n";

            if( dp[i-1][j] == 1 ) dp[i][idx1] = 1, u[i][idx1] = '+', num[i][idx1] = j;
            if( dp[i-1][j] == 1 ) dp[i][idx2] = 1, u[i][idx2] = '-', num[i][idx2] = j;
        }        
    }

    if( dp[s.size()-1][0] == 0 ) cout << "NO\n";
    else
    {
        vector<char> v;
        int idx1 = s.size() - 1, idx2 = 0;
        while( idx1 != 0 )
        {
            v.push_back(u[idx1][idx2]);
            idx2 = num[idx1][idx2];
            idx1--;
        }

        reverse(v.begin(),v.end());

        for(int i=1;i<s.size();i++)
        {
            if( i == 1 && v[i-1] == '+' ) cout << s[i];
            else cout << v[i-1] << s[i];
        }

        cout << "\n";
    }

    return 0;
}