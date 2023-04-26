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
#define MAX (int)2e5 + 10

auto comp = [](string p, string t) {
    char curr = t[0];
    int j = 0;
    for (int i = 0; i < p.size() && j < t.size(); i++) 
        if (p[i] == curr) 
            curr = t[++j];
    return (j == t.size());
};


int32_t main() {
    string p, t;
    cin >> p >> t;

    int n = p.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++)
        cin >> order[i];
    

    int lo = 0, hi = n, mid= (lo + hi) /2;
    while (lo < hi) {
        string check = p;
        for (int i = 0; i <= mid; i++)
            check[order[i] - 1] = ' ';
        // cout << lo << " : " << hi << " : " << mid << " : " << a[mid + 1] << " : " << t << " : " << comp(a[mid + 1], t) << nl;
        if (comp(check, t)) 
            lo = mid + 1;
        else 
            hi = mid;
        mid = (hi + lo)/2;
    }
    cout << lo << nl;

} 