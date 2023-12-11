#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int mx = 0;
        int cnt[26] = {};

        for(int i=0;i<s.size();i++) cnt[s[i]-'a']++ , mx = max(mx,cnt[s[i]-'a']);

        if( mx > n - mx ) cout << mx - ( n - mx ) << "\n";
        else
        {
            if( n % 2 == 1 ) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }

    return 0;
}
