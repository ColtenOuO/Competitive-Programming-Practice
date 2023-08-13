class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> a;
        a.insert(1LL);
        do
        {
            vector<long long> b;
            for( long long i : a )
            {
                if( i * 2 <= 1e18 ) b.push_back(i*2);
                if( i * 3 <= 1e18 ) b.push_back(i*3);
                if( i * 5 <= 1e18 ) b.push_back(i*5);
            }

            for( long long i : b ) a.insert(i);
        }while( a.size() < n * 4 );

        vector<long long> c;
        for( long long i : a ) c.push_back(i);
        sort(c.begin(),c.end());
        return c[n-1];
    }
};