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


int32_t main() {
    int ans = 0;
    for (int i = 0; i < (1 << 6); i++)
        ans += __builtin_popcount(i);

    cout << ans << nl;
}
