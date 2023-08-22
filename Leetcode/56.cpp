bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if( a.first == b.first ) return a.second > b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;
        for( auto i : intervals )
        {
            v.push_back({i[0],i[1]});
        }

        sort(v.begin(),v.end(),cmp);

        vector<vector<int>> ans;

        int st = v[0].first , R = v[0].second;
        for(int i=1;i<v.size();i++)
        {
            if( v[i].first <= R ) R = max(R,v[i].second);
            else
            {
                ans.push_back({st,R});
                st = v[i].first , R = v[i].second;
            }
        }
        ans.push_back({st,R});

        return ans;
    }
};
