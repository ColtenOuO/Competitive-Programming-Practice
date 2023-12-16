#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define int long long
using namespace std;

vector<vector<int> > a,b;
int m;

bool cmp(vector<int> &a,vector<int> &b)
{
    int total1 = 0 ,total2 = 0 , mx1 = 0 , mx2 = 0;
    for(int i=0;i<m;i++)
    {
        if( a[i] != -1 ) total1++;
        if( b[i] != -1 ) total2++;
    }

    if( total1 != total2 ) return total1 > total2;
    
    for(int i=m-1;i>=0;i--)
    {
        if( a[i] != b[i] ) return a[i] < b[i];
    }

    return false;
}
bool same(vector<int> &a,vector<int> &b)
{
    int total1 = 0 ,total2 = 0 , mx1 = 0 , mx2 = 0;
    for(int i=0;i<m;i++)
    {
        if( a[i] != -1 ) total1++;
        if( b[i] != -1 ) total2++;
    }

    if( total1 != total2 ) return false;
    
    for(int i=m-1;i>=0;i--)
    {
        if( a[i] != b[i] ) return false;
    }

    return true;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        vector<int> tmp;
        for(int j=0;j<m;j++)
        {
            int num;
            cin >> num;
            tmp.push_back(num);
        }

        sort(tmp.begin(),tmp.end());
        a.push_back(tmp);
        b.push_back(tmp);
    }

    sort(a.begin(),a.end(),cmp);
    map<vector<int>,int> mp;
    int ans = 1,add = 0;
    for(int i=0;i<n;i++)
    {
        if( i != 0 )
        {
            if( same(a[i],a[i-1]) == false ) ans++ , ans += add , add = 0;
            else add++;
        }

        mp[a[i]] = ans;
    }

    for(int i=0;i<n;i++) cout << mp[b[i]] << " ";

    cout << "\n";
    return 0;
}