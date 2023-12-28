#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxa = 26;

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(mxa);
    
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        cnt[c - 'a']++;
    }
    
    if ((n - k) % 2) {
        for (int i = 0; i < 26; i++) {
            int nd = 0;
            if (cnt[i]) {
                if (!(cnt[i] % 2)) nd++;
                for (int j = 0; j < 26; j++)
                    if (j != i)
                        if (cnt[j] % 2) nd++;
                
                if (nd > k) continue;
                if ((k - nd) % 2 == 0) return true;
            }
        }

    } else {
        int nd = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] % 2) nd++;
        
        if (nd > k) return 0;
        return !((k - nd) % 2); 
    }
    return false;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << nl;
}
