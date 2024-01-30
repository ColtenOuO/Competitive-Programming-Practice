#include<bits/stdc++.h>

#define int long long
#define f first
#define s second
#define AC ios_base::sync_with_stdio(0), cin.tie(0)
#define endl "\n"
#define lowbit(x) x&(-x)

using namespace std;

const int sz = 2e5 + 5;

int n, q;
int salary[sz], bit[sz];

void update(int i, int v){
    for(; i <= n; i += lowbit(i)) {
        bit[i] += v;
    }
}

int query(int x) {
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        sum += bit[x];
    }
    return sum;
}

signed main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> salary[i];
        update(salary[i], 1);
    }
    while(q--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == '?') {
            cout << query(b) << ' ' << query(a - 1) << endl;
            cout << query(b) - query(a - 1) << endl;
        }
        else {
            update(salary[a], -1);
            update(b, 1);
            salary[a] = b;
        }
    }
}