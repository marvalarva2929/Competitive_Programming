using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i].first << ", " << x[i].second << " ";} cout << nl;
#define MAX (int)1e5 + 10
int cn[10]; 
vector<int> ans;

int32_t main() {
    int n;
    cin >> n;
    int firstd = 1;
    int leftover;
    for (int i = 1; i <= 9; i++) {
        int c; cin >> c;
        cn[i] = c;
        leftover = n % cn[firstd];
        if (n / c > n / cn[firstd])     
            firstd = i;
        else if (n /c == n/ cn[firstd] && leftover <= n % cn[i]) {
            firstd = i;
        }
    }
    if (n/cn[firstd] == 0) {
        cout << -1 << nl;
        return 0;
    }
    vector<int> ans(n/cn[firstd], firstd);
    n = leftover;
    // cout << n << nl;
    int c = cn[firstd];
    for (int & num : cn)
        num -= c;


    bool changed = true;
    while (n > 0 && changed) {
        changed = false;
        for (int i = 0; i < ans.size(); i++) {
            if (n == 0) break;
            for (int j = 9; j >= 1; j--) {
                if (cn[j] <= n && j > ans[i]) {
                    ans[i] = j;
                    n -= cn[j];
                    changed = true;
                    break;
                }
            }
        }
    }
    for (int dig : ans)
        cout << dig;

    cout << nl;

} 