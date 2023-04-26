using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define mod 1000000007
vector<int> p;
bool isComp[100];

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    int curr = 1;
    for (int i = 2; i <= 200; i++) {
        int next = lcm(curr, i);
        int t = (n/curr - n/next);
        ans += (t * i) % mod;
        curr = next;
    }
    cout << ans % mod<< nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 2; i < 100; i++)
        if (!isComp[i]) {
            p.push_back(i);
            for (int j = i + i; j < 100; j += i)
                isComp[j] = true;
        }

    int t; cin >> t;
    while (t--)
        solve();
}