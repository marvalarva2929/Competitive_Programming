#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

void solve() {
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    while (true) {
        cout << n << " ";
        if (n == 1) break; 
        if (n % 2) n = (n * 3) + 1;
        else n /= 2;
    }
    cout << nl;
}
