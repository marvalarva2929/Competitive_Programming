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
#define sz(x) (int)(x.size())
#define all(x) begin(x), end(x)


int32_t main() {
    int n;
    cin >> n;
    vector<string> ans = {
        "c","o","d","e","f","o","r","c","e","s",
    };
    map<int, string> c = {
        {0, "c"},
        {1, "o"},
        {2, "d"},
        {3, "e"},
        {4, "f"},
        {5, "o"},
        {6, "r"},
        {7, "c"},
        {8, "e"},
        {9, "s"},
    };
    int k = 1;
    int total = sz(ans[0]) * sz(ans[1]) * sz(ans[2]) * sz(ans[3]) * sz(ans[4]) * sz(ans[5]) * sz(ans[6]) * sz(ans[7]) * sz(ans[8]) * sz(ans[9]);
    for (int i = 0; total < n; i++, total =  sz(ans[0]) * sz(ans[1]) * sz(ans[2]) * sz(ans[3]) * sz(ans[4]) * sz(ans[5]) * sz(ans[6]) * sz(ans[7]) * sz(ans[8]) * sz(ans[9])) {
        ans[i % 10] += c[i % 10];
    }

    for (int i = 0; i < 10; i++) cout << ans[i];
    cout << nl;
} 