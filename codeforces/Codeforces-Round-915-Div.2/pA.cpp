#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>

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
        int a,b;
        cin >> a >> b;
        cout << max(a,b) << "\n";
    }
}