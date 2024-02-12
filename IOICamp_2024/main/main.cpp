int dp[101] = {};

class Solution {
public:
    int numDecodings(string s) {
        s = "%" + s;
        dp[0] = 1;
        dp[1] = 1;
        if( s[1] == '0' ) return 0;
        for(int i=2;i<s.size();i++)
        {
            if( s[i] == '0' && ( s[i-1] == '$' || s[i-1] == '0' || s[i-1] > '2' ) ) return 0;

            dp[i] = 0;
            if( s[i] != '0' ) dp[i] += dp[i-1];
            if( s[i-1] == '1' ) dp[i] += dp[i-2];
            if( s[i-1] == '2' && s[i] <= '6' ) dp[i] += dp[i-2];
        }
        return dp[s.size()-1];
    }
};