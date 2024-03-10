#include<bits/stdc++.h>
using namespace std;

#define weak_sakinu0807 ios::sync_with_stdio(0),cin.tie(0)
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define F first
#define S second
#define tmi(a,b) a=min(a,b)
#define tmx(a,b) a=max(a,b)

const int MAX_N=1e6+5,INF=1e18,MOD=1e9+9;
int arr[MAX_N];
int n,q;

struct node{
    int l,r;
    int lsum_1,rsum_1;       //自己最大 前綴 後綴 左右idx
    int lsum_2,rsum_2;       //自己最大 前綴 後綴 左右idx
    int mx_3,lsum_3,rsum_3;
} seg[MAX_N<<2];

/*void print(node x){
    cout << x.l << "," << x.r << "\n";
    cout << x.lsum_1 << "," << x.rsum_1 << "\n";
    cout << x.lsum_2 << "," << x.rsum_2 << "\n";
    cout << x.mx_3 << "," << x.lsum_3 << "," << x.rsum_3 << "\n";
    
}*/

node merge(node a,node b){
    node c={0,0,0,0,0,0,0,0,0};
    c.l=a.l;
    c.r=b.r;
    
    c.lsum_1=a.lsum_1;
    c.rsum_1=b.rsum_1;
    if(arr[a.r]<arr[b.l]){      //可以merge 12 34
        if(a.lsum_1==a.r-a.l+1){
            c.lsum_1+=b.lsum_1;
        }
        if(b.rsum_1==b.r-b.l+1){
            c.rsum_1+=a.rsum_1;
        }
    }
    
    c.lsum_2=a.lsum_2;
    c.rsum_2=b.rsum_2;
    if(arr[a.r]>arr[b.l]){      //可以merge 12 34
        if(a.lsum_2==a.r-a.l+1){
            c.lsum_2+=b.lsum_2;
        }
        if(b.rsum_2==b.r-b.l+1){
            c.rsum_2+=a.rsum_2; 
        }
    }
    
    c.mx_3=max(a.mx_3,b.mx_3);
    
    c.lsum_3=a.lsum_3;      //左合法的最大
    if(arr[a.r]>arr[b.l]){
        int x=a.rsum_3+b.lsum_2;
        if(a.mx_3==a.r-a.l+1){
            c.lsum_3=x;
        }
        tmx(c.mx_3,x);
    }
    
    c.rsum_3=b.rsum_3;      //右合法的最大
    if(arr[a.r]<arr[b.l]){
        int x=a.rsum_1+b.lsum_3;
        if(b.mx_3==b.r-b.l+1){
            c.rsum_3=x;
        }
        tmx(c.mx_3,x);
    }
    
    if(c.lsum_3==c.r-c.l+1) c.rsum_3=c.lsum_3;
    if(c.rsum_3==c.r-c.l+1) c.lsum_3=c.rsum_3;
    tmx(c.mx_3,max(c.lsum_3,c.rsum_3));
    return c;
}

void build(int l,int r,int id){
    if(l==r){
        seg[id]={
            l,l,
            1,1,
            1,1,
            1,1,1
        };
        return;
    }
    int mm=(l+r)/2;
    build(l,mm,id*2);
    build(mm+1,r,id*2+1);
    seg[id]=merge(seg[id*2],seg[id*2+1]);
}

void updata(int l,int r,int id,int pos,int v){
    if(l==r){
        arr[l]=v;
        return;
    }
    int mm=(l+r)/2;
    if(pos<=mm) updata(l,mm,id*2,pos,v);
    else updata(mm+1,r,id*2+1,pos,v);
    seg[id]=merge(seg[id*2],seg[id*2+1]);
}

node query(int l,int r,int id,int ql,int qr){
    if(ql<=l&&r<=qr) return seg[id];
    int mm=(l+r)/2;
    //print(now);
    if(qr<=mm) return query(l,mm,id*2,ql,qr);
    else if(ql>mm) return query(mm+1,r,id*2+1,ql,qr);
    return merge(query(l,mm,id*2,ql,qr),query(mm+1,r,id*2+1,ql,qr));
}

void qq(int n,int l,int r){
    node now=query(1,n,1,l,r);
    cout << now.mx_3 << "\n";
    //print(now);
}
/*
8 6
7 4 5 6 8 9 1 2
2 1 8
1 1 10
1 3 3
2 2 8
1 1 12
2 3 6

8 1
10 4 3 6 8 9 1 2
2 2 8

*/
void solve(){
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,n,1);
    while(q--){
        int tp,a,b;
        cin >> tp >> a >> b;
        if(tp==1){
            arr[a]=b;
            updata(1,n,1,a,b);
        }
        else{
            qq(n,a,b);
        }
        //for(int i=1;i<=n;i++) cout << arr[i] << " \n"[i==n];
    }
}

signed main(){
    weak_sakinu0807;
    solve();
}