#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N=1e6+5;
int dp[26][MAX_N];

signed main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    s=" "+s;
    int n=s.size();
    int an=0;
    for(int i=0;i<26;i++){
        int r=1;
        int cnt=0;
        for(int l=1;l<=n;l++){
            while(r<=n&&cnt<k){
                if(s[r]!='A'+i) cnt++;
                r++;
            }
            an=max((int)an,(int)r-l-cnt);
            if(s[l]!='A'+i) cnt--;
        }
    }
    cout << an << "\n";
}