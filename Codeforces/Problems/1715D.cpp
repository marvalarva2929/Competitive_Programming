#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];
vector<pi> adj[mxn];

bool getbit(int x, int n) {
    return (x >> n) & 1;
}

void setbit(int& x, int n) {
    x |= (1 << n);
}

void rembit(int& x, int n) {
    x ^= (1 << n);
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q; cin >> n >> q;
    
    for (int i = 0; i < q; i++) {
        int ii, jj, x; cin >> ii >> jj >> x; --ii, --jj;

        adj[ii].emplace_back(jj, x);
        adj[jj].emplace_back(ii, x);
    }

    fill(a, a + n, (int)(1 << 30) - 1);
    
    for (int bit = 0; bit < 30; bit++) {
        for (int i = 0; i < n; i++)
            for (pi& p : adj[i]) 
                if (!getbit(p.ss, bit)) {
                    rembit(a[i], bit);
                    break;
                }
        
        for (int i = 0; i < n; i++) {
            if (!getbit(a[i], bit)) continue;
            rembit(a[i], bit);
           
            for (pi& p : adj[i]) {
                if (getbit(p.ss, bit) && !getbit(a[p.ff], bit)) {
                    setbit(a[i], bit);
                    break; 
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        cout << a[i] << nl[i == n - 1];
}
