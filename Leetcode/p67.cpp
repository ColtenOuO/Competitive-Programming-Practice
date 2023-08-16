class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> x(10004,'0'),y(10004,'0');
        int idx = 0;
        for(int i=a.size()-1;i>=0;i--) x[idx++] = a[i];
        idx = 0;
        for(int i=b.size()-1;i>=0;i--) y[idx++] = b[i];

        string ans = "";
        int add = 0;
        for(int i=0;i<=10000;i++)
        {
            int val = add + x[i] - '0' + y[i] - '0'; 
            if( val >= 2 ) add = 1;
            else add = 0;
            val %= 2;
            ans += to_string(val);
        }
        
        string fix_ans = "";
        for(int i=ans.size()-1;i>=0;i--)
        {
            if( fix_ans == "" && ans[i] == '0' ) continue;
            else fix_ans += ans[i];
        }

        if( fix_ans == "" ) fix_ans = "0";

        return fix_ans;
    }
};