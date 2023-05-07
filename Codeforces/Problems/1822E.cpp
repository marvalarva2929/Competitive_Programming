#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 2e5;

int a[mxn];
int lo[26];
int cnt[26];


void solve() {

    fill(lo, lo + 26, 0);
    fill(cnt, cnt + 26, 0);

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c - 'a';
        cnt[a[i]]++;
    }


    if (n % 2 || (*max_element(cnt, cnt + 26) > (n/2))) { // if n is odd, the middle number will always be a palindrome
        cout << -1 << nl;
        return;
    }

    for (int i = 0; i < n/2; i++) 
        if (a[i] == a[n - 1 - i]) 
            lo[a[i]]++;

    
    int m = 0, k = 0;
    for (int i = 0; i < 26; i++)
        k += lo[i],
        m = max(m, lo[i]);

    cout << max(m, (int)ceil(k/2.0)) << nl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t --> 0)
        solve();
}