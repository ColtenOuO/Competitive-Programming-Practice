class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> v;
        v.push_back(-1);
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            if( s[i] == '(' ) v.push_back(i);
            else
            {
                if( v.size() == 0 ) v.push_back(i);
                else
                {
                    v.pop_back();
                    if( v.size() == 0 ) v.push_back(i);
                    else ans = max(ans,i-v.back());
                }
            }
        }

        return ans;
    }
};