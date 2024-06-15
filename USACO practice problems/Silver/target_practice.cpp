#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int t[mxn];
string s;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    map<int, int> it;
    int n, m; cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int x; cin >> x; it[x] = i + 1;
    }
    cin >> s;
    
    set<int> in[5][2];
    int cnt[5] = {};
    
    fill(t, t + n, INT_MAX);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') cur--;
        else if (s[i] == 'R') cur++;
        else if (s[i] == 'F') 
            if (it[cur]) {
                if (!in[2][0].count(it[cur] - 1))
                    t[i] = (it[cur] - 1);
                in[2][0].insert(it[cur] - 1);
            }
    }

    for (int i = 0; i < 5; i++)
        cnt[i] = in[2][0].size(), in[i][0] = in[2][0];
    int ans = cnt[2];

    for (int i = n - 1; i >= 0; i--) {
        cur += (s[i] == 'L') - (s[i] == 'R'); 
        
        if (s[i] == 'L') {
            //F
            int c = it[cur];
            if (c) {
                c--;
                ans = max(ans, cnt[3] + (!in[3][0].count(c) && !in[3][1].count(c)));
            }
            ans = max({ans, cnt[4], cnt[3]});
        } else if (s[i] == 'R') {
            int c = it[cur];
            if (c) {
                c--;
                ans = max(ans, cnt[1] + (!in[1][0].count(c) && !in[1][1].count(c)));
            }
            ans = max({ans, cnt[0], cnt[1]});
        } else {
            ans = max({ans, cnt[1], cnt[2], cnt[3]});
            for (int j = 0; j < 5; j++) {
                int ncur = cur + j - 2;
                
                if (t[i] == it[cur] - 1) { 
                    in[j][0].erase(it[cur] - 1);
                    if (!in[j][1].count(it[cur] - 1)) cnt[j]--; 
                }

                if (it[ncur]) {
                    if (!in[j][0].count(it[ncur] - 1) && !in[j][1].count(it[ncur] - 1))
                        cnt[j]++;
                    in[j][1].insert(it[ncur] - 1);
                }
            }
        }
    }

    cout << ans << endl; 
}
