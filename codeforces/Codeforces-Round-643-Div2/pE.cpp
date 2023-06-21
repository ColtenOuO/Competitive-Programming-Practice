#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

int a[100005],n;

int solve(int val,int A,int R,int M)
{
    int total = 0 , add = 0 , sub = 0;
    for(int i=0;i<n;i++)
    {
        if( a[i] < val ) add += val - a[i];
        else if( a[i] > val ) sub += a[i] - val;
    }
    //cout << val << " " << add << " " << sub << "\n";
    if( A + R > M )
    {
        if( add >= sub ) return M * sub + ( add - sub ) * A;
        else return M * add + ( sub - add ) * R;
    }
    else return add * A + sub * R;
}
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A,R,M;
    cin >> n >> A >> R >> M;
    for(int i=0;i<n;i++) cin >> a[i];
    
    int l = 1 , r = *max_element(a,a+n);
    while( l < r )
    {
        int mid1 = ( l + r ) / 2;
        int mid2 = mid1 + 1;

        int val1 = solve(mid1,A,R,M) , val2 = solve(mid2,A,R,M);
        if( val1 <= val2 ) r = mid1;
        else l = mid2;
    }

//    cout << l << "\n";
  //  cout << solve(8,A,R,M) << "\n";
    cout << solve(l,A,R,M) << "\n";
}
