#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define int long long
using namespace std;
bool cmp(pair<string,int> a,pair<string,int> b)
{
    return stoll(a.first) < stoll(b.first);
}
signed main()
{
    int n;
    cin >> n;
    vector<pair<string,int> > v(n);
    map<string,long double> a,b,c;
    map<string,long double> mp;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        a[s] = b[s] = c[s] = 0;
        cin >> a[s] >> b[s] >> c[s];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        string s;
        int h;
        cin >> s >> h;
        if( mp.count(s) == 0 ) mp[s] = 0;
        mp[s] += h;
    }

    vector<pair<string, long double> > ans;

    for( auto i : a )
    {
        string s = i.first;
        long double total = a[s] * (long double)0.3 + b[s] * (long double)0.3 + c[s] * (long double)0.4;
        if( mp.count(s) != 0 && mp[s] > 6 ) total -= ( mp[s] - 6 );
        ans.push_back(make_pair(s,total));
    }

    sort(ans.begin(),ans.end(),cmp);
    for( auto i : ans )
    {
        cout << i.first << " ";
        int g = (int)i.second, t = i.second * 10;
        if( round(i.second) < 0 )
        {
            cout << 0 << "\n";
            continue;
        }
        cout << round(i.second) << "\n";
    }

    return 0;
}