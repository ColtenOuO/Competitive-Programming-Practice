#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>

#define int long long
using namespace std;

int l[500005],r[500005],w[500005],b[500005],c[500005];
vector<pair<int,int> > in[500005],out[500005];

struct set_cmp{
    bool operator() const(const pair<int,int> &a,const pair<int,int> &b){
        if( a.first == b.first ) return a.second < b.second;
        return a.first > b.first;
    }
};
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> l[i] >> r[i] >> c[i] >> w[i];
    for(int i=1;i<=m;i++) cin >> b[i];

    set<pair<int,int>,set_cmp> s;
    for(int i=0;i<n;i++)
    {
        in[l[i]].push_back(make_pair(w[i],i));
        out[r[i]+1].push_back(make_pair(w[i],i));
    }
    
    for(int i=1;i<=m;i++)
    {
        for( auto i : out[i] ) s.erase(i);
        for( auto i : in[i] ) s.insert(i);

        int total = 0;
        while( b[i] != 0 && s.size() != 0 )
        {
            auto it = s.begin();
            if( c[it->second] <= b[i] )
            {
                b[i] -= c[it->second];
                total += c[it->second] * ( it -> first );
                s.erase(it);
            }
            else
            {
                c[it->second] -= b[i];
                total += b[i] * ( it -> first );
                b[i] = 0;
            }
        }

        cout << total << " ";
    }

    cout << "\n";

    return 0;
}