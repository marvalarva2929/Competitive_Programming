using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    string s; cin >> s;
    int a[s.size() + 1] = {};
    for (int i = 0; i < s.size(); i++)
        a[i + 1] = a[i] + (s[i] & 1);

    int n = s.size();

    // for (int i : a)
    //     cout << i << " ";
    // cout << nl;
    
    // Number of ones removed : a[n] - (a[j] - a[i]) Where i and j are the beginning and endpoints of a subarray respectively
    // Number of zeros : (j - i) - (a[j] - a[i])
    // When trying to find the max, the constant term -(a[j] - a[i]) can be ignored
    // Thus, the number of ones is greater iff a[n - 1] > (j - i), and vice-versa
    // If (j < a[n]), the maximum will always be at (i == 0) because we are subtracting from j. Thus, the answer if j < a[n] is always a[n] - a[j]
    // if (j > a[n]), the maximum could either be when (i == (j - a[n])), since this will make them equal and any larger value of i will result in the first option winning, or the min value from i = 1 -> j - a[n]
    // The term (j - i) - (a[j] - a[i]) can be rearranged to j - a[j] - (i - a[i]). As shown, the only changing term is (i - a[i]).  And when i = j - a[j], the two cases are equal

    int ans = INT_MAX;
    for (int j = 1; j <= n; j++)
        if (j > a[n])
            ans = min(ans, (j - a[j]) - ((j - a[n]) - a[j - a[n]]));
        else    
            ans = min(ans, a[n] - a[j]);

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}