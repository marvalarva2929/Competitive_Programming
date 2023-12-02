#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5;
int a[mxn];
int n, k, l;

bool check(int h) {
    
    int s = 0;
    for (int i = 0; i < h; i++)
        if (a[i] < h) {
            int diff = h - a[i];
            if (diff > k) return false; 
            s += diff; 
        } 

    return s <= k * l;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
 
    cin >> n >> k >> l;    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    
    int lo = 0, hi = n;
    while (lo < hi) {
        int m = (lo + hi + 1) >> 1;
        if (check(m)) lo = m;
        else hi = m - 1;
    }
    
    cout << hi << endl;
}
