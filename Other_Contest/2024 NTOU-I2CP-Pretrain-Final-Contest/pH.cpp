#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define int long long

using namespace std;

deque<int> tmp1,tmp2;
deque<int> r,b; 
bool ok = 1;
void solve(int n)
{
    if( ok == 0 || n == 1 ) return;
    vector<pair<int,char> > v;
    for(int i=0;i<n/2;i++)
    {
        if( r.size() != 0 )
        {
            if( b.size() == 0 )
            {
                ok = 0;
                return;
            }
            if( b.front() < r.front() ) v.push_back(make_pair(b.front(),'B')) , b.pop_front(),r.pop_front();
            else v.push_back(make_pair(r.front(),'R')), r.pop_front(),b.pop_back();
        }
        else
        {
            b.pop_back();
            v.push_back(make_pair(b.back(),'B'));
            b.pop_back();
        }
    }

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if( v[i].second == 'R' ) r.push_back(v[i].first);
        else b.push_back(v[i].first);
    }

    solve(n/2);

    return;
}
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
        r.clear();
        b.clear();
        for(int i=0;i<s.size();i++)
        {
            if( s[i] == 'R' ) r.push_back(i);
            else b.push_back(i);
        }
        ok = 1;
        solve((1LL<<n));
        
        if( ok == 1 ) cout << "Interesting\n";
        else cout << "Boring\n";
    }

    return 0;
}