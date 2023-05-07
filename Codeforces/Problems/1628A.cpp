using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)2e5 + 10

int mexx(vector<int> a) {
    unordered_map<int, bool> check;
    for (int i : a) 
        check[i] = true;
 
    for (int i = 1; i <= a.size() + 2; i++)
        if (i && !check[i - 1]) 
            return i - 1;   
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    int mex[n] = {}; // stores the MEX from i to n (the suffix)
    for (int & i : a)
        cin >> i;

    reverse(a.begin(), a.end());
    int curr = 0;
    unordered_map<int, bool> p;
    // cout << m << nl;

    for (int i = 0; i < n; i++) {
        p[a[i]] = true;
        while (p[curr]) curr++;
        mex[n - i - 1] = curr;
    }

    int m = mex[0];
    int i = 0;

    curr = 0; p.clear();

    while (a.size()) {
        p[a.back()] = true;
        a.pop_back();
        i++;
        while (p[curr]) curr++;
        // cout << curr << ' ' << m << nl;
        if (curr == m) {
            b.push_back(curr);
            m = mex[i];
            curr = 0;
            p.clear();
        }
    }    

    cout << b.size() << nl;
    for (int i : b)
        cout << i << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}