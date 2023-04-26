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

#define MAX (int)1e5 + 10
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
int is[MAX];
int sb[MAX];

bool equal(int n) {
    for (int i = 0; i < n; i++)
        if (is[i] != sb[i])
            return false;

    return true;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sb[i];
    for (int i = 0; i < n; i++)
        cin >> is[i];

    int ans = 0;
    
    while (!equal(n)) {
        for (int i = 0; i < n; i++) {
            vector<int> lower;
            int delta = INT_MAX;
            while (i < n && sb[i] > is[i]) {
                lower.push_back(i);
                delta = min(delta, sb[i] - is[i]);
                i++;
            }
            if (delta != INT_MAX) ans += delta;
            for (int ind : lower)
                is[ind] += delta;
            
            // cout << delta << nl;
        }
        // print(is, 0, n - 1);
        for (int i = 0; i < n; i++) {
            vector<int> higher;
            int delta = INT_MAX;
            while (i < n && sb[i] < is[i]) {
                higher.push_back(i);
                delta = min(delta, is[i] - sb[i]);
                i++;
            }
            if (delta != INT_MAX) ans += delta;
            for (int ind : higher)
                is[ind] -= delta;

            // cout << delta << nl;
        }
        // print(is, 0, n - 1);
    }
    cout << ans << nl;
} 