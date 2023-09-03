#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    int n; cin >> n;

    int t = 2; 
    while (n % t == 0) t++;
    
    string s;
    char a = 'a';
    
    for (int i = 0; i < t; i++)
        s += (char)(a++);

    for (int i = 0; i < n; i++) 
        cout << s[(int)i % t];
    cout << endl;
}

signed main() {
    cin.tie()->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();
}
