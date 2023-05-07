using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)pow(2, 18)

signed main() {
    int n; string s; cin >> n >> s;
    int x = 0, y = 0;
    for (char a : s)
        x += a&1, y += !(a&1);

    for (int i = pow(2, x); i <= (pow(2, n) - pow(2, y) + 1); i++)
        cout << i << " ";
    cout << nl;
            
}