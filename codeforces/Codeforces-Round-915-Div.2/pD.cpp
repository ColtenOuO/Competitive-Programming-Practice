#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <deque>

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
        vector<int> a(n);
        int l = 0, r = n - 1;
        while( l != r )
        {
            int mid1 = ( l + r ) / 2;
            int mid2 = mid1 + 1;
            int mid3 = mid1 - 1;
            
            int idx1 = mid1 , idx2 = mid2;
            vector<int> b,c;
            b.push_back(a[idx1]);
            c.push_back(a[idx2]);
            idx1++ , idx2++;
            while( idx1 % n != mid1 ) b.push_back(a[idx1%n]), idx1++;
            while( idx2 % n != mid2 ) c.push_back(a[idx2%n]), idx2++;

            set<int> s1,s2;
            for(int i=0;i<=n;i++) s1.insert(i) , s2.insert(i);
            int total1 = 0, total2 = 0;
            for(int i=0;i<n;i++)
            {
                s1.erase(b[i]);
                s2.erase(c[i]);
                total1 += *s1.begin();
                total2 += *s2.begin();
            }

            if( total1)
        }
    }
}