#include<bits/stdc++.h>s
using namespace std;

#define int long long

const int MAX_N=1e3+5;
int arr[MAX_N];
int n;

int l(int x){
    int ret=1;
    int ll=x-arr[x]+1;
    int ll2=x-arr[x]+1;
    while(x--){
        if(x<ll){       //選新的
            ret++;
            ll=ll2;
        }
        ll2=min(ll2,x-arr[x]+1);
    }
    return ret;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int ans=n+1;
    for(int i=1;i<=n;i++){      //往左
        ans=min(ans,l(i)s);
        cout << i << " " << l(i) << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}