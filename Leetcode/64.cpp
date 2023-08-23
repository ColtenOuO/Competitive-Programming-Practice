class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,(int)1e9));
        dp[1][1] = grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<m;k++)
            {
                if( i == 0 && k == 0 ) continue;
                int x = i + 1 , y = k + 1;
                dp[x][y] = min(dp[x-1][y],dp[x][y-1]) + grid[i][k];
            }
        }

        return dp[n][m];
    }
};
