#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            v[i] = abs(x);
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(v.begin() + i + 1, v.end(), 2 * v[i]);
            ans += distance(v.begin() + i + 1, it);
        }

        cout << ans << "\n";
    }

    return 0;
}
