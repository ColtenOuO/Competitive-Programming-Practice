class Solution {
private:
    int dp[502][502];
public:
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        for(int i=0;i<=n;i++) for(int k=0;k<=m;k++) dp[i][k] = 1e9;
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int i=0;i<=m;i++) dp[0][i] = i;

        for(int i=0;i<n;i++)
        {
            for(int k=0;k<m;k++)
            {
                int x = i + 1 , y = k + 1;

                int ans = 1e9;
                dp[x][y] = min(dp[x][y-1]+1,dp[x][y]); // insert
                dp[x][y] = min(dp[x-1][y]+1,dp[x][y]); // delete
                dp[x][y] = min(dp[x-1][y-1]+1,dp[x][y]); // replace

                if( s1[i] == s2[k] )
                {
                    dp[x][y] = min(dp[x-1][y-1],dp[x][y]);
                }
            }
        }

        return dp[n][m];
    }
};
