#include <bits/stdc++.h>

#define int long long

using namespace std;

struct Point{
    int x,y;
};

int cross(Point o,Point a,Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

Point p[100005];
Point answer[100005];

bool cmp(Point &a,Point &b)
{
    if( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}
int Andrew_monotone_chain(int n)
{
    sort(p,p+n,cmp);
    int cnt = 0;

    for(int i=0;i<n;i++) // 凸包下半部要選逆時針轉的, 外積 > 0 表示逆時針轉
    {
        while( cnt >= 2 && cross(answer[cnt-2],answer[cnt-1],p[i]) <= 0 ) cnt--;
        answer[cnt++] = p[i];
    }

    int under = cnt;

    for(int i=n-2;i>=0;i--)
    {  // 選上半部的時候不要把下半部選好的 pop 走
        while( cnt >= under + 1 && cross(answer[cnt-2],answer[cnt-1],p[i]) <= 0 ) cnt--;
        answer[cnt++] = p[i];
    }

    return cnt - 1; // 扣掉起點 (會被重複選到)
}
signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p[i].x >> p[i].y;
    }

    cout << Andrew_monotone_chain(n) << "\n";
}