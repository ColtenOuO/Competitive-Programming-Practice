#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

string s1[10] = {"I","He","She","They","Mary","John"};
string s2[10] = {"love","like","see","find"};
string s3[10] = {"me","him" ,"her" ,"them" ,"Mary" ,"John"};
signed main()
{
    int q;
    cin >> q;
    while(q--)
    {
        string a[3];
        cin >> a[0] >> a[1] >> a[2];
        int t[3][4] = {};
        for(int i=0;i<10;i++)
        {
            if( a[0] == s1[i] ) t[0][1] = 1;
            if( a[0] == s2[i] ) t[0][2] = 1;
            if( a[0] == s3[i] ) t[0][3] = 1;

            if( a[1] == s1[i] ) t[1][1] = 1;
            if( a[1] == s2[i] ) t[1][2] = 1;
            if( a[1] == s3[i] ) t[1][3] = 1;

            if( a[2] == s1[i] ) t[2][1] = 1;
            if( a[2] == s2[i] ) t[2][2] = 1;
            if( a[2] == s3[i] ) t[2][3] = 1;
        }

        vector<int> v;
        for(int i=0;i<3;i++) v.push_back(i);
        bool f = false;
        do
        {
            int x = v[0], y = v[1], z = v[2];
           // cout << t[x][1] << " " << t[y][2] << " " << t[z][3] << "\n";
            if( t[x][1] == 1 && t[y][2] == 1 && t[z][3] == 1 )
            {
                if( f == true ) cout << " or ";
                f = true;
                cout << a[x] << " ";
                if( a[x] != "I" && a[x] != "They" ) cout << a[y] << "s" << " ";
                else cout << a[y] << " ";
                
                if( a[x] == "I" && a[z] == "me" ) cout << "myself";
                else if( ( a[x] == "He" || a[x] == "John" ) && a[z] == "him" ) cout << "himeself";
                else if( ( a[x] == "Her" || a[x] == "Mary" ) && a[z] == "her" ) cout << "herself";
                else if( a[x] == "They" && a[z] == "them" ) cout << "themselves";
                else cout << a[z];
            }
        } while (next_permutation(v.begin(),v.end()));
        cout << "\n";
    }
}