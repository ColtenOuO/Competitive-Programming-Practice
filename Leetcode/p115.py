class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [0] * len(t)
        for i in range(0,len(s)):
            for k in range(len(t)-1,-1,-1):
                if( s[i] == t[k] ):
                    if( k == 0 ): dp[0] += 1
                    else: dp[k] += dp[k-1]
        return dp[len(t)-1]