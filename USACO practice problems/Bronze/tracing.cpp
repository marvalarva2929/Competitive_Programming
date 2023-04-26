using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>

bool isInf[101];
pi ev[251];

bool works(int init_cow, int k) {
    bool inf[101] = {false};
    int inter[101] = {};
    inf[init_cow] = true;

    for (int i = 0; i <= 250; i++) {
        if (ev[i].first) {
            if (inf[ev[i].first]) inter[ev[i].first]++;
            if (inf[ev[i].second]) inter[ev[i].second]++;   

            if (inter[ev[i].first] <= k && inf[ev[i].first]) inf[ev[i].second] = true;
            if (inter[ev[i].second] <= k && inf[ev[i].second]) inf[ev[i].first] = true;
        }
    }
    int ans = 1;
    for (int i = 0; i <= 100; i++)
        ans &= inf[i] == isInf[i];
    return ans;
}

signed main() {
    ifstream cin("tracing.in");
    ofstream cout("tracing.out");

    int n, t; cin >> n >> t;
    for (int i = 0; i < n; i++)
        { char c; cin >> c; isInf[i + 1] = (c & 1); }

    for (int i = 0; i < t; i++) {
        int tt, x, y; cin >> tt >> x >> y;
        ev[tt] = {x, y};
    }

    set<int> possibleCows;
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 1; i <= n; i++) 
        for (int k = 0; k <= 250; k++)
            if (works(i, k))
                mx = max(mx, k), mn = min(mn, k), possibleCows.insert(i);


    cout << possibleCows.size() << " " << mn << " ";
    if (mx == 250)
        cout << "Infinity";
    else cout << mx;
    cout << nl;

    return 0;

}