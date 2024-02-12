#include<iostream>
#include<vector>
using namespace std;

#define int long long

const int MAX_N=1e3+5,INF=1e18;
int arr[MAX_N];
int cnt[MAX_N];
int n,sum;
vector<pair<int,int>> v;

struct node{            //有多少最小值和最小值是多少
    int sum,min;
    int tag;
} seg[MAX_N<<2];

void build(int l,int r,int id){
    seg[id]={r-l+1,0,0};
    if(l==r){
        return;
    }
    int mm=(l+r)/2;
    build(l,mm,id*2);
    build(mm+1,r,id*2+1);
}

void merge(node &c,node a,node b){
    c.min=min(a.min,b.min);
    if(a.min==c.min){
        c.sum=a.sum;
    }
    else if(a.min>b.min){
        c.sum=b.sum;
    }
    else{
        c.sum=a.sum+b.sum;
    }
}

void push(int id){
    int x=seg[id].tag;
    seg[id*2].tag+=x;
    seg[id*2].min+=x;
    seg[id*2+1].tag+=x;
    seg[id*2+1].min+=x;
    seg[id].tag=0;
}

void updata(int l,int r,int id,int ql,int qr,int v){
    if(r<ql||qr<l) return;
    if(ql<=l&&r<=qr){
        seg[id].tag+=v;
        seg[id].min+=v;
        return;
    }
    push(id);
    int mm=(l+r)/2;
    updata(l,mm,id*2,ql,qr,v);
    updata(mm+1,r,id*2+1,ql,qr,v);
    merge(seg[id],seg[id*2],seg[id*2+1]);
}

node query(int l,int r,int id,int ql,int qr){
    if(r<ql||qr<l) return {0,0,0};
    if(ql<=l&&r<=qr){
        return seg[id];
    }
    push(id);
    node now={0,INF,0};
    int mm=(l+r)/2;
    merge(now,query(l,mm,id*2,ql,qr),query(mm+1,r,id*2+1,ql,qr));
    return now;
}

int l(int x){
    return max(1LL,x-arr[x]+1);
}

int r(int x){
    return min(n,x+arr[x]-1);
}

bool needl(int x){
    return query(1,n,1,l(x),x).min==0;
    /*for(int i=l(x);i<=x;i++){
        if(!cnt[i]){
            return 1;
        }
    }
    return 0;*/
}

bool needr(int x){
    return query(1,n,1,x,r(x)).min==0;
    /*for(int i=r(x);i>=x;i--){
        if(!cnt[i]){
            return 1;
        }
    }
    return 0;*/
}

int wt(){       //還有幾個0
    if(seg[1].min!=0) return 0;
    return seg[1].sum;
}

int f(int id){     //枚舉某個數的結果
    if(wt()>sum) return INF;
    if(id==n){
        if(wt()) return INF;
        return 0;
    }
    int x=v[id].second;
    cout << "id=" << id << " x=" << x << " " << wt() << "\n";
    cout << seg[1].min << "," << seg[1].sum << "\n";
    int an=INF;
    if(arr[x]==1){
        return wt();
    }
    if(needl(x)){
        //cout << id << " " << x << "l\n";
        updata(1,n,1,l(x),x,1);
        /*for(int i=l(x);i<=x;i++){
            if(!cnt[i]) wt--;
            cnt[i]++;
        }*/
        sum-=arr[x];
        int test=f(id+1);
        //cout << id << " xl=" << x << " " << wt() << " " << test << "\n";
        an=min(an,test+1);
        sum+=arr[x];
        /*for(int i=l(x);i<=x;i++){
            cnt[i]--;
            if(!cnt[i]) wt++;
        }*/
        updata(1,n,1,l(x),x,-1);
    }
    if(needr(x)){
        //cout << id << " " << x << "r\n";
        updata(1,n,x,r(x),x,1);
        /*for(int i=r(x);i>=x;i--){
            if(!cnt[i]) wt--;
            cnt[i]++;
        }*/
        sum-=arr[x];
        int test=f(id+1);
        //cout << id << " xr=" << x << " " << wt() << " " << test << "\n";
        an=min(an,test+1);
        sum+=arr[x];
        /*for(int i=r(x);i>=x;i--){
            cnt[i]--;
            if(!cnt[i]) wt++;
        }*/
        updata(1,n,x,r(x),x,-1);
    }
    sum-=arr[x];
    an=min(an,f(id+1));
    sum+=arr[x];
    return an;
}

void solve(){
    v.clear();
    cin >> n;
    build(1,n,1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        sum+=arr[i];
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
        v.push_back({arr[i],i});
    }
    sort(v.rbegin(),v.rend());
    cout << f(0) << "\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
}