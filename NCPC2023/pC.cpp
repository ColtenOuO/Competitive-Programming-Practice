#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[24],n,dp[24];
vector<vector<int>> ans;
vector<int> v;
int node_id = 1;

void solve(int pos,int last,int idx)
{	
	if( idx == ( n - 1 ) *  2 )
	{
		ans.push_back(v);
		return;
	}
	
	
	if( a[idx] == 0 ) v.push_back(0) , solve(last,pos,idx+1);
	else
	{
	//	cout << node_id << "\n";
		v.push_back(++dp[pos]) , 
		solve(node_id++,pos,idx+1);
	}
	
	return;
}
void dfs(int idx,int cnt)
{
    if( idx == ( n - 1 ) * 2 || cnt == 0 )
    {
    	if( idx == ( n - 2 ) * 2 && cnt != 0 ) return;
        int dep = 0 , ok = 1;
        for(int i=0;i<(n-1)*2;i++)
        {
        	dp[i] = 0;
        	if( a[i] != 0 ) dep++;
        	else dep--;
        	
        	if( dep < 0 ) ok = 0;
        }
        
        if( ok == 0 || dep != 0 ) return;
        
        v.clear();
        node_id = 1;
        solve(0,0,0);
      //  for(int i=0;i<6;i++) cout << a[i] << " ";
      //  cout << "\n";
        ans.push_back(v);
        
        return;
    }
    
    a[idx] = 0;
    dfs(idx+1,cnt-1);
    a[idx] = -1;
    dfs(idx+1,cnt);
    
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<23;i++) a[i] = -1;
    
    cin >> n;
    dfs(0,n-1);

	sort(ans.begin(),ans.end());    
    ans.resize( unique(ans.begin(),ans.end()) - ans.begin() );
    
    for(int i=0;i<ans.size();i++)
    {
    	for( auto j : ans[i] ) cout << j << " ";
    	cout << "\n";
    }
}