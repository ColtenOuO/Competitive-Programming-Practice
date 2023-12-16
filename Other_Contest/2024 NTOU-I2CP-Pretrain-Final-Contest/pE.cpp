#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n),b(n,1);
    for(int i=0;i<n;i++) cin >> a[i];
    
    if( n == 1 )
    {
        cout << 2 << "\n";
        return 0;
    }
    
    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<n;j++) b[j] *= a[j];
        int g = llabs(b[1] - b[0]);
        for(int j=2;j<n;j++)
        {
            g = __gcd(llabs(b[j]-b[j-1]),g);
        }
        
       // cout << i << " " << g << "\n";

        if( g == 1 ) continue;
        else
        {
            cout << g << "\n";
            return 0;
        }
    }
}