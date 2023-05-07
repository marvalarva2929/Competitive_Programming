using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)32000
bool isComp[MAX];
vector<int> primes;

void solve() {
    int n; cin >> n;
    int a[n] = {};
    
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> c;
    bool fl = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j : primes) {
            if (x % j == 0) {
                if (c.find(j) != c.end()) {
                    fl = true;
                    break;
                }
                c.insert(j);
                while ((x % j) == 0) x /= j;
            }
        }
        
            if (fl) break;
            if (x != 1) {
                if (c.find(x) != c.end()) fl = true;
                else c.insert(x);
            }
            if (fl) break;
    }
  
    cout << (fl ? "YES" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    primes.push_back(2);
    for (int i = 4; i < MAX; i += 2)
        isComp[i] = true;

    for (int i = 3; i < MAX; i += 2) 
        if (!isComp[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAX; j += i)
                isComp[j] = true;
        }

    int t; cin >> t;
    while (t--)
        solve();
}