#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        string s,tmp = "";
        cin >> s;
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if( tmp == "" ) tmp += s[i], ans++;
            else
            {
                if( tmp[tmp.size()-1] == s[i] ) tmp = "", tmp += s[i], ans++;
                else if( tmp[0] == s[i] && ( i + 1 == s.size() || s[i] == s[i+1] ) && tmp.size() != 1 ) tmp = "", tmp += s[i], ans++;
                else tmp += s[i];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}