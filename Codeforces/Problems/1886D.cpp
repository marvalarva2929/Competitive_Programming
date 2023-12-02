#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int MOD = 998244353;
const int mxn = 3e5;
int fact[mxn+1];
bool a[mxn];
int ts[mxn];

int power(int a, int b) {
    int ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans % MOD;
}

int inv(int x) { return power(x, MOD - 2); }

int perm(int n, int k) { //cout << n << " " << k << nl; 
                         return fact[n] * inv(fact[n - k]) % MOD; }

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i < n; i++) {
        char c; cin >> c;
        a[i] = (c == '?');
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = i * fact[i - 1] % MOD;
    

    int ogans = 1;
    int cnt = 0, cur = n - 2;
    set<int> brks;

    brks.insert(0);
    brks.insert(n);
    
    vector<pi> ops; 

    if (a[1]) { ops.emplace_back(1, 1), a[1] = 0; }
    else { ops.emplace_back(1, a[1]); }

    for (int i = n - 1; i > 0; i--)
        if (!a[i]) ogans = ogans * perm(cur, cnt) % MOD,
                    ts[i] = cur,
                    cur -= cnt + 1, 
                    cnt = 0, 
                    brks.insert(i);
        else cnt++;
    
    for (int i = 0; i < m; i++) {
        int id; char c; cin >> id >> c;
        ops.emplace_back(id, (c == '?'));
    }
    
    bool no = false;

    for (auto [id, t] : ops) {
        int ans = ogans;

        if (a[id] == t) { goto skip; }

  
        if (a[id]) {
            if (id == 1 && no) { no = false; a[1] = 0; goto skip; }
            
            auto it = brks.lower_bound(id);
            int af = *it; --it;
            int bef = *it;
            
            //cout << bef << " " << af << nl;     
        
            ans = ans * inv(perm(ts[bef], af - bef - 1)) % MOD 
                        * perm(ts[bef], af - id - 1) % MOD 
                        * perm(ts[bef] - (af - id - 1) - 1, id - bef - 1) % MOD;
            
            ts[id] = ts[bef];
            ts[bef] -= af - id;
 
            brks.insert(id);
            a[id] = 0;
        } else {
            if (id == 1) { no = true; cout << 0 << nl; a[1] = 1; continue; }
           
            int af = *(++brks.find(id)),
                bef = *(--brks.find(id));
 
            ans = ans * inv(perm(ts[id], af - id - 1)) % MOD
                    * inv(perm(ts[bef], id - bef - 1)) % MOD
                    * perm(ts[id], af - bef - 1) % MOD;
            
            ts[bef] = ts[id];
            ts[id] = 0;
            brks.erase(id);
            a[id] = 1;
        }
   
skip:
        cout << (no ? 0 : ans) << nl;
        ogans = ans;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1; 
    while (t--)
        solve();
}
