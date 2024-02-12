#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
#define int long long
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if( a.first == b.first ) return a.second > b.second;
    return a.first < b.first;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    while( cin >> n >> m )
    {
        deque<pair<int,int> > a(n),b(m);
        for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
        for(int i=0;i<m;i++) cin >> b[i].first >> b[i].second;
        int l,r;
        cin >> l >> r;
        int num1 = 0, num2 = 0;
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        
        int r1 = -1e18, r2 = -1e18;

        while( a.size() != 0 && a.front().second < l ) a.pop_front();
        while( b.size() != 0 && b.front().second < l ) b.pop_front();
        while( a.size() != 0 && a.front().first <= l ) r1 = max(r1,a.front().second), a.pop_front();
        while( b.size() != 0 && b.front().first <= l ) r2 = max(r2,b.front().second), b.pop_front();
        
        int idx1 = 0,idx2 = 0;
        
        if( r1 == -1e18 ) r1 = 1e18, num1 = -1;
        if( r2 == -1e18 ) r2 = 1e18, num2 = -1;

        while( idx1 < a.size() && r1 < r )
        {
            int new_r1 = -1e18;
            while( idx1 < a.size() && a[idx1].first <= r1 ) new_r1 = max(new_r1,a[idx1].second), idx1++;
            if( new_r1 == -1e18 )
            {
                num1 = -1;
                break;
            }
            r1 = new_r1;
            num1++;
        }
        while( idx2 < b.size() && r2 < r )
        {
            int new_r2 = -1e18;
            while( idx2 < b.size() && b[idx2].first <= r2 ) new_r2 = max(new_r2,b[idx2].second), idx2++;
            if( new_r2 == -1e18 )
            {
                num2 = -1;
                break;
            }
            r2 = new_r2;
            num2++;
        }

        if( r1 < r ) num1 = -1;
        if( r2 < r ) num2 = -1;

        if( num1 == -1 && num2 == -1 ) cout << "TIE\n";
        else if( num1 == -1 && num2 != -1 ) cout << "B WIN\n";
        else if( num1 != -1 && num2 == -1 ) cout << "A WIN\n";
        else if( num1 <= num2 ) cout << "A WIN\n";
        else cout << "B WIN\n";
    }
}