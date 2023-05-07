using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

int q(int x) {
    cout << "- " << x << nl;
    int ret; cin >> ret;
    cout.flush();
    return ret;
}

void answer(int x) { 
    cout << "! " << x << nl;
    cout.flush();
}

void solve() {
    int init_cnt; cin >> init_cnt;
    int cur_cnt = 0;
    int cur_bit = 0;   
    int prev_n = init_cnt;
    int ans = 0;

    while (cur_cnt < init_cnt) {
        int qe = q(1 << cur_bit);
        int delta = prev_n - qe;
        prev_n = qe;
        if (delta == 1) {
            ans += (1 << cur_bit);
            cur_bit++;
        } else {
            cur_bit += abs(delta) + 1;
            ans += (1 << cur_bit);
        }
        cur_cnt++;
    }
    answer(ans);
}

signed main() {

    int t; cin >> t;
    while (t--)
        solve();
}