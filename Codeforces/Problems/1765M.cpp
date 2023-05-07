using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

int lcf(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return i;
        }
    }
    return a;
}

int32_t main() {
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int a = x/lcf(x);
        // cout << lcf(x) << nl;
        cout << a << " " << x - a << nl;
    }
} 