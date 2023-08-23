class Solution {
public:
    int dp[101][4];
    int minimumOperations(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) dp[i][1] = dp[i][2] = dp[i][3] = 1e9;
        dp[0][1] = dp[0][2] = dp[0][3] = 1;
        dp[0][a[0]] = 0;
        for(int i=1;i<n;i++)
        {
            if( a[i] == 1 ) dp[i][1] = dp[i-1][1];
            else dp[i][1] = dp[i-1][1] + 1;

            if( a[i] == 2 ) dp[i][2] = min(dp[i-1][2],dp[i-1][1]);
            else dp[i][2] = min(dp[i-1][2],dp[i-1][1]) + 1;

            if( a[i] == 3 ) dp[i][3] = min({dp[i-1][1],dp[i-1][2],dp[i-1][3]});
            else dp[i][3] = min({dp[i-1][1],dp[i-1][2],dp[i-1][3]}) + 1;
        }

        return min({dp[n-1][1],dp[n-1][2],dp[n-1][3]});
    }
};
