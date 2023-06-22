#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve(int t) {
    int n, d12, d23, d13; cin >> n >> d12 >> d23 >> d13;
    set<pi> ans;
    stringstream check;

    if (d23 > d12 + d13 || (((d12 + d13) - d23) % 2) || (d12 + d13 + 1 - ((d12 + d13 - d23) / 2)  > n)) {
        cout << "NO" << nl;
        return;
    }
   
    set<int> rem;
    for (int i = 4; i <= n; i++)
        rem.insert(i);
    
    int tail = ((d12 + d13 - d23) / 2);
    if (tail > d12 || tail > d13) {
        cout << "NO" << nl;
        return;
    }

    int prv = 1;
    auto nex = rem.begin();
    for (int i = 0; i < tail - 1; i++)
        ans.insert({prv, *nex}),
        prv = *nex,
        nex++;
    
    if (tail == d12) ans.insert({prv, 2}), prv = 2;
    else if (tail == d13) ans.insert({prv, 3}), prv = 3;
    else if (tail) ans.insert({prv, *nex}), prv = *nex, nex++;
    
    int two = d12 - tail;
    int prv2 = prv;
    for (int i = 0; i < two - 1; i++) 
        ans.insert({prv2, *nex}),
        prv2 = *nex,
        nex++;
    if (two) ans.insert({prv2, 2});

    int three = d13 - tail;
    int prv3 = prv;
    for (int i = 0; i < three - 1; i++)
        ans.insert({prv3, *nex}),
        prv3 = *nex,
        nex++;
    if (three) ans.insert({prv3, 3});

    prv = 1;
    while (nex != rem.end()) {
        ans.insert({prv, *nex});
        nex++;
    }

    cout << "YES" << nl;
    for (pi edge : ans)
        cout << edge.ff << " " << edge.ss << nl;
}

signed main() {
    cin.tie()->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
