#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

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
        string s;
        cin >> s;
        string s2;
        s2 += s;
        sort(s2.begin(),s2.end());

        if( s == s2 )
        {
            cout << 0 << "\n";
            continue;
        }
        
        vector<int> a,b,vis(n,0);
        vector<pair<char,int> > v;
        vector<int> c[26];
        for(int i=0;i<s.size();i++) c[s[i]-'a'].push_back(i);
        int idx = -1,pos = 0;
        for(int i=25;i>=0;i--)
        {
            auto it = lower_bound(c[i].begin(),c[i].end(),idx+1);
            if( it != c[i].end() )
            {
                vis[*it] = 1;
                idx = *it;
                b.push_back(*it);
                v.push_back(make_pair(s[*it],pos++));
                i++;
            }
        }

        string s3,s4;
        for(int i=0;i<b.size();i++) s4 += s[b[i]];
        sort(s4.begin(),s4.end());

        int index = 0;
        for(int i=0;i<s.size();i++)
        {
            if( vis[i] != 1 ) s3 += s[i];
            else s3 += s4[index++];
        }

    //    for( auto i : b ) cout << i << "\n";

        if( s3 != s2 )
        {
            cout << -1 << "\n";
        }
        else
        {
            sort(v.begin(),v.end());
            int mn1 = 0 , mn2 = 0;
            char u1 = v[0].first , u2 = v[v.size()-1].first;
            for( auto i : v )
            {
                if( i.first == u2 ) mn1 = max(mn1,i.second);
                if( i.first == u1 ) mn2 = max(mn2,i.second);
            }

          ///  cout << u1 << " " << u2 << "\n";

        //    cout << mx << " " << mn << "\n";

            cout << mn2 - mn1 << "\n";
        }
    }
}