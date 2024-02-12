#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q,l,k;
    cin >> q >> l >> k;
    while(q--)
    {
        string s;
        cin >> s;
        int ans = 0;
        if( k == 1 ) ans = l;
        if( l == k )
        {
            int idx1 = 0, idx2 = l - 1,total = 0;
            while( idx1 < idx2 )
            {
                if( s[idx1] != s[idx2] ) total++;
                idx1++, idx2--;
            }
            ans = max(ans,l-total);
        }
        if( k % 2 == 1 )
        {
            vector<int> cnt1(26,0),cnt2(26,0);
            for(int i=0;i<s.size();i++) 
            {
                if( i % 2 == 0 ) cnt1[s[i]-'a']++;
                else cnt2[s[i]-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++) ans = max(ans,l/2+1-((l/2+1)-cnt1[i]) + l / 2 - ( l / 2 - cnt2[j] ) );

            }
        }
        
        vector<int> cnt(26,0);
        for(int i=0;i<l;i++) cnt[s[i]-'a']++;
        for(int i=0;i<26;i++) ans = max(ans,l-(l-cnt[i]));

        cout << ans << "\n";
    }

    return 0;
}