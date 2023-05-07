#include <iostream>
#include <cmath>
#define int long long
#define nl '\n'
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            for (int i = 0; i < n; i++) {
                cout << n << ' ';
            }
            cout << nl;
        } else {
            int x = n;
            while (x > 1) {
                x /= 2;
            }
            x *= 2;
            int t = pow(2, x);
            int one = t - t/2;
            int two = t + t/2;
            for (int i = 0; i < n - 2; i++) cout << t << ' ';
            cout << one << " " << two << nl;
        }
    }
}