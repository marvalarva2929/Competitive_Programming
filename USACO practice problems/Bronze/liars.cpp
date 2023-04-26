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


int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vd;
    for (int i = 0; i < n; i++) {
        char a;
        int x;
        cin >> a >> x;
        if (a == 'L') vd.push_back({x, 0});
        else vd.push_back({x, 1});
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int newAns = 0;
        auto truthteller = vd[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                auto checker = vd[j];
                if (checker.s == 0) {
                    if ((truthteller.f > checker.f)) newAns++;
                } else {
                    if ((truthteller.f < checker.f)) newAns++;
                }
            }
        }
        ans = min(ans, newAns);
    }
    cout << ans << nl;
} 