#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int x; cin >> x;

    for (int i = 0; i <= 100; i++) {
        int y = i;
    
        string s = to_string((x + y) * (x + y)) + to_string((x + y) * (x + y) * (x + y));
        
        bool k = s.length() == 10;
        for (int j = 0; j <= 9; j++)
            k &= s.find(((char)(j + '0'))) != string::npos;
    
        if (k) {
            cout << y << nl;
            return 0;
        }
    }
}
