#include <iostream>
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
        int n;
        cin >> n;
        int c[26] = {};
        string s;
        cin >> s;

        for(int i=0;i<s.size();i++) c[s[i]-'a']++;
        
        bool ok = 1;
        for(int i=0;i<26;i++) if( c[i] > s.size() / 2 ) ok = 0;
        if( s.size() % 2 == 1 ) ok = 0;

        if( ok == 0 ) cout << -1 << "\n";
        else
        {
            int ans = 0 , opt[26] = {} , total = 0 , addition = 0;
            for(int i=0;i<s.size()/2;i++) if( s[i] == s[s.size()-i-1] ) total++ , opt[s[i]-'a']++;
            int total2 = total;
            for(int i=0;i<26;i++)
            {
                if( opt[i] > total / 2 ) addition = opt[i];
            }

            if( addition != 0 ) cout << addition << "\n";
            else cout << total2 / 2 + ( total2 % 2 != 0 ) << "\n";
        }
    }
}
