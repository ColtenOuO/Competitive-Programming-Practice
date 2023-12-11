#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;

        set <int> s1,s2;
        for(int i=0;i<s.size();i++)
        {
            if( s[i] == 'B' || s[i] == 'b' )
            {
                if( s[i] == 'B' && s1.size() != 0 ) s1.erase(--s1.end());
                if( s[i] == 'b' && s2.size() != 0 ) s2.erase(--s2.end());

                continue;
            }

            if( s[i] >= 'A' && s[i] <= 'Z' ) s1.insert(i);
            else s2.insert(i);
        }

        vector<int> v;
        for( auto i : s1 ) v.push_back(i);
        for( auto i : s2 ) v.push_back(i);
        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++) cout << s[v[i]];
        cout << "\n";
    }

    return 0;
}
