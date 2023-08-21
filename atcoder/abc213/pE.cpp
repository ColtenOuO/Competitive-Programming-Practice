#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

char mp[502][502];
int ans[502][502];

struct bfs{
    int x,y,val;
};
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h,w;
    cin >> h >> w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++) cin >> mp[i][j] , ans[i][j] = 1e9;
    }

    deque<bfs> dq;
    dq.push_back({1,1,0});
    ans[1][1] = 0;

    while( dq.size() != 0 )
    {
        bfs u = dq.front();
        dq.pop_front();

        for(int i=-2;i<=2;i++)
        {
            for(int k=-2;k<=2;k++)
            {
                if( abs(i) == 2 && abs(k) == 2 ) continue;
                int a = u.x + i , b = u.y + k , c = u.val;

                if( a <= 0 || b <= 0 || a > h || b > w ) continue;
             
                if( ( abs(i) == 1 && k == 0 ) || ( i == 0 && abs(k) == 1 ) )
                {
                	if( mp[a][b] == '#' )
                    {
                    	if( ans[a][b] > c + 1 )
                        {
                        	ans[a][b] = c + 1;
                          	dq.push_back({a,b,c+1});
                        }
                    }
                  	else
                    {
                    	if( ans[a][b] > c )
                        {
                        	ans[a][b] = c;
                          	dq.push_front({a,b,c});
                        }
                    }
                }
              	else
                {
                	if( ans[a][b] > c + 1 )
                    {
                    	ans[a][b] = c + 1;
                      	dq.push_front({a,b,c+1});
                    }
                }
            }
        }
    }

    cout << ans[h][w] << "\n";

    return 0;
}

