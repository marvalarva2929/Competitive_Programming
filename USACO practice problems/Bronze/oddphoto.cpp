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
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)1e4
int c[MAX];

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
        if (c[i] % 2 == 1)
            odd++;
        else even++;


    while (even - odd > 1 || even - odd < 0) {
    // cout << odd << ": " << even << nl;

        if (odd < even - 1) {
            int ans = 0;
            while (even != odd + 1)
                even--;
        }

        if (odd > even + 1) {
            while (odd > even) {
                odd -= 2;
                even++;
            }
        }
        if (odd >= even - 1 && odd <= even + 1) { 
            cout << odd + even << nl;
            return 0;
        }
    }

} 