class Solution {
public:

    bool isUgly(int n) {
        vector<int> a = { 2 , 3 , 5 };
        for(int i=2;i>=0;i--)
        {
            while( abs(n) != 1 )
            {
                if( n == 0 ) break;
                if( n % a[i] == 0 ) n /= a[i];
                else break;
            }
        }

        return ( n == 1 );
    }
};