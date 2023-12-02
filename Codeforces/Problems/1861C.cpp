#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve(int t) {
    string s; cin >> s;
    
    //if (t == 731) {
    //    cout << s << nl;
    //} 

    unordered_map<int, int> map;
    int cnt0 = 0, cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        map[0] = map[1] = 1; 
        if (s[i] == '1') {
            if (cnt0) {
                cout << "NO" << nl;
                return;
            }
            map[cnt] = 1;
        } else if (s[i] == '0') {
            if (map[cnt] == 1) {
                cout << "NO" << nl;
                return;
            }
            if (map[cnt] != -1) cnt0++; 
            map[cnt] = -1;
        } else if (s[i] == '-') {
            if (map[cnt] == -1) cnt0--;
            else if (map[cnt] == 1) map[cnt - 1] = 1;
            map[cnt--] = 0;
        } else cnt++;
    }
    
    cout << "YES" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
