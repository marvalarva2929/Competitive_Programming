#include <bits/stdc++.h>
#define int long long
#define nl endl
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 1e3;
int a[mxn];

char one(int x) {
    cout << '?' << " " << 1 << " " << x + 1 << endl;
    char ans; cin >> ans;
    return ans;
}

int two(int l, int r) {
    cout << '?' << " " << 2 << " " << l + 1 << " " << r + 1 << endl;
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n; cin >> n;
    string s;
    
    vector<vector<int>> cnt(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        if (i == 0)
            s.push_back(one(i));
        else if (two(0, i) > cnt[i - 1][0]) {
            s.push_back(one(i));
        } else {
            unordered_map<char, int> last;
            for (int j = 0; j < i; j++)
                last[s[j]] = j;
            
            vector<int> lasts;
            for (auto& p : last)
                lasts.push_back(p.ss); 
            sort(lasts.begin(), lasts.end()); 
            
            int l = 0, r = lasts.size();

            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (two(lasts[m], i) == cnt[i - 1][lasts[m]]) l = m;
                else r = m;
            }

            s.push_back(s[lasts[l]]);
        } 
     
        set<char> q;
        for (int j = i; j >= 0; j--) {
            q.insert(s[j]);
            cnt[i][j] = q.size(); 
        }

    }
    
    cout << '!' << " " << s << endl; 
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}
