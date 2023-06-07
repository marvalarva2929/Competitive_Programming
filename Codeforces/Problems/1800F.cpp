#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;

int a[mxn]; // amount
int b[mxn]; // parity
            
unordered_map<int, int> cnt[26];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n; cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int bit = s[j] - 'a';
            a[i] |= (1 << bit);
            b[i] ^= (1 << bit);
        }

        for (int k = 0; k < 26; k++)
            if (!((a[i] >> k) & 1)) 
                    cnt[k][b[i]]++;
    }
       
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++)
            if (!((a[i] >> j) & 1)) 
                ans += cnt[j][((b[i] ^ ((1 << 26) - 1)) - (1 << j))];
    }
 
    cout << ans/2 << nl;
}


