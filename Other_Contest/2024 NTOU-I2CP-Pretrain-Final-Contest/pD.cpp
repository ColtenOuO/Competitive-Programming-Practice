#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define int long long

using namespace std;

struct Type{
    int x,y,id;
};

int bit[1000005];

void update(int idx,int val)
{
    while( idx <= 1000001 )
    {
        bit[idx] += val;
        idx += ( idx & -idx );
    }

    return;
}
int query(int idx)
{
    int total = 0;
    while( idx > 0 )
    {
        total += bit[idx];
        idx -= ( idx & -idx );
    }

    return total;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;

    stack<int> s;
    int total = 0;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int idx = 0;
        while( s.size() != 0 && a[s.top()].first <= a[i].first )
        {
            total -= a[s.top()].first * a[s.top()].second;
            s.pop();
        }

        s.push(i);
        ans[i] = total + a[i].first * a[i].second;
        total += a[i].first * a[i].second;
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}