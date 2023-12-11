#include <iostream>
#include <vector>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> count(82, 0); // 最大的數字之和為 9*7 = 63，加一點緩衝
        for (int i = 0; i <= n; ++i) {
            count[digitSum(i)]++;
        }

        int total = 0;
        for (int s = 0; s < count.size(); ++s) {
            if (digitSum(n) == s) {
                total += count[s] * count[s] * count[s];
            }
        }
        cout << total << endl;
    }
    return 0;
}

