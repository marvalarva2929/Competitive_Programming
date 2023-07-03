#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int digsum(int x) {
    int cur = 0;
    while (x) {
        cur += x % 10;
        x /= 10;
    }

    return cur;
}

signed main() {
    int n, k; cin >> n >> k;

    int i = 0;
    int x = 0;

    while (true) {
        if (digsum(i) == k) x++;

        if (x == n) {
            cout << i << nl;
            return 0;
        }

        i++;
    }
}
