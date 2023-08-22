class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int l = newInterval[0] , r = newInterval[1];
        vector<pair<int,int>> v;
        for( auto i : intervals ) v.push_back({i[0],i[1]});
        vector<vector<int>> ans;
        vector<pair<int,int>> v2;
        
        bool ok = false;
        if( v.size() != 0 && l <= v[0].first ) ok = true , v2.push_back({l,r}); 
        
        for(int i=0;i<v.size();i++)
        {
            if( i != v.size() - 1 && v[i+1].first >= l && ok == false )
            {
                ok = true;
                v2.push_back(v[i]);
                v2.push_back({l,r});
            }
            else v2.push_back(v[i]);
        }

        if( ok == false ) v2.push_back({l,r});

        int st = v2[0].first , R = v2[0].second;
        for(int i=1;i<v2.size();i++)
        {
            if( v2[i].first <= R ) R = max(R,v2[i].second);
            else
            {
                ans.push_back({st,R});
                st = v2[i].first , R = v2[i].second;
            }
        }

        ans.push_back({st,R});
        return ans;
    }
};
