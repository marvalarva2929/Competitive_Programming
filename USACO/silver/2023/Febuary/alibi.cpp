using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define pii pair<pi, int>
#define f first
#define s second
#define x f.f
#define y f.s

const int mxn = 1e5 + 10;

pii gr[mxn];
pii a[mxn];

int dist(pi xy1, pi xy2) {
    return ((xy1.f - xy2.f) * (xy1.f - xy2.f)) + ((xy1.s - xy2.s) * (xy1.s - xy2.s));
}

bool canReach(pii cow, pii garden) {
    return dist(cow.f, garden.f) <= (cow.s - garden.s) * (cow.s - garden.s);
} 

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int g, n; cin >> g >> n;
    for (int i = 0; i < g; i++) 
        cin >> gr[i].x >> gr[i].y >> gr[i].s;
    
    for (int i = 0; i < n; i++) 
        cin >> a[i].x >> a[i].y >> a[i].s;

    auto cmp = [](const pii a, const pii b) -> bool {
        return a.s < b.s;
    };
    sort(gr, gr + g, cmp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int lb = lower_bound(gr, gr + g, a[i], cmp) - gr;
        int isguilty = true;
        // cout << i << " : " << lb << nl;
        if (lb > 0)
            isguilty &= canReach(a[i], gr[lb - 1]);
        // cout << isguilty << " ";
        if (lb < g)
            isguilty &= canReach(a[i], gr[lb]);
        // cout << isguilty << " ";
        // cout << nl;
        ans += !isguilty;
    }
    cout << ans << nl;
}