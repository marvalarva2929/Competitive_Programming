using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define vi vector<long long>
#define MAX (int)2e5 + 10
int a[MAX];

int ans = 0;

vi numOfInversions(int l, int h, int n) {
    if (n == 1) 
        return { a[l] };
    int m = (l + h)/2;
    vi left = numOfInversions(l, m, n/2);
    vi right = numOfInversions(m, h, n - n/2);   

    vi out(n);
    int i = 0, j = 0, k = 0;
    for (int q = 0; q < n; q++) 
        if (i < left.size() && (j >= right.size() || left[i] < right[j]))
            out[k++] = left[i++];
        else if (j < right.size() && (i >= left.size() || left[i] >= right[j]))
            out[k++] = right[j++], ans += max((int)0, (int)left.size() - i);
    
    return out;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ans = 0;
    numOfInversions(0, n, n);
    // for (int i : out)
    //     cout << i << " ";
    // cout << nl;
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}