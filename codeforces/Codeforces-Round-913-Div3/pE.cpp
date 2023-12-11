#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

vector<int> v[80];

void init()
{
    for(int i=1;i<=10000000;i++)
    {
        int sum = 0,num = i;
        while( num != 0 ) sum += num % 10 , num /= 10;
        v[sum].push_back(i);
    }

    return;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();

    for(int i=0;i<=70;i++) cout << i << " " << v[i].size() << "\n";

    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;

        int cnt = 0,num = n;
        while( num != 0 ) cnt += num % 10 , num /= 10;

        for(int i=0;i<=cnt;i++)
        {
            for(int j=0;j<=cnt;j++)
            {
                if( i + j > n ) break;
                int k = n - ( i + j );

            }
        }
    }
}
