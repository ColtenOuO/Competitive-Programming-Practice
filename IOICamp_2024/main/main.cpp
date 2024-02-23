#include <iostream>
#include <algorithm>
#include <utility>
#define int long long
using namespace std;
struct Type{
    int a,b,c;
};
bool cmp(Type &x,Type &y)
{
    return x.b - x.a < y.b - y.a;
}
signed main()
{
    int n;
    cin >> n;
    vector<Type> v(n);
    for(int i=0;i<n;i++) cin >> v[i].a >> v[i].b >> v[i].c;
    sort(v.begin(),v.end(),cmp);
    int front = 0,ans = 0, sum = 0;
    for(int i=0;i<n;i++)
    {
        ans += ( ( i + 1 ) * i / 2 );
        ans += ( v[i].a + v[i].c ) * v[i].b;
        ans -= front;
        front += ( v[i].b - v[i].a );
    }

    cout << ans << "\n";
    return 0;
}