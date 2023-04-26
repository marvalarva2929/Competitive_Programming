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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

int flip(int a) {
    int pw = 0;
    for (int i = 0; i < log2(a); i++)
        pw += pow(2, i);
    return a ^ pw;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> ansf;
    vector<int> ansb;
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        a[i] = x - '0';
    }
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        b[i] = x - '0';
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            ansf.push_back(i);
        }
    }
    if (a[n - 1] != b[n - 1]) ansf.push_back(n);
    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            ansb.push_back(i);
        }
    }
    reverse(ansb.begin(), ansb.end());
    cout << ansf.size() + ansb.size() << " ";
    for (int a : ansf)
        cout << a << " ";
    for (int a : ansb) 
        cout << a << " ";
    cout << nl;
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        solve();
} 