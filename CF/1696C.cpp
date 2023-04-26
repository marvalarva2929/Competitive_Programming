using namespace std;
#include <bits/stdc++.h>
#define f first
#define s second
#define int long long
#define pi pair<long long, long long>
#define vpi vector<pi>
#define vi vector<long long>
#define nl '\n'
int m;

int smallestFactor(int a) {
    while (!(a % m)) a /= m;
    return a;
}

void combine(vpi& a) {
    vector<pair<int, int>> splitted;
    int i = 0;
    while (i < a.size()) {
        int j = i, tot = 0;
        while (j < a.size() && a[i].f == a[j].f) tot += a[j].s, j++;
        int s = smallestFactor(a[i].f);
        splitted.push_back({s, tot * (a[i].f/s)});
        i = j;
    }
    a = splitted;   
}

bool equals(vpi a, vpi b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i].f != b[i].f || a[i].s != b[i].s)
            return false;
    return true;
}

void solve() {
    int n; cin >> n >> m;
    vpi a, b;
    vi ina, inb;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; ina.push_back(x);
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x; inb.push_back(x);
    }

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && ina[j] == ina[i]) j++;
        int s = smallestFactor(ina[i]);
        a.push_back({s, (j - i) * (ina[i]/s)});
        i = j;
    }

    i = 0;
    while (i < k) {
        int j = i;
        while (j < k && inb[j] == inb[i]) j++;
        int s = smallestFactor(inb[i]);
        b.push_back({s, (j - i) * (inb[i]/s)});
        i = j;
    }

    combine(a); combine(b); 
    cout << (equals(a, b) ? "YES" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}