#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;

signed main()
{
    string s;
    int ans = 0;
    while(getline(cin,s))
    {
        string tmp = "";
        for(int i=0;i<s.size();i++)
        {
            if( s[i] >= '0' && s[i] <= '9' )
            {
                tmp += s[i];
            }
            else
            {
                if( tmp != "" )
                {
                    reverse(tmp.begin(),tmp.end());
                    ans += stoll(tmp);
                    tmp = "";
                }
            }
        }
        if( tmp != "" )
        {
            reverse(tmp.begin(),tmp.end());
            ans += stoll(tmp);
            tmp = "";
        }
    }

    cout << ans << "\n";
    return 0;
}