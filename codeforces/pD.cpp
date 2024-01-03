#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>

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
        string ans;
        int n;
        cin >> n;
        string s;
        cin >> s;

        string tmp = "";
        for(int i=0;i<s.size();i++)
        {
            tmp += s[i];
            if( tmp.size() == 2 )
            {
                if( i + 2 < s.size() && s[i+2] != 'a' && s[i+2] != 'e' ) continue;
                else if( i + 2 == s.size() ) continue;
                else
                {
                    if( ans != "" ) ans += ".", ans += tmp, tmp = "";
                    else ans += tmp, tmp = "";
                //    cout << i << "\n";
                }
            }
            else if( tmp.size() == 3 )
            {
                if( ans != "" ) ans += ".", ans += tmp, tmp = "";
                else ans += tmp, tmp = "";
            }
        }

        cout << ans << "\n";
    }

    return 0;
}