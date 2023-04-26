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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;
#define MAX (int)5e5 + 10
char a[MAX];
int g[MAX];
int h[MAX];

int32_t main() {
    int n;
    cin >> n;  
    int ans = 0;
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int l = 0, r = 0;
        if (i > 0 && a[i - 1] != a[i]) {
            l++;
            for (int j = i - 2; j >= 0 && a[j] != a[i]; j--) l++;
        }
        if (i < n - 1 && a[i + 1] != a[i]) {
            r++;
            for (int j = i + 2; j < n && a[j] != a[i]; j++) r++;
        }

        ans += (l * r);
        if (l)
            ans += l - 1;
        if (r)
            ans += r - 1;
    }

    cout << ans << nl;
} 