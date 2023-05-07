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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)100 + 10
int c[MAX];
vector<int> p;

// didn't solve in contest

void solve() {
    int n; cin >> n;
    int a[n] = {};
    int odd = 0, even = 0;
    unordered_map<int, bool> seen;
    bool nooo = false;
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        if (a[i]&1)
            odd++;
        else 
            even++;

        if (seen[a[i]])
            nooo = true;
        else 
            seen[a[i]] = true;
    }

    if (nooo) {
        cout << "NO" << nl;
        return;
    }


    for (int prime : p) {
        int cnt[MAX] = {};

        for (int i = 0; i < n; i++) 
            cnt[a[i] % prime]++;

        if (*min_element(cnt, cnt + prime) > 1) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 2; i <= MAX/2; i++) {
        if (!c[i]) {
            p.push_back(i);
            for (int j = i; j <= MAX/2; j += i)
                c[j] = true;
        }
    }


    int t; cin >> t;
    while (t--)
        solve();
} 