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


int32_t main() {
    string alpha; cin >> alpha;
    unordered_map<char, int> order;
    for (int i = 0; i < 26; i++)
        order[alpha[i]] = i;

    int ans = 0; string check; cin >> check;
    char curr = check[0];
    for (char a : check) {
        // cout << a << ": " << curr << ": " << order[a] << ": " << order[curr] << nl;
        if (order[a] <= order[curr]) ans++;
        curr = a;
    }
    cout << ans << nl;
}   