#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pi pair<int, int>
#define nl " \n"

using namespace std;
const int mxn = 1e5;
int a[mxn];
int n, p;

bool check(int k) {
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] - k;
    
    int d = 0;
    for (int i = 0; i < n; i++)
        if (b[i] > 0)
            d += (b[i] + p - 1) / p;
    
    return d <= k;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> p; p--;
    int l = 0, h = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], h += (a[i] + p - 1) / p;
    
    while (l < h) {
        int m = ((l + h)>>1);
        if (check(m)) h = m;
        else l = m + 1;
    }
        
    cout << l << nl;
}
